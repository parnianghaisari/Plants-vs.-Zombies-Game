#include "startwindow.h"
#include "ui_startwindow.h"
#include "client.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
  , client(new Client(this))
{
    ui->setupUi(this);
     this->setStyleSheet("StartWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    QByteArray data="i";
    clientS->write(data);
    QByteArray lisend = clientS->readAll();
    this->hide();
    QString receiveString = QString::fromUtf8(lisend);
    gameHistory *w   = new gameHistory();
    w->show();
    w->setTextInTextEdit(receiveString);
}


void StartWindow::on_pushButton_2_clicked()
{
    this->hide();
    setting *u=new setting();
    u->show();
}


void StartWindow::on_pushButton_3_clicked()
{

}

