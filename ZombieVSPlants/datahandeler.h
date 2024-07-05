// DataHandler.h
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QTcpSocket>

class DataHandler : public QObject
{
    Q_OBJECT

public:
    explicit DataHandler(QObject *parent = nullptr);

signals:
    void dataReceived(const QByteArray &data);

public slots:
    void readData();
};

#endif // DATAHANDLER_H

