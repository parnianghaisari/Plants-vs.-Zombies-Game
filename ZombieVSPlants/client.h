#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>

#include "globals.h"

class Client : public QObject {
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);

    void connectToServer(const QString &host, quint16 port);
    void sendMessageToServer(const QString &message);

private slots:
    void onReadyRead();
};

#endif // CLIENT_H
