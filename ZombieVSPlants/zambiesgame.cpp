#include "zambiesgame.h"
#include "ui_zambiesgame.h"
#include"loginwindow.h"
zambiesGame::zambiesGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zambiesGame),
      //gameTimer(new QTimer(this)),
      clients(new QTcpSocket(this)),
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
    // timer2 = new QTimer(this);
    // connect(timer2, &QTimer::timeout, this, &zambiesGame::showMapZ);
     //timer2->start(200);
     //listen = new QTimer(this);
     //connect(timer, &QTimer::timeout, this, &zambiesGame::listenServerZ);
     //listen->start(200);
    connect(clientS, &QTcpSocket::readyRead, this, &zambiesGame::listenServerZ);
    connect(&gameLogicHandlerZ, &GameLogicHandling::gameStateUpdated, this, &zambiesGame::showMapZ);

       clientS->connectToHost(hostId, 2025);

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

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+67";

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
    if (zamby != 0 && gameMap[68] == 0) {

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+68";

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


void zambiesGame::on_pushButton_69_clicked()
{
    if (zamby != 0 && gameMap[69] == 0) {

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+69";

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

void zambiesGame::on_pushButton_70_clicked()
{
    if (zamby != 0 && gameMap[70] == 0) {

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+70";

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


void zambiesGame::on_pushButton_71_clicked()
{
    if (zamby != 0 && gameMap[71] == 0) {

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+71";

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


void zambiesGame::on_pushButton_72_clicked()
{
    if (zamby != 0 && gameMap[72] == 0) {

        QString s = QString::number(zamby);
        QByteArray data = "z+" + s.toUtf8() + "+72";

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
           beforeMoving.clear();
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
    deadPlants.clear();
    qDebug()<<"3";
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


}


void zambiesGame::listenServerZ() {
    QByteArray data = clientS->readAll();
    QString str(data);
    QStringList parts = str.split('+');
    if (parts.size() >= 3) {
        QString command = parts[0];
        int id = parts[1].toInt();
        int position = parts[2].toInt();

        if (command=='z') { // Zombie
            gameLogicHandlerZ.createZombie(id, position);
        } else if(command =='p')  { // Plant
            gameLogicHandlerZ.createPlant(id, position);
        }

        showMapZ();
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
