#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "forgotwindow.h"
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("LoginWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");
   ui->password->setEchoMode(QLineEdit::Password); // hide password
   ui->password->setMaxLength(8); // only 8 charachters

}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_pushButton_clicked()
{
    //QByteArray data="f";
   //192.168.1.6 clientS->write(data);
    this->hide();
    ForgotWindow* FWindow= new ForgotWindow();
    FWindow->show();

}


void LoginWindow::on_pushButton_2_clicked()
{
   QByteArray data="l+";
    clientS->write(data);
    QByteArray data1 = ui->username->text().toUtf8()+ "+";
    clientS->write(data1);
    QByteArray data2 = ui->password->text().toUtf8();
    clientS->write(data2);
    QByteArray lisend = clientS->readAll();
    if(lisend=="1")
    {
        StartWindow * FWindow= new StartWindow();
    FWindow->show();
    }
    if(lisend=="0")
    {
     ui->textEdit->setText("wrong...");
    }
}

