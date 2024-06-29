#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include <QTabBar>

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
        this->setStyleSheet("MainWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot (7) (1).png); }");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow2* secondWindow= new MainWindow2();
    secondWindow->show();
}

