#include "zambiesgame.h"
#include "ui_zambiesgame.h"
#include"loginwindow.h"
zambiesGame::zambiesGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zambiesGame)
{

    ui->setupUi(this);



    this->setStyleSheet("zambiesGame { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot_12_optimized.png); }");

    QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/regular zombie.jpg";
     ui->pushButton ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/leaf hair zombie.jpg";
     ui->pushButton_2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/astronaut zombie.jpg";
     ui->pushButton_3 ->setStyleSheet("QPushButton { "
                            "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/tall zombie.jpg";
     ui->pushButton_4 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/Bucket head zombie.jpg";
     ui->pushButton_5 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/purple hair zombie.jpg";
     ui->pushButton_6 ->setStyleSheet("QPushButton { "
                           "    border-image: url(" + imagePath + ") stretch;"
                             "}");

    applyStylesheets();
}

zambiesGame::~zambiesGame()
{
    delete ui;
}

void zambiesGame::on_pushButton_clicked()
{

    this->hide();
    LoginWindow* thirdWindow= new LoginWindow();
    thirdWindow->show();
}

void zambiesGame::on_pushButton_7_clicked()
{
    this->hide();
    LoginWindow* thirdWindow= new LoginWindow();
    thirdWindow->show();
}

void zambiesGame::applyStylesheets()
{
    for (int i = 7; i <= 78; ++i) {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0); border: none; }");
        }
    }
}
