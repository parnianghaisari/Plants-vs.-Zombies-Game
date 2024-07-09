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
     ui->pushButtonC1 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/leaf hair zombie.jpg";
     ui->pushButtonC2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/astronaut zombie.jpg";
     ui->pushButtonC3 ->setStyleSheet("QPushButton { "
                            "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/tall zombie.jpg";
     ui->pushButtonC4 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/Bucket head zombie.jpg";
     ui->pushButtonC5 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/purple hair zombie.jpg";
     ui->pushButtonC6 ->setStyleSheet("QPushButton { "
                           "    border-image: url(" + imagePath + ") stretch;"
                             "}");

    applyStylesheets();
     srand(time(nullptr));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &zambiesGame::generateRandomNumberZ);
    timer->start(5000);
}

zambiesGame::~zambiesGame()
{
    delete ui;
}

void zambiesGame::on_pushButtonC1_clicked()
{

 zamby=1;
}

void zambiesGame::on_pushButton_7_clicked()
{
    this->hide();
    LoginWindow* thirdWindow= new LoginWindow();
    thirdWindow->show();
}

void zambiesGame::applyStylesheets()
{
    for (int i = 1; i <= 72; ++i) {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0); border: none; }");
        }

    }
    for (int i = 37; i <= 72; ++i) {
        QString buttonName = QString("pushButtonB%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0); border: none; }");
        }

    }
}

void zambiesGame::on_pushButtonC2_clicked()
{
    zamby=2;
}


void zambiesGame::on_pushButtonC3_clicked()
{
    zamby=3;
}


void zambiesGame::on_pushButtonC4_clicked()
{
    zamby=4;
}


void zambiesGame::on_pushButtonC5_clicked()
{
    zamby=5;
}


void zambiesGame::on_pushButtonC6_clicked()
{
    zamby=6;
}

void zambiesGame::generateRandomNumberZ() {
    int number = 37 + std::rand() % 36; // Generates a number between 37 and 72
     ui->textEdit->setText(QString("Generated number: %1").arg(number));
     locBrain = number;
     QString buttonName = QString("pushButtonB%1").arg(number);
     QPushButton *button = findChild<QPushButton *>(buttonName);
      QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Brain.png";
    button ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
    QTimer::singleShot(3000, [button]() {
          button->setStyleSheet("QPushButton { "
                                "    background-color: rgba(255, 255, 255, 0); "
                                "    border: none; "
                                "}");
      });

}
