#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QTabBar>
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QTabBar* tab2= ui->tabWidget->findChild<QTabBar *>();
        tab2->hide(); // Hide the tab
        ui->tabWidget->setStyleSheet("QTabWidget::tab_2 { background: transparent; border: 0; }"
                                         "QTabBar::tab { background: transparent; }");
       this->setStyleSheet("MainWindow { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot_8_optimized.png); }");
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
