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
   QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/unhide.png";
   ui->pushButton_3->setStyleSheet("QPushButton { "
                         "    border-image: url(" + imagePath + ") stretch;"
                         "}");

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

    QByteArray requestData = "l+";
      QByteArray usernameData = ui->username->text().toUtf8() + "+";
      QByteArray passwordData = ui->password->text().toUtf8();

      // Send login request to server
      clientS->write(requestData);
      clientS->write(usernameData);
      clientS->write(passwordData);

      // Wait for server response
      if (!clientS->waitForReadyRead(3000)){
          return;
      }
      // Read server response
         QByteArray responseData = clientS->readAll();
         QString responseString = QString::fromUtf8(responseData);


         // Process server response
         if (responseString == "1") {
             this->hide();
             StartWindow *startWindow = new StartWindow();
             startWindow->show();
         } else if (responseString == "0") {
             ui->textEdit->setText("Wrong username or password.");
         }
}


void LoginWindow::on_pushButton_3_clicked()
{
      ui->password->setEchoMode(QLineEdit::Normal);
}

