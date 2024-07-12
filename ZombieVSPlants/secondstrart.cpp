#include "secondstrart.h"
#include "ui_secondstrart.h"


SecondStrart::SecondStrart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondStrart),
    clients(new QTcpSocket(this))
{
    ui->setupUi(this);
     this->setStyleSheet(" { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");

    connect(socket, &QTcpSocket::readyRead, this, &SecondStrart::listenServer);
    socket->connectToHost(hostId, 2025);
}

SecondStrart::~SecondStrart()
{
    delete ui;
}

void SecondStrart::on_pushButton_clicked()
{
    QByteArray data="i";
    socket->write(data);
    QByteArray lisend = socket->readAll();
    this->hide();
    QString receiveString = QString::fromUtf8(lisend);
    gameHistory *w   = new gameHistory();
    w->show();
    w->setTextInTextEdit(receiveString);
}


void SecondStrart::on_pushButton_2_clicked()
{
    this->hide();
    setting *u=new setting();
    u->show();
}


void SecondStrart::on_pushButton_3_clicked()
{
    QByteArray data = "h";
    if (socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Attempting to write data to socket...";
        socket->write(data);
        if (socket->waitForBytesWritten(5000)) {  // Wait up to 5 seconds
            qDebug() << "Data written to socket.";
         }
      }
}

void SecondStrart::listenServer()
{
    QByteArray data = socket->readAll();
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

