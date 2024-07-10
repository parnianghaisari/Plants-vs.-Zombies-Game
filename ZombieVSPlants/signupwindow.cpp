#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("SignUpWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");
    ui->pass->setEchoMode(QLineEdit::Password);
    QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/unhide.png";
    ui->pushButton_2->setStyleSheet("QPushButton { "
                          "    border-image: url(" + imagePath + ") stretch;"
                          "}");
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_pushButton_clicked()
{
 int check = checkPassword();
 if(check==1){
   QByteArray data="s+";
   clientS->write(data);
   QByteArray data1 = ui->name->text().toUtf8()+ "+";
   clientS->write(data1);
   QByteArray data2 = ui->uName->text().toUtf8()+ "+";
   clientS->write(data2);
   QByteArray data3 = ui->pass->text().toUtf8()+ "+";
   clientS->write(data3);
   QByteArray data4 = ui->address->text().toUtf8()+ "+";
   clientS->write(data4);
   QByteArray data5 = ui->PNumber->text().toUtf8();
   clientS->write(data5);
   this->hide();
   StartWindow* SWindow= new StartWindow();
   SWindow->show();
 }
}

int SignUpWindow::checkPassword() {
    QString password = ui->pass->text();

    if (password.length() != 8) {
         ui->textEdit->setText("Invalid Password , it must contain 8 letters.");
        return 0;
    }
    QRegularExpression upperCaseRegex("[A-Z]");
    QRegularExpressionMatch upperCaseMatch = upperCaseRegex.match(password);
    if (!upperCaseMatch.hasMatch()) {
         ui->textEdit->setText("Invalid Password ,Password must contain at least one uppercase letter.");
        return 0;
    }

    QRegularExpression numberRegex("[0-9]");
    QRegularExpressionMatch numberMatch = numberRegex.match(password);
    if (!numberMatch.hasMatch()) {
           ui->textEdit->setText("Invalid Password ,Password must contain at least one number.");
        return 0;
    }

   ui->textEdit->setText("valid Password.");
   return 1;
}

void SignUpWindow::on_pushButton_2_clicked()
{

  ui->pass->setEchoMode(QLineEdit::Normal);
}

