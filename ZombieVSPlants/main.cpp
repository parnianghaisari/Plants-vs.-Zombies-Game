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
   // plants p;
   // p.show();
   // zambiesGame w;
 // w.show();
    //plants p;
    //p.show();
    //MainWindow w;
   // w.show();
  //  SignUpWindow l;
    //l.show();
   LoginWindow d;
   d.show();

    return a.exec();
}
