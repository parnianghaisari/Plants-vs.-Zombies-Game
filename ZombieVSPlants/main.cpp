#include "mainwindow.h"
#include"mainwindow2.h"
#include "plants.h"
#include "zambiesgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  plants p;
  //  p.show();
    zambiesGame w;
    w.show();
    //MainWindow w;
   // w.show();
    return a.exec();
}
