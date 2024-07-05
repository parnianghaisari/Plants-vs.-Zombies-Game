#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("SignUpWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");

}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_pushButton_clicked()
{

    QByteArray data="s2";
    clientS->write(data);
   QByteArray data1 = ui->name->text().toUtf8()+ "\n";
   clientS->write(data1);
   QByteArray data2 = ui->uName->text().toUtf8()+ "\n";
   clientS->write(data2);
   QByteArray data3 = ui->pass->text().toUtf8()+ "\n";
   clientS->write(data3);
   QByteArray data4 = ui->address->text().toUtf8()+ "\n";
   clientS->write(data4);
   QByteArray data5 = ui->PNumber->text().toUtf8()+ "\n";
   clientS->write(data5);
   this->hide();
  StartWindow* SWindow= new StartWindow();
   SWindow->show();
}

