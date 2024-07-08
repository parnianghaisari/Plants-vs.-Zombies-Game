#include "zambiesgame.h"
#include "ui_zambiesgame.h"
#include"loginwindow.h"
zambiesGame::zambiesGame(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::zambiesGame),
      view(new QGraphicsView(this)),
      scene(new QGraphicsScene(this)),
      board(new Board(scene)) {

    ui->setupUi(this);

    // Set up the scene
    scene->setSceneRect(10, 20, 1212, 426);

    // Set up the view
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);

    // Set the main window layout
    setCentralWidget(view);
    setFixedSize(1232, 466);
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
