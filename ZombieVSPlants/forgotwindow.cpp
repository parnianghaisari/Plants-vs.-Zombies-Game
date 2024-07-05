#include "forgotwindow.h"
#include "ui_forgotwindow.h"

ForgotWindow::ForgotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForgotWindow)
{
    ui->setupUi(this);
     this->setStyleSheet("ForgotWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");
}

ForgotWindow::~ForgotWindow()
{
    delete ui;
}

void ForgotWindow::on_pushButton_clicked()
{
     QByteArray data="f2";
     clientS->write(data);
    QByteArray data1 = ui->phone->text().toUtf8()+ "\n";
    clientS->write(data1);
    QByteArray data2 = ui->pass->text().toUtf8()+ "\n";
    clientS->write(data2);
}

