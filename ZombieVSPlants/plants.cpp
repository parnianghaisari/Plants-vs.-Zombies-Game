
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
     ui->pushButtonC1_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/jalapino.jpg";
     ui->pushButtonC2_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/pea shooter.jpg";
     ui->pushButtonC3_2 ->setStyleSheet("QPushButton { "
                            "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/plum mine.jpg";
     ui->pushButtonC4_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/two_peashooter.jpg";
     ui->pushButtonC5_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/walnut.jpg";
     ui->pushButtonC6_2 ->setStyleSheet("QPushButton { "
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
    for (int i = 1; i <= 72; ++i) {
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

<<<<<<< HEAD

void plants::on_pushButtonC1_2_clicked()
=======
void plants::on_pushButton_clicked()
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
{
    plant=1;
}


<<<<<<< HEAD
void plants::on_pushButtonC2_2_clicked()
=======
void plants::on_pushButton_2_clicked()
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
{
    plant=2;
}


<<<<<<< HEAD
void plants::on_pushButtonC3_2_clicked()
=======
void plants::on_pushButton_3_clicked()
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
{
    plant=3;
}


<<<<<<< HEAD
void plants::on_pushButtonC4_2_clicked()
=======
void plants::on_pushButton_4_clicked()
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
{
    plant=4;
}


<<<<<<< HEAD
void plants::on_pushButtonC5_2_clicked()
=======

void plants::on_pushButton_5_clicked()
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
{
    plant=5;
}


<<<<<<< HEAD
void plants::on_pushButtonC6_2_clicked()
{
    plant =6;
=======
void plants::on_pushButton_6_clicked()
{
    plant=6;
>>>>>>> b52bf0993ed7fb44be4492b562057526b8f7bdbc
}

