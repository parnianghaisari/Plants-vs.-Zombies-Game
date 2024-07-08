
#include "plants.h"
#include "ui_plants.h"
#include "zambiesgame.h"
plants::plants(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plants)
{
    ui->setupUi(this);
    this->setStyleSheet("plants { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot_12_optimized.png); }");

    QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/boomerang.jpg";
     ui->pushButton ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/jalapino.jpg";
     ui->pushButton_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/pea shooter.jpg";
     ui->pushButton_3 ->setStyleSheet("QPushButton { "
                            "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/plum mine.jpg";
     ui->pushButton_4 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/two_peashooter.jpg";
     ui->pushButton_5 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/walnut.jpg";
     ui->pushButton_6 ->setStyleSheet("QPushButton { "
                           "    border-image: url(" + imagePath + ") stretch;"
                             "}");
       applyStylesheets();
}

plants::~plants()
{
    delete ui;
}
void plants::applyStylesheets()
{
    for (int i = 7; i <= 78; ++i) {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0); border: none; }");
        }
    }
}

void plants::on_pushButton_7_clicked()
{
    this->hide();
    zambiesGame* thirdWindow= new zambiesGame();
    thirdWindow->show();
}

void plants::on_pushButton_clicked()
{
    plant=1;
}


void plants::on_pushButton_2_clicked()
{
    plant=2;
}


void plants::on_pushButton_3_clicked()
{
    plant=3;
}


void plants::on_pushButton_4_clicked()
{
    plant=4;
}



void plants::on_pushButton_5_clicked()
{
    plant=5;
}


void plants::on_pushButton_6_clicked()
{
    plant=6;
}

