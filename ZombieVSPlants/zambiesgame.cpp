#include "zambiesgame.h"
#include "ui_zambiesgame.h"
#include"loginwindow.h"
zambiesGame::zambiesGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zambiesGame),
      //gameTimer(new QTimer(this)),
      gameLogicHandlerZ(this)
{

    ui->setupUi(this);
    this->setStyleSheet("zambiesGame { background-image: url(D:/AP_newPro/AP_project/ZombieVSPlants/Screenshot_12_optimized.png); }");

    QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/regular zombie.jpg";
     ui->pushButtonC1 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/Bucket head zombie.jpg";
     ui->pushButtonC2 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/leaf hair zombie.jpg";
     ui->pushButtonC3 ->setStyleSheet("QPushButton { "
                            "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/tall zombie.jpg";
     ui->pushButtonC4 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/astronaut zombie.jpg";
     ui->pushButtonC5 ->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                             "}");
     imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/purple hair zombie.jpg";
     ui->pushButtonC6 ->setStyleSheet("QPushButton { "
                           "    border-image: url(" + imagePath + ") stretch;"
                             "}");

     //gameTimer->setInterval(240000); // 4 minutes
     //connect(gameTimer, &QTimer::timeout, this, &zambiesGame::onGameTimerTimeout);

     //gameTimer->start();

    ui->textEdit->setText(QString::number(Branis));
    applyStylesheets();
    srand(time(nullptr));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &zambiesGame::generateRandomNumberZ);
    timer->start(5000);
    for (int i = 37; i <= 72; ++i) {
        QString buttonName = QString("pushButtonB%1").arg(i);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &zambiesGame::handleButtonClick);
        } else {
            qDebug() << "Button not found:" << buttonName;
        }
    }
     timer2 = new QTimer(this);
     connect(timer2, &QTimer::timeout, this, &zambiesGame::showMapZ);
     timer2->start(500);
     listen = new QTimer(this);
     connect(timer, &QTimer::timeout, this, &zambiesGame::listenServerZ);
     listen->start(500);

}

zambiesGame::~zambiesGame()
{
    delete ui;
}

void zambiesGame::on_pushButtonC1_clicked()
{

    if(Branis >= 100)
     {    zamby=11;
        Branis=Branis-100;
        ui->textEdit->setText(QString::number(Branis));
    }
    else
        zamby =0;
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

    if(Branis >= 200)
    {    zamby=12;
       Branis=Branis-200;
       ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::on_pushButtonC3_clicked()
{
    if(Branis >= 150)
    {    zamby=13;
       Branis=Branis-150;
       ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::on_pushButtonC4_clicked()
{
    if(Branis >= 150)
    {    zamby=14;
       Branis=Branis-150;
       ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::on_pushButtonC5_clicked()
{
    if(Branis >= 200)
    {    zamby=15;
       Branis=Branis-200;
        ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::on_pushButtonC6_clicked()
{
    if(Branis >= 800)
    {    zamby=16;
       Branis=Branis-800;
       ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::generateRandomNumberZ() {
    locBrain = 37 + std::rand() % 36; // Generates a number between 37 and 72
    QString buttonName = QString("pushButtonB%1").arg(locBrain);
    QPushButton *button = findChild<QPushButton *>(buttonName);
    if (button) {
        QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Brain.png";
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

void zambiesGame::handleButtonClick() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonName = QString("pushButtonB%1").arg(locBrain);
        if (button->objectName() == buttonName) {
            Branis += 25;
        ui->textEdit->setText(QString::number(Branis));
            button->setStyleSheet("QPushButton { "
                                  "    background-color: rgba(255, 255, 255, 0); "
                                  "    border: none; "
                                  "}");
       }
    }
}
void zambiesGame::on_pushButton_67_clicked()
{
    if (zamby != 0 && gameMap[67] == 0) {
        gameLogicHandlerZ.createZombie(zamby, 67);

        QString s = QString::number(zamby);
        QByteArray data = "g+" + s.toUtf8() + "+67";

        if (clientS->state() == QAbstractSocket::ConnectedState) {
            qDebug() << "Attempting to write data to socket...";
            clientS->write(data);
            if (clientS->waitForBytesWritten(5000)) {  // Wait up to 5 seconds
                qDebug() << "Data written to socket.";
            } else {
                qDebug() << "Failed to write data to socket:" << clientS->errorString();
            }
        } else {
            qDebug() << "Socket is not connected!";
        }

        zamby = 0;
    }
}


void zambiesGame::on_pushButton_68_clicked()
{
    if ( zamby!=0&&gameMap[68] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 68);
         QString s = QString::number(zamby);
        QByteArray data="g+"+s.toUtf8() +"+68";
        clientS->write(data);
    zamby=0;
    }
}


void zambiesGame::on_pushButton_69_clicked()
{
    if (zamby!=0&& gameMap[69] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 69);
         QString s = QString::number(zamby);
        QByteArray data="g+"+s.toUtf8() +"+69";
        clientS->write(data);
             zamby=0;
    }
}

void zambiesGame::on_pushButton_70_clicked()
{
    if (zamby!=0&& gameMap[70] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 70);
         QString s = QString::number(zamby);
        QByteArray data="g+"+s.toUtf8() +"+70";
        clientS->write(data);
    zamby=0;
    }
}


void zambiesGame::on_pushButton_71_clicked()
{
    if (zamby!=0&& gameMap[71] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 71);
         QString s = QString::number(zamby);
        QByteArray data="g+"+s.toUtf8() +"+71";
        clientS->write(data);
    zamby=0;
    }
}


void zambiesGame::on_pushButton_72_clicked()
{
    if (zamby!=0&& gameMap[72] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 72);
         QString s = QString::number(zamby);
        QByteArray data="g+"+s.toUtf8() +"+72";
        clientS->write(data);
         zamby=0;

    }
}
void zambiesGame::showMapZ()
{
    if (gameLogicHandlerZ.winner == 1) {
         timer2->stop();
         this->hide();
         ForgotWindow* FWindow= new ForgotWindow();
         FWindow->show();
         qDebug() << "Timer stopped because winner == 1";
         return; // Exit the function to avoid further processing
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


void zambiesGame:: listenServerZ(){
    QByteArray data = clientS->readAll();
    QString str(data);
    QStringList usAndps= str.split('+');
    if (usAndps.size() >= 3) {
        bool ok1, ok2;
        int value1 = usAndps[1].toInt(&ok1);
        int value2 = usAndps[2].toInt(&ok2);

        if (ok1 && ok2) {
            gameLogicHandlerZ.createPlant(value1, value2);
        }
    }
}

//void zambiesGame::onGameTimerTimeout()
//{
  //  if (gameLogicHandlerZ.winner != -1)
    //{
      //  gameLogicHandlerZ.winner = 0;
        //qDebug() << "plants win!";
    //}
//
    //qDebug() << "Zombie wins!";
//
  //  this->hide();
    //gameTimer->stop();
//}
