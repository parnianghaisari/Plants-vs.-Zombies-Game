#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
     this->setStyleSheet("StartWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/pvz2-ea-hero-pvz2-xl.jpg.adapt.crop16x9.1023w.jpg); }");

    dataHandler = new DataHandler(this);

    // Connect DataHandler signal to MainWindow slot
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    QByteArray data="i";
    clientS->write(data);
    QByteArray lisend = clientS->readAll();
    this->hide();
    QString receivedString = QString::fromUtf8(lisend);
    gameHistory *w  =  new gameHistory();
    w->show();
    w->setTextInTextEdit(receivedString);
}


void StartWindow::on_pushButton_2_clicked()
{
    this->hide();
    setting *u= new setting();
    u->show();
}


void StartWindow::on_pushButton_3_clicked()
{
    clientS->write("h");

        // Wait for server response
        if (!clientS->waitForReadyRead(3000)) {
            qDebug() << "Error: " << clientS->errorString();
            return;
        }
    // Read server response
       QByteArray responseData = clientS->readAll();
       QString responseString = QString::fromUtf8(responseData);

       qDebug() << "Server response:" << responseString;

       // Process server response
       if (responseString == "1") {
           this->hide();
           zambiesGame *x= new zambiesGame();
           x->show();

       } else if (responseString == "0") {
           this->hide();
           plants *x= new plants();
           x->show();
       } else {
           qDebug() << "Unexpected server response:" << responseString;
       }
}


