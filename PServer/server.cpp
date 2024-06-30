#include "server.h"
#include <QDebug>

Server::Server(QObject *parent)
    : QTcpServer(parent) {
    QHostAddress localAddress(getWifiIPv4Address());
        if (this->listen(localAddress, 2025)) {
            qDebug() << "Server started on" << localAddress.toString();
        } else {
            qDebug() << "Server could not start!";
        }
}

void Server::incomingConnection(qintptr socketDescriptor) {
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

QString Server::getWifiIPv4Address()
{
    QString wifiIPv4;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (const QNetworkInterface& iface, interfaces) {
        if (iface.flags().testFlag(QNetworkInterface::IsUp) &&
            iface.flags().testFlag(QNetworkInterface::IsRunning) &&
            iface.flags().testFlag(QNetworkInterface::IsLoopBack) == false) {

            QList<QNetworkAddressEntry> entries = iface.addressEntries();
            foreach (const QNetworkAddressEntry& entry, entries) {
                if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    wifiIPv4 = entry.ip().toString();
                    if (iface.humanReadableName().contains("wlan", Qt::CaseInsensitive) ||
                        iface.humanReadableName().contains("wi-fi", Qt::CaseInsensitive) ||
                        iface.humanReadableName().contains("wireless", Qt::CaseInsensitive)) {
                        return wifiIPv4;
                    }
                }
            }
        }
    }
    return QString();
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

    clients.removeAll(socket);
    emit clientDisconnected(socket->peerAddress().toString());
    socket->deleteLater();
    qDebug() << "Client disconnected";;
}

void Server::broadcastMessage(const QByteArray &message, QTcpSocket *excludeSocket) {
    for (QTcpSocket *client : clients) {
            if (client != excludeSocket) {
                client->write(message);
            }
        }
}
