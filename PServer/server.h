#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMutex>
#include <QList>

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

private slots:
    void readClient();
    void handleClientDisconnected();

private:
    QList<QTcpSocket*> clients;
    QMutex mutex;
    void broadcastMessage(const QByteArray &message, QTcpSocket *excludeSocket = nullptr);
};

#endif // SERVER_H
