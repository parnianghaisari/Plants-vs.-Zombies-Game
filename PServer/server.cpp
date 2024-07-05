#include "server.h"
#include <QDebug>
#include <QStringList>

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
    clients.insert(socketDescriptor, socket);
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

void Server::sendMessageToClients(const QString &message, int id)
{
    QByteArray data = message.toUtf8();
    if (clients[id]->state() == QAbstractSocket::ConnectedState)
        clients[id]->write(data);
}

void Server::readClient() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    int socketDescriptor = socket->socketDescriptor();
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "Received data from client:" << message;

    QString fileP = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
    JsonManager LoginSignup(fileP);
    if (message == "l" || message == "l2")
    {
        bool Flag = false;
        LoginSignup.loadData();
        QByteArray data_ = socket->readAll();
        QString str(data_);
        QStringList usAndps = str.split('+');
        for (int i = 0; i < usAndps.size(); ++i)
            qDebug() << "Received data from client:" << usAndps[i];
        for (int i = 0; i < LoginSignup.getUsers().size(); ++i)
        {
            if (usAndps[0] == LoginSignup.getUsers()[i].userVal())
            {
                if (usAndps[1] == LoginSignup.getUsers()[i].pswVal())
                {
                    Flag = true;
                    break;
                }
                break;
            }
        }
        if (Flag == false)
            sendMessageToClients("f", socketDescriptor);
    }

    emit messageReceived(message);
    broadcastMessage(data, socket);
}

void Server::handleClientDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    int socketDescriptor = socket->socketDescriptor();
    clients.remove(socketDescriptor);
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
