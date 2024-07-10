#include "mainwindow.h"
#include"mainwindow2.h"
#include "plants.h"
#include "zambiesgame.h"
#include <QApplication>
#include "signupwindow.h"
#include "loginwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //plants p;
   //p.show();
    zambiesGame w;
    w.show();
       // Create a QTimer for periodic printing
       QTimer timer;
       QObject::connect(&timer, &QTimer::timeout, []() {
           // Print map values from key 1 to 72

               qDebug() << "Map key:" << 1 << "Value:" << gameMap.value(1);
                 qDebug() << "Map key:" << 2 << "Value:" << gameMap.value(2);

       });
       timer.start(3000);
    //plants p;
    //p.show();
    //MainWindow w;
   // w.show();
  //  SignUpWindow l;
   // l.show();
  // LoginWindow d;
  // d.show();

    return a.exec();
}
