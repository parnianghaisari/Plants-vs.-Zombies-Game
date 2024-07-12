#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow),
    clients(new QTcpSocket(this))
{
    ui->setupUi(this);
     this->setStyleSheet("StartWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");

    connect(clients, &QTcpSocket::readyRead, this, &StartWindow::listenServer);
    clients->connectToHost(hostId, 2025);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    QByteArray data="i";
    clients->write(data);
    QByteArray lisend = clients->readAll();
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
    QByteArray data = "h";
    if (clients->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Attempting to write data to socket...";
        clients->write(data);
        if (clients->waitForBytesWritten(5000)) {  // Wait up to 5 seconds
            qDebug() << "Data written to socket.";
         }
      }
}

void StartWindow::listenServer()
{
    QByteArray data = clients->readAll();
    QString message = QString::fromUtf8(data);
    if (message == "1")
    {
        zambiesGame *p = new zambiesGame();
        this->hide();
        p->show();
    }
    if (message == "0")
    {
        plants *p = new plants();
        this->hide();
        p->show();
    }
}

