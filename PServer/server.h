#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMutex>
#include <QString>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QHash>
#include <QRandomGenerator>

#include "signup.h"

extern int flagForStarting;
extern int numForGame1;
extern int numForGame2;
extern QString user_1;
extern QString user_2;


class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
signals:
    void clientConnected(const QString &address);
    void clientDisconnected(const QString &address);
    void messageReceived(const QString &message);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public slots:
    QString getWifiIPv4Address();
    void sendMessageToClients(const QString &message, int id);

private slots:
    void readClient();
    void handleClientDisconnected();

private:
    QHash<int, QTcpSocket*> clients;
    void broadcastMessage(const QByteArray &message, QTcpSocket *excludeSocket = nullptr);
};

#endif // SERVER_H
