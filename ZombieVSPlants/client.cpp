#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent) {
    connect(clientS, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::connectToServer(const QString &host, quint16 port) {
    clientS->connectToHost(host, port);
}

void Client::sendMessageToServer(const QString &message) {
    if (clientS->state() == QTcpSocket::ConnectedState) {
        clientS->write(message.toUtf8());
    } else {
        qWarning() << "Not connected to server!";
    }
}

void Client::onReadyRead() {
    QByteArray data = clientS->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "Received message from server:" << message;
    // Handle the received message as needed
}
