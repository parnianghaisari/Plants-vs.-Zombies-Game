#include "plants.h"
#include "ui_plants.h"
#include "zambiesgame.h"
plants::plants(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plants),
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
      timer2 = new QTimer(this);
       connect(timer, &QTimer::timeout, this, &plants::showMapP);
       timer2->start(1000);
      listen = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &plants::listenServerP);
        listen->start(500);
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
        plant=26;
    else
        plant =0;
}
void plants::on_pushButtonC2_2_clicked()
{
    if(Suns >= 150)
        plant=25;
    else
        plant =0;
}
void plants::on_pushButtonC3_2_clicked()
{
    if(Suns >= 50)
        plant=21;
    else
        plant =0;
}

void plants::on_pushButtonC4_2_clicked()
{
    if(Suns >= 175)
        plant=24;
    else
        plant =0;
}

void plants::on_pushButtonC5_2_clicked()
{
    if(Suns >= 100)
        plant=22;
    else
        plant =0;
}

void plants::on_pushButtonC6_2_clicked()
{
    if(Suns >= 100)
        plant=23;
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

void plants::on_pushButton_1_clicked()
{
    if (plant!=0&& gameMap[1] == 0) {
         gameLogicHandlerP.createPlant(plant, 1);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+1";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_2_clicked()
{
    if (plant!=0&& gameMap[2] == 0) {
         gameLogicHandlerP.createPlant(plant, 2);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+2";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_3_clicked()
{
    if (plant!=0&& gameMap[3] == 0) {
         gameLogicHandlerP.createPlant(plant, 3);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+3";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_4_clicked()
{
    if (plant!=0&& gameMap[4] == 0) {
         gameLogicHandlerP.createPlant(plant, 4);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+4";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_5_clicked()
{
    if (plant!=0&& gameMap[5] == 0) {
         gameLogicHandlerP.createPlant(plant, 5);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+5";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_6_clicked()
{
    if (plant!=0&& gameMap[6] == 0) {
         gameLogicHandlerP.createPlant(plant, 6);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+6";
        clientS->write(data);
         plant=0;

    }
}
void plants::on_pushButton_7_clicked()
{
    if (plant!=0&& gameMap[7] == 0) {
         gameLogicHandlerP.createPlant(plant, 7);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+7";
        clientS->write(data);
         plant=0;

    }
}

void plants::on_pushButton_8_clicked()
{
    if (plant!=0&& gameMap[8] == 0) {
         gameLogicHandlerP.createPlant(plant, 8);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+8";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_9_clicked()
{
    if (plant!=0&& gameMap[9] == 0) {
         gameLogicHandlerP.createPlant(plant, 9);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+9";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_10_clicked()
{
    if (plant!=0&& gameMap[10] == 0) {
         gameLogicHandlerP.createPlant(plant, 10);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+10";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_11_clicked()
{
    if (plant!=0&& gameMap[11] == 0) {
         gameLogicHandlerP.createPlant(plant, 11);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+11";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_12_clicked()
{
    if (plant!=0&& gameMap[12] == 0) {
         gameLogicHandlerP.createPlant(plant, 12);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+12";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_13_clicked()
{
    if (plant!=0&& gameMap[13] == 0) {
         gameLogicHandlerP.createPlant(plant, 13);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+13";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_14_clicked()
{
    if (plant!=0&& gameMap[14] == 0) {
         gameLogicHandlerP.createPlant(plant, 14);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+14";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_15_clicked()
{
    if (plant!=0&& gameMap[15] == 0) {
         gameLogicHandlerP.createPlant(plant, 15);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+15";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_16_clicked()
{
    if (plant!=0&& gameMap[16] == 0) {
         gameLogicHandlerP.createPlant(plant, 16);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+16";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_17_clicked()
{
    if (plant!=0&& gameMap[17] == 0) {
         gameLogicHandlerP.createPlant(plant, 17);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+17";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_18_clicked()
{
    if (plant!=0&& gameMap[18] == 0) {
         gameLogicHandlerP.createPlant(plant, 18);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+18";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_19_clicked()
{
    if (plant!=0&& gameMap[19] == 0) {
         gameLogicHandlerP.createPlant(plant, 19);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+19";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_20_clicked()
{
    if (plant!=0&& gameMap[20] == 0) {
         gameLogicHandlerP.createPlant(plant, 20);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+20";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_21_clicked()
{
    if (plant!=0&& gameMap[21] == 0) {
         gameLogicHandlerP.createPlant(plant, 21);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+21";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_22_clicked()
{
    if (plant!=0&& gameMap[22] == 0) {
         gameLogicHandlerP.createPlant(plant, 22);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+22";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_23_clicked()
{
    if (plant!=0&& gameMap[23] == 0) {
         gameLogicHandlerP.createPlant(plant, 23);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+23";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_24_clicked()
{
    if (plant!=0&& gameMap[24] == 0) {
         gameLogicHandlerP.createPlant(plant, 24);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+24";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_25_clicked()
{
    if (plant!=0&& gameMap[25] == 0) {
         gameLogicHandlerP.createPlant(plant, 25);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+25";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_26_clicked()
{
    if (plant!=0&& gameMap[26] == 0) {
         gameLogicHandlerP.createPlant(plant, 26);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+26";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_27_clicked()
{
    if (plant!=0&& gameMap[27] == 0) {
         gameLogicHandlerP.createPlant(plant, 27);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+27";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_28_clicked()
{
    if (plant!=0&& gameMap[28] == 0) {
         gameLogicHandlerP.createPlant(plant, 28);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+28";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_29_clicked()
{
    if (plant!=0&& gameMap[29] == 0) {
         gameLogicHandlerP.createPlant(plant, 29);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+29";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_30_clicked()
{
    if (plant!=0&& gameMap[30] == 0) {
         gameLogicHandlerP.createPlant(plant, 30);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+30";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_31_clicked()
{
    if (plant!=0&& gameMap[31] == 0) {
         gameLogicHandlerP.createPlant(plant, 31);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+31";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_32_clicked()
{
    if (plant!=0&& gameMap[32] == 0) {
         gameLogicHandlerP.createPlant(plant, 32);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+32";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_33_clicked()
{
    if (plant!=0&& gameMap[33] == 0) {
         gameLogicHandlerP.createPlant(plant, 33);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+33";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_34_clicked()
{
    if (plant!=0&& gameMap[34] == 0) {
         gameLogicHandlerP.createPlant(plant, 34);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+34";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_35_clicked()
{
    if (plant!=0&& gameMap[35] == 0) {
         gameLogicHandlerP.createPlant(plant, 35);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+35";
        clientS->write(data);
         plant=0;

    }
}


void plants::on_pushButton_36_clicked()
{
    if (plant!=0&& gameMap[36] == 0) {
         gameLogicHandlerP.createPlant(plant, 36);
         QString s = QString::number(plant);
        QByteArray data="g+"+s.toUtf8() +"+36";
        clientS->write(data);
         plant=0;

    }
}

void plants::showMapP()
{

    if (gameLogicHandlerP.winner == 1) {
         timer2->stop();
         this->hide();
         ForgotWindow* FWindow= new ForgotWindow();
         FWindow->show();
         return;
     }
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
           beforeMoving.clear();
      }
  if(bornZombies.size()!=0)
    {for (auto i = bornZombies.begin(); i != bornZombies.end(); ++i) {
        int a=i.key();
        int b=i.value();
        QString imagePath;
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
        bornZombies.clear();
}
    }
if(deadZombies.size()!=0)
  {   for (int i = 0; i != deadZombies.size(); ++i) {
       QString buttonName = QString("pushButton_%1").arg(deadZombies[i]);
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
       deadZombies.pop_front();
}
}
    beforeMoving.clear();
    bornZombies.clear();

    for(int i=0 ;i<deadPlants.size(); i++)
    {
        QString buttonName = QString("pushButton_%1").arg(deadPlants[i]);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        button->setStyleSheet("QPushButton { "
                              "    background-color: rgba(255, 255, 255, 0); "
                              "    border: none; "
                              "}");

    }
    deadPlants.clear();
    for (int i = 1; i <= 36; ++i)
    {
    if(gameMap[i]!=0)
    {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        QString imagePath;
        switch (gameMap[i] / 1000)
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

}

}

void plants:: listenServerP(){
    QByteArray data = clientS->readAll();
    QString str(data);
    QStringList usAndps= str.split('+');
    if (usAndps.size() >= 3) {
        bool ok1, ok2;
        int value1 = usAndps[1].toInt(&ok1);
        int value2 = usAndps[2].toInt(&ok2);

        if (ok1 && ok2) {
            gameLogicHandlerP.createZombie(value1, value2);
        }
    }
}
