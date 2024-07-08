// DataHandler.cpp
#include "datahandeler.h"
#include "globals.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    // Assuming clientS is initialized elsewhere
    // Example: clientS = new QTcpSocket(this);
    connect(clientS, &QTcpSocket::readyRead, this, &DataHandler::readData);
}

void DataHandler::readData()
{
    QByteArray data = clientS->readAll();
    emit dataReceived(data);
    // Additional processing of data if needed
}
