#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    QByteArray lisend = clientS->readAll();
    QString strr(lisend);
    QStringList arr =strr.split('+');
    ui->lineEdit1->setText(arr[0]);
    ui->lineEdit2->setText(arr[1]);
    ui->lineEdit3->setText(arr[2]);
    ui->lineEdit4->setText(arr[3]);
    ui->lineEdit5->setText(arr[4]);

}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_clicked()
{
    QString data = ui->lineEdit1->text() + '+' +
                      ui->lineEdit2->text() + '+' +
                      ui->lineEdit3->text() + '+' +
                      ui->lineEdit4->text() + '+' +
                      ui->lineEdit5->text();
       QByteArray byteArrayData = data.toUtf8();
       clientS->write(byteArrayData);
       this->hide();
       StartWindow *u= new StartWindow();
       u->show();

}
