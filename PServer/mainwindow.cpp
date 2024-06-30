#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , server(new Server(this))
{
    ui->setupUi(this);

    connect(server, &Server::clientConnected, this, &MainWindow::onClientConnected);
    connect(server, &Server::clientDisconnected, this, &MainWindow::onClientDisconnected);
    connect(server, &Server::messageReceived, this, &MainWindow::onMessageReceived);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onClientConnected(const QString &address) {
    ui->logBox->append("Client connected: " + address);
    ui->clientList->addItem(address);
}

void MainWindow::onClientDisconnected(const QString &address) {
    ui->logBox->append("Client disconnected: " + address);
    QList<QListWidgetItem*> items = ui->clientList->findItems(address, Qt::MatchExactly);
    if (!items.isEmpty()) {
        delete items.first();
    }
}

void MainWindow::onMessageReceived(const QString &message) {
    ui->logBox->append("Message received: " + message);
}
