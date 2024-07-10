#ifndef GLOBALS_H
#define GLOBALS_H

#include<QTcpSocket>
#include <QHash>
#include <QMap>

extern QTcpSocket *clientS;
extern int zamby;
extern int plant;
extern int Branis;
extern int Suns;
extern QHash<int , int> gamehash;
void setVal();
#endif // GLOBALS_H
