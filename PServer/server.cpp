#include "server.h"
#include <QDebug>
#include <QStringList>

int flagForStarting = 0;
int numForGame1 = -1;
int numForGame2 = -1;

QString user_1 = "";
QString user_2 = "";

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
    if (clients.size() >= 6) {
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
    QTcpSocket *client = clients.value(id, nullptr);
    if (client) {
        client->write(message.toUtf8());
    }
}

void Server::readClient() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    int socketDescriptor = socket->socketDescriptor();
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    QString str(data);
    QStringList usAndps = str.split('+');
    for (int i = 0; i < usAndps.size(); ++i)
        qDebug() << "Received data from client :" << usAndps[i];
    if (usAndps[0] == 'l')
    {
        Login log;
        QString res = log.matchPSW(usAndps[1], usAndps[2]);
        if (res == "1")
        {
            if (user_1 == "")
                user_1 = usAndps[1];
            else
                user_2 = usAndps[1];
        }
        qDebug() << res;
        sendMessageToClients(res, socketDescriptor);
    }
    else if (usAndps[0] == 't')
    {
        QString data;
        QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
        JsonManager load(filep);
        load.loadData();
        for (int i = 0; i < load.getUsers().size(); ++i)
            if (usAndps[1] == load.getUsers()[i].userVal())
            {
                data = load.getUsers()[i].nameVal() + '+' + load.getUsers()[i].userVal() + '+' + load.getUsers()[i].pswVal() + '+' + load.getUsers()[i].numberVal() + '+' + load.getUsers()[i].emailVal();
                break;
            }
        sendMessageToClients(data, socketDescriptor);
    }
    else if (usAndps[0] == "t2")
    {
        QString filep = "D:\\AP\\AP_project\\PServer\\SignUpInformation.json";
        JsonManager load(filep);
        load.loadData();
        for (int i = 0; i < load.getUsers().size(); ++i)
            if (usAndps[1] == load.getUsers()[i].userVal())
            {
                load.getUsers()[i].nameVal() = usAndps[2];
                load.getUsers()[i].userVal() = usAndps[3];
                load.getUsers()[i].pswVal() = usAndps[4];
                load.getUsers()[i].numberVal() = usAndps[5];
                load.getUsers()[i].emailVal() = usAndps[6];
                break;
            }
        load.saveData();
    }
    else if (usAndps[0] == 'f')
    {
        Login log;
        QString res = log.matchPN(usAndps[1], usAndps[2]);
        sendMessageToClients(res, socketDescriptor);
    }
    else if (usAndps[0] == 's')
    {
        qDebug() << usAndps[5];
        SignUp sig;
        Users user(usAndps[1], usAndps[2], usAndps[3], usAndps[4], usAndps[5]);
        qDebug() << usAndps[1];
        sig.sign(user);
    }
    else if (usAndps[0] == 'n')
    {
        Login log;
        log.changePSW(usAndps[1], usAndps[2]);
    }
    else if (usAndps[0] == 'i')
    {
        JsonManager manage(usAndps[1], 0);
        manage.loadHistoryData();
        QString his = "";
        for (int i = 0; i < manage.getHistory().size(); ++i)
        {
            his += '+';
            his += manage.getHistory()[i].historyToString();
        }
        sendMessageToClients(his, socketDescriptor);
    }
    else if (usAndps[0] == 'z' || usAndps[0] == 'p')
    {
        auto it = clients.begin();
        sendMessageToClients(str, it.key());
        it++;
        sendMessageToClients(str, it.key());
        ++it;
        sendMessageToClients(str, it.key());
        ++it;
        sendMessageToClients(str, it.key());
    }
    else if (usAndps[0] == 'h') //sposed to be commented
    {
        if (flagForStarting <= 1)
        {
            QString numberString = QString::number(flagForStarting);
            qDebug() << numberString;
            if (numForGame1 == -1)
                numForGame1 = socketDescriptor * 10;
            else
                numForGame2 = socketDescriptor * 10 + 1;
            sendMessageToClients(numberString, socketDescriptor);
            ++flagForStarting;
        }
        else
        {
            if (socketDescriptor == (numForGame1/10))
                sendMessageToClients("1", socketDescriptor);
            else
                sendMessageToClients("0", socketDescriptor);
        }
    }

    emit messageReceived(message);
    //broadcastMessage(data, socket);
}

void Server::handleClientDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    qDebug() << "Client disconnected: " << socket->socketDescriptor();
    clients.remove(socket->socketDescriptor());
    flagForStarting--;
    emit clientDisconnected(socket->peerAddress().toString());
    socket->deleteLater();
}

void Server::broadcastMessage(const QByteArray &message, QTcpSocket *excludeSocket) {
    for (QTcpSocket *client : clients) {
            if (client != excludeSocket) {
                client->write(message);
                client->flush();
            }
        }
}
