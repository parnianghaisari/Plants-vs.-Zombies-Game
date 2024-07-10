#ifndef GLOBALS_H
#define GLOBALS_H

#include<QTcpSocket>
#include <QHash>
#include <QMap>
#include <QVector>

extern QTcpSocket *clientS;
extern int zamby;
extern int plant;
extern int Branis;
extern int Suns;
extern QHash<int , int> gamehash;
extern QMap<int, int> gameMap;
extern QMap<int, int> beforeMoving;
extern QVector<int> deadZombies;
extern QMap<int, int> bornZombies;
extern QVector<int> deadPlants;
extern QMap<int, int> bornPlants;
void setVal();
#endif // GLOBALS_H
