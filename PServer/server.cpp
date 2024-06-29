#include "server.h"
#include <QDebug>

Server::Server(QObject *parent)
    : QTcpServer(parent) {
    if (this->listen(QHostAddress::Any, 2025)) {
        qDebug() << "Server started";
    } else {
        qDebug() << "Server could not start!";
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    QMutexLocker locker(&mutex);
    if (clients.size() >= 2) {
        qDebug() << "Connection attempt rejected: maximum client limit reached";
        QTcpSocket tempSocket;
        tempSocket.setSocketDescriptor(socketDescriptor);
        tempSocket.disconnectFromHost();
        return;
    }

    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    clients.append(socket);

    connect(socket, &QTcpSocket::readyRead, this, &Server::readClient);
    connect(socket, &QTcpSocket::disconnected, this, &Server::handleClientDisconnected);

    emit clientConnected(socket->peerAddress().toString());
    qDebug() << "Client connected from" << socket->peerAddress().toString();
}

void Server::readClient() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "Received data from client:" << message;

    emit messageReceived(message);
    broadcastMessage(data, socket);
}

void Server::handleClientDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QMutexLocker locker(&mutex);
    clients.removeOne(socket);
    emit clientDisconnected(socket->peerAddress().toString());
    socket->deleteLater();
    qDebug() << "Client disconnected";
}

void Server::broadcastMessage(const QByteArray &message, QTcpSocket *excludeSocket) {
    QMutexLocker locker(&mutex);
    for (QTcpSocket *client : clients) {
        if (client != excludeSocket) {
            client->write(message);
        }
    }
}
