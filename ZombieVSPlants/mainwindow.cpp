#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"zambiesgame.h"
#include "mainwindow2.h"
#include <QTabBar>
#include "globals.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    QTabBar* tab= ui->tabWidget->findChild<QTabBar *>();
        tab->hide(); // Hide the tab
        ui->tabWidget->setStyleSheet("QTabWidget::tab_2 { background: transparent; border: 0; }"
                                         "QTabBar::tab { background: transparent; }");
        this->setStyleSheet("MainWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot_8_optimized.png); }");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

   // QString text_1 = ui->lineEdit->text();
    //QString text_2="192.168.1.101";
    QString text_3 = ui->lineEdit_2->text();
    QString text_4="2025";
    if( text_3.compare(text_4)==0 )
          {
            //check address and port
        connectToServer();
      this->hide();


    MainWindow2* secondWindow= new MainWindow2();
     secondWindow->show();
          }
    else{

    }

}

void MainWindow::connectToServer()
{
    QString text_1 = ui->lineEdit->text();
    clientS->connectToHost(text_1,2025);
    ui->textEdit->setText("connecting...");
    clientS->waitForConnected(-1);
    if( clientS->waitForConnected(-1)){
         ui->textEdit->setText("connected");
    }

}


