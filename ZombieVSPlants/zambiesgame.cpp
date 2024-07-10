#include "zambiesgame.h"
#include "ui_zambiesgame.h"
#include"loginwindow.h"
zambiesGame::zambiesGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zambiesGame),
     gameLogicHandlerZ(this)
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
    //    showMapZ(gameLogicHandlerZ.gameMap);


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

    if(Branis >= 150)
    {    zamby=13;
       Branis=Branis-150;
       ui->textEdit->setText(QString::number(Branis));
   }
    else
        zamby =0;
}


void zambiesGame::on_pushButtonC3_clicked()
{
    if(Branis >= 200)
    {    zamby=15;
       Branis=Branis-200;
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
    {    zamby=12;
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
void zambiesGame::putCard()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
     QString imagePath=" ";

    if(zamby ==11)
      {  imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/regular zombie.jpg";
       button->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                               "}");
       zamby=0;
    }
    if(zamby ==12)
    {   imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/leaf hair zombie.jpg";
       button->setStyleSheet("QPushButton { "
                             "    border-image: url(" + imagePath + ") stretch;"
                               "}");
        zamby=0;
    }
    if(zamby ==13)
     {
        imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/astronaut zombie.jpg";
              button->setStyleSheet("QPushButton { "
                                    "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
          zamby=0;

    }
    if(zamby ==14)
    {
       imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/tall zombie.jpg";
             button->setStyleSheet("QPushButton { "
                                   "    border-image: url(" + imagePath + ") stretch;"
                                     "}");
          zamby=0;

   }
    if(zamby ==15)
    {
       imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/Bucket head zombie.jpg";
             button->setStyleSheet("QPushButton { "
                                   "    border-image: url(" + imagePath + ") stretch;"
                                     "}");
          zamby=0;

   }
    if(zamby ==16)
    {
       imagePath="D:/AP_newPro/AP_project/ZombieVSPlants/purple hair zombie.jpg";
             button->setStyleSheet("QPushButton { "
                                   "    border-image: url(" + imagePath + ") stretch;"
                                     "}");
          zamby=0;

   }
}
void zambiesGame:: showMapZ(QMap<int , int> m){
    QString buttonName = QString("pushButtonB%1").arg(1);
    QPushButton *button = findChild<QPushButton *>(buttonName);
    for(int i=1 ; i<=72 ; i++){
        if(m[i]/1000 ==11){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/regular zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
         if(m[i]/1000 ==12){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/leaf hair zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
         if(m[i]/1000 ==13){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/astronaut zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
         if(m[i]/1000 ==14){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/tall zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
         if(m[i]/1000 ==15){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/Bucket head zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
         if(m[i]/1000 ==16){
            buttonName = QString("pushButton_%1").arg(i);
            button = findChild<QPushButton *>(buttonName);
            if (button) {
                QString imagePath = "D:/AP_newPro/AP_project/ZombieVSPlants/purple hair zombie.jpg";
                button->setStyleSheet("QPushButton { "
                                      "    border-image: url(" + imagePath + ") stretch;"
                                      "}");
        }
    }
}
}

void zambiesGame::on_pushButton_67_clicked()
{
    if ( gameLogicHandlerZ.gameMap[67] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 67);
         ui->textEdit->setText("hi");
        showMapZ( gameLogicHandlerZ.gameMap);
    }
}


void zambiesGame::on_pushButton_68_clicked()
{
    if ( gameLogicHandlerZ.gameMap[68] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 68);
    showMapZ( gameLogicHandlerZ.gameMap);
    }
}


void zambiesGame::on_pushButton_69_clicked()
{
    if ( gameLogicHandlerZ.gameMap[69] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 69);
    showMapZ( gameLogicHandlerZ.gameMap);
    }
}


void zambiesGame::on_pushButton_70_clicked()
{
    if ( gameLogicHandlerZ.gameMap[70] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 70);
    showMapZ( gameLogicHandlerZ.gameMap);
    }
}


void zambiesGame::on_pushButton_71_clicked()
{
    if ( gameLogicHandlerZ.gameMap[71] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 71);
    showMapZ( gameLogicHandlerZ.gameMap);
    }
}


void zambiesGame::on_pushButton_72_clicked()
{
    if ( gameLogicHandlerZ.gameMap[72] == 0) {
         gameLogicHandlerZ.createZombie(zamby, 72);
    showMapZ( gameLogicHandlerZ.gameMap);
    }
}

