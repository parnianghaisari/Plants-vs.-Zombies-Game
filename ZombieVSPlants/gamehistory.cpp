#include "gamehistory.h"
#include "ui_gamehistory.h"
#include "startwindow.h"

gameHistory::gameHistory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameHistory),
    textEdit(new QTextEdit(this))
{
    ui->setupUi(this);
    this->setStyleSheet("gameHistory { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");
    setCentralWidget(textEdit);
}

gameHistory::~gameHistory()
{
    delete ui;
}

void gameHistory::on_pushButton_clicked()
{
    this->hide();


}

void gameHistory::setTextInTextEdit(const QString &text)
{
    textEdit->setText(text);
}
