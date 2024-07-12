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
    int check =checkPassword();
    if(check==1)
    {
       QByteArray data="f+";
       clientS->write(data);
       QByteArray data1 = ui->user->text().toUtf8()+ "+";
       clientS->write(data1);
       QByteArray data2 = ui->phone->text().toUtf8();
       clientS->write(data2);
       if (!clientS->waitForReadyRead(3000)){
           return;
       }
       // Read server response
          QByteArray responseData = clientS->readAll();
          QString responseString = QString::fromUtf8(responseData);
      qDebug()<<responseString;
       if(responseString=="1"){
        QByteArray data="n+";
        clientS->write(data);
        QByteArray data1 = ui->user->text().toUtf8()+ "+";
        clientS->write(data1);
        QByteArray data2 = ui->pass->text().toUtf8();
        clientS->write(data2);
        StartWindow * FWindow= new StartWindow();
        FWindow->show();
    }
    if(responseString=="0")
    {
     ui->textEdit->setText("wrong...");
    }

  }
    else{
        ui->textEdit->setText("wrong pass...");
    }
}

int ForgotWindow::checkPassword() {
    QString password = ui->pass->text();

    if (password.length() != 8) {
        return 0;
    }
    QRegularExpression upperCaseRegex("[A-Z]");
    QRegularExpressionMatch upperCaseMatch = upperCaseRegex.match(password);
    if (!upperCaseMatch.hasMatch()) {
        return 0;
    }

    QRegularExpression numberRegex("[0-9]");
    QRegularExpressionMatch numberMatch = numberRegex.match(password);
    if (!numberMatch.hasMatch()) {
        return 0;
    }
   return 1;
}
