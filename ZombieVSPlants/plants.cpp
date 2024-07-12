#include "plants.h"
#include "ui_plants.h"
#include "zambiesgame.h"
plants::plants(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plants),
     clients(new QTcpSocket(this)),
    gameLogicHandlerP(this)
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
       RoundG++;
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
       connect(clientS, &QTcpSocket::readyRead, this, &plants::listenServerP);
       connect(&gameLogicHandlerP, &GameLogicHandling::gameStateUpdated, this, &plants::showMapP);

          clientS->connectToHost(hostId, 2025);
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

void plants::on_pushButtonC1_2_clicked()
{
    if(Suns >= 125)
    {    plant=26;
        Suns=Suns-125;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
}
void plants::on_pushButtonC2_2_clicked()
{
    if(Suns >= 150)
     {   plant=25;
        Suns=Suns-150;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
}
void plants::on_pushButtonC3_2_clicked()
{
    if(Suns >= 50)
      {  plant=21;
        Suns=Suns-50;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
}

void plants::on_pushButtonC4_2_clicked()
{
    if(Suns >= 175)
     {   plant=24;
        Suns=Suns-175;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
}

void plants::on_pushButtonC5_2_clicked()
{
    if(Suns >= 100)
     {   plant=22;
        Suns=Suns-100;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
}

void plants::on_pushButtonC6_2_clicked()
{
    if(Suns >= 100)
      {  plant=23;
        Suns=Suns-100;
        ui->textEdit->setText(QString::number(Suns));
    }
    else
        plant =0;
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

void plants::on_pushButton_1_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[1] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+1";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_2_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[2] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+2";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_3_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[3] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+3";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_4_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[4] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+4";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_5_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[5] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+5";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_6_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[6] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+6";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}
void plants::on_pushButton_7_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[7] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+7";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}

void plants::on_pushButton_8_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[8] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+8";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_9_clicked()
{
    qDebug()<<"in the button";
     qDebug()<<plant;
     if (plant != 0 && gameMap[9] == 0) {
      qDebug()<<"in the button2";
         QString s = QString::number(plant);
         QByteArray data = "p+" + s.toUtf8() + "+9";

         if (clientS->state() == QAbstractSocket::ConnectedState) {
             qDebug() << "Attempting to write data to socket...";
             clientS->write(data);

         } else {
             qDebug() << "Socket is not connected!";
         }

         plant = 0;
     }
}


void plants::on_pushButton_10_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[10] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+10";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_11_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[11] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+11";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_12_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[12] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+12";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_13_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[13] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+13";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_14_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[14] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+14";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_15_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[15] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+15";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_16_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[16] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+16";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_17_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[17] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+17";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_18_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[18] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+18";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_19_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[19] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+19";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_20_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[20] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+20";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_21_clicked()
{
    qDebug()<<"in the button";
    qDebug()<<plant;
    if (plant != 0 && gameMap[21] == 0) {
     qDebug()<<"in the button2";
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+21";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        } else {
            qDebug() << "Socket is not connected!";
        }

        plant = 0;
    }
}


void plants::on_pushButton_22_clicked()
{

    if (plant != 0 && gameMap[22] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+22";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_23_clicked()
{
    if (plant != 0 && gameMap[23] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+23";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_24_clicked()
{
    if (plant != 0 && gameMap[24] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+24";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_25_clicked()
{
    if (plant != 0 && gameMap[25] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+25";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_26_clicked()
{
    if (plant != 0 && gameMap[26] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+26";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_27_clicked()
{
    if (plant != 0 && gameMap[27] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+27";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_28_clicked()
{
    if (plant != 0 && gameMap[28] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+28";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_29_clicked()
{
    if (plant != 0 && gameMap[29] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+29";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_30_clicked()
{
    if (plant != 0 && gameMap[30] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+30";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_31_clicked()
{
    if (plant != 0 && gameMap[31] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+31";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_32_clicked()
{
    if (plant != 0 && gameMap[32] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+32";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_33_clicked()
{
    if (plant != 0 && gameMap[33] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+33";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_34_clicked()
{
    if (plant != 0 && gameMap[34] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+34";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_35_clicked()
{
    if (plant != 0 && gameMap[35] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+35";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}


void plants::on_pushButton_36_clicked()
{
    if (plant != 0 && gameMap[36] == 0) {
        QString s = QString::number(plant);
        QByteArray data = "p+" + s.toUtf8() + "+36";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);

        }
        plant = 0;
    }
}

void plants::showMapP()
{
    if (gameLogicHandlerP.winner != 1) {
     {  timer2->stop();
         qDebug() << "Timer stopped because winner == 1";
         QString winnerString = QString::number(gameLogicHandlerP.winner);
         QByteArray winnerData = winnerString.toUtf8();
         QByteArray UsernameData = userName.toUtf8();
         QByteArray data = winnerData + "+" + UsernameData + "+" +"p";
          clientS->write(data);
          if (clientS->waitForBytesWritten(5000)) {
              qDebug() << "Data written to socket.";
          }
          if(RoundG ==2){
              this->hide();
            lastPage * p = new lastPage();
            p->show();
          }
          else {
             // StartWindow * s =new StartWindow();
              this->hide();
          }
          return;
     }
     qDebug() << "show ";
      QLabel *label = new QLabel(this);
       QString imagePath;
      if(beforeMoving.size()!=0)
     { for (auto i = beforeMoving.begin(); i != beforeMoving.end(); ++i) {
        int a=i.key();
        int b=i.value();
        QMovie *movie;
        QString buttonName = QString("pushButton_%1").arg(a);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
               QLabel* label = button->findChild<QLabel*>();
               if (label) {
                   button->layout()->removeWidget(label);
                   label->deleteLater();
               }
               button->setStyleSheet("QPushButton { "
                                     "    background-color: rgba(255, 255, 255, 0); "
                                     "    border: none; "
                                     "}");
           }
         buttonName = QString("pushButton_%1").arg(a-6);
         button = findChild<QPushButton*>(buttonName);
        switch (b/1000)
        {
        case 11:
           {

            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/walking-plants-vs-zombies-ezgif.com-resize.gif";
            movie = new QMovie(imagePath);
            label->setMovie(movie);
            movie->start();
            break;
        }
        case 12:
        {

        imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Buckethead-Zombie-unscreen-ezgif.com-resize.gif";
         movie = new QMovie(imagePath);
         label->setMovie(movie);
         movie->start();
         break;
     }
        case 13:
        {
        imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/leafhead-unscreen-ezgif.com-resize.gif";
         movie = new QMovie(imagePath);
         label->setMovie(movie);
         movie->start();
         break;
     }
        case 14:
        {

         imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/walking-plants-vs-zombies-ezgif.com-resize.gif";
         movie = new QMovie(imagePath);
         label->setMovie(movie);
         movie->start();
         break;
     }
        case 15:
        {  imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/astronaut-unscreen.gif";
           movie = new QMovie(imagePath);
           label->setMovie(movie);
           movie->start();
           break;
      }
        case 16:
        {
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/purple-hair-unscreen-ezgif.com-resize.gif";
           movie = new QMovie(imagePath);
           label->setMovie(movie);
           movie->start();
           break;
      }
        }
        if (!imagePath.isEmpty())
        {
            button->setStyleSheet("QPushButton { border: none; }"); // Remove border if needed
            button->setLayout(new QHBoxLayout);
            button->layout()->addWidget(label);
        }

     }

      }
  if(bornZombies.size()!=0)
    {for (auto i = bornZombies.begin(); i != bornZombies.end(); ++i) {
        int a=i.key();
        int b=i.value();
        QString imagePath;
           qDebug()<<a;
        QString buttonName = QString("pushButton_%1").arg(a);
        QLabel *label = new QLabel(this);
        QPushButton  *button = findChild<QPushButton*>(buttonName);
        QMovie *movie;
       ui->textEdit->setText(QString::number(b/1000));
       switch (b/1000)
       {
       case 11:
          {

           imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/walking-plants-vs-zombies-ezgif.com-resize.gif";
           movie = new QMovie(imagePath);
           label->setMovie(movie);
           movie->start();
           break;
       }
       case 12:
       {

       imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Buckethead-Zombie-unscreen-ezgif.com-resize.gif";
        movie = new QMovie(imagePath);
        label->setMovie(movie);
        movie->start();
        break;
    }
       case 13:
       {
       imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/leafhead-unscreen-ezgif.com-resize.gif";
        movie = new QMovie(imagePath);
        label->setMovie(movie);
        movie->start();
        break;
    }
       case 14:
       {

        imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/walking-plants-vs-zombies-ezgif.com-resize.gif";
        movie = new QMovie(imagePath);
        label->setMovie(movie);
        movie->start();
        break;
    }
       case 15:
       {  imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/astronaut-unscreen.gif";
          movie = new QMovie(imagePath);
          label->setMovie(movie);
          movie->start();
          break;
     }
       case 16:
       {
           imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/purple-hair-unscreen-ezgif.com-resize.gif";
          movie = new QMovie(imagePath);
          label->setMovie(movie);
          movie->start();
          break;
     }
       }
        if (!imagePath.isEmpty())
        {
            button->setStyleSheet("QPushButton { border: none; }"); // Remove border if needed
            button->setLayout(new QHBoxLayout);
            button->layout()->addWidget(label);
        }
}
    }
  if(deadZombies.size()!=0)
    {   for (int i = 0; i < deadZombies.size(); ++i) {
         QString buttonName = QString("pushButton_%1").arg(deadZombies[i]);
         QPushButton *button = findChild<QPushButton*>(buttonName);
         qDebug() << i+1 <<"zombies deleted";
         if (button) {
              qDebug() << i+1 <<"zombies deleted2";
                QLabel* label = button->findChild<QLabel*>();
                if (label) {
                     qDebug() << i+1 <<"zombies deleted3";
                    button->layout()->removeWidget(label);
                    label->deleteLater();
                }
                button->setStyleSheet("QPushButton { "
                                      "    background-color: rgba(255, 255, 255, 0); "
                                      "    border: none; "
                                      "}");
            }
  }
  }
    beforeMoving.clear();
    bornZombies.clear();
    deadZombies.clear();

    for(int i=0 ;i<deadPlants.size(); i++)
    {
        QString buttonName = QString("pushButton_%1").arg(deadPlants[i]);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        button->setStyleSheet("QPushButton { "
                              "    background-color: rgba(255, 255, 255, 0); "
                              "    border: none; "
                              "}");

    }
    for (auto i = bornPlants.begin(); i !=bornPlants.end(); ++i)
    {

        QString buttonName = QString("pushButton_%1").arg(i.key());
        QPushButton *button = findChild<QPushButton*>(buttonName);
        QString imagePath;
           qDebug()<<i.key();
        switch (i.value() / 1000)
        {
        case 21:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/pea shooter.jpg";
            break;
        case 22:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/two_peashooter.jpg";
            break;
        case 23:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/walnut.jpg";
            break;
        case 24:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/plum mine.jpg";
            break;
        case 25:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/jalapino.jpg";
            break;
        case 26:
            imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/boomerang.jpg";
            break;
        }
        if (!imagePath.isEmpty())
        {
            button->setStyleSheet("QPushButton { "
                                  "    border-image: url(" + imagePath + ") stretch;"
                                  "}");
        }
    }
deadPlants.clear();
bornPlants.clear();
}
}
void plants::listenServerP() {
    QByteArray data = clientS->readAll();
    QString str(data);
    qDebug()<<str;
    QStringList parts = str.split('+');
    if (parts.size() >= 3) {
        QString command = parts[0];
        int id = parts[1].toInt();
        int position = parts[2].toInt();

        if (command =='z') { // Zombie
            gameLogicHandlerP.createZombie(id, position);
        } else if(command =='p') { // Plant
            gameLogicHandlerP.createPlant(id, position);
        }

        showMapP(); // Update the UI to reflect the changes
    }
}


