#ifndef SECONDSTRART_H
#define SECONDSTRART_H

#include <QMainWindow>
#include "datahandeler.h"
#include "globals.h"
#include "gamehistory.h"
#include"setting.h"
#include "zambiesgame.h"
#include "plants.h"
#include "globals.h"

namespace Ui {
class SecondStrart;
}

class SecondStrart : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondStrart(QWidget *parent = nullptr);
    ~SecondStrart();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void listenServer();
private:
    Ui::SecondStrart *ui;
    DataHandler *dataHandler;
    QTcpSocket *clients;
};

#endif // SECONDSTRART_H
