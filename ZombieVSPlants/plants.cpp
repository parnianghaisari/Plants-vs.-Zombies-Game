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
       srand(time(nullptr));
      timer = new QTimer(this);
      connect(timer, &QTimer::timeout, this, &plants::generateRandomNumberS);
      timer->start(5000);
      for (int i = 1; i <= 36; ++i) {
          QString buttonName = QString("pushButtonS%1").arg(i);
          QPushButton *button = findChild<QPushButton *>(buttonName);
          if (button) {
              connect(button, &QPushButton::clicked, this, &plants::handleButtonClick);
          } else {
              qDebug() << "Button not found:" << buttonName;
          }
      }
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
    for (int i = 1; i <= 36; ++i) {
        QString buttonName = QString("pushButtonS%1").arg(i);
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

void plants::on_pushButtonC1_2_clicked()
{
    plant=1;
}
void plants::on_pushButtonC2_2_clicked()
{
    plant=2;
}
void plants::on_pushButtonC3_2_clicked()
{
    plant=3;
}

void plants::on_pushButtonC4_2_clicked()
{
    plant=4;
}

void plants::on_pushButtonC5_2_clicked()
{
    plant=5;
}

void plants::on_pushButtonC6_2_clicked()
{
    plant=6;
}

void plants::generateRandomNumberS() {
    locSun = 1 + std::rand() % 36; // Generates a number between 37 and 72
    QString buttonName = QString("pushButtonS%1").arg(locSun);
    QPushButton *button = findChild<QPushButton *>(buttonName);
    if (button) {
        QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Sun.png";
        button->setStyleSheet("QPushButton { "
                              "    border-image: url(" + imagePath + ") stretch;"
                              "}");
        QTimer::singleShot(3000, [button]() {
            button->setStyleSheet("QPushButton { "
                                  "    background-color: rgba(255, 255, 255, 0); "
                                  "    border: none; "
                                  "}");
        });
        ui->textEdit_2->setText(QString::number(locSun));
    }
}

void plants::handleButtonClick() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonName = QString("pushButtonS%1").arg(locSun);
        if (button->objectName() == buttonName) {
            Suns += 25;
            ui->textEdit->setText(QString::number(Suns));

            button->setStyleSheet("QPushButton { "
                                  "    background-color: rgba(255, 255, 255, 0); "
                                  "    border: none; "
                                  "}");
       }
    }
}
