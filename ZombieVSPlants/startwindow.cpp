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
    connect(dataHandler, &DataHandler::dataReceived, this, &StartWindow::updateLineEdit);
}

void StartWindow::updateLineEdit(const QByteArray &data)
{
    QString dataStr = QString::fromUtf8(data);
    ui->lineEdit_dataReceived->setText(dataStr);
}
StartWindow::~StartWindow()
{
    delete ui;
}
