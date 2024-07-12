#ifndef GAMELOGICHANDLING_H
#define GAMELOGICHANDLING_H

#include <QWidget>
#include <QThread>
#include <QList>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
#include <QCoreApplication>

#include <QMutex>

#include "globals.h"
#include "astronautzombie.h"
#include "boomerangplant.h"
#include "bucketheadzombie.h"
#include "jalapeno.h"
#include "leafheadzombie.h"
#include "peashooterplant.h"
#include "plummineplant.h"
#include "purplehairzombie.h"
#include "regularzombie.h"
#include "tallzombie.h"
#include "twopeashooterplant.h"
#include "walnutplant.h"
#include "zombie.h"
#include "plant.h"

class GameLogicHandling : public QWidget
{
    Q_OBJECT
public:
    explicit GameLogicHandling(QWidget *parent = nullptr);
    ~GameLogicHandling();
    int winner = -1;//1 -> zombie , 0 -> plant

    void createZombie(int iid, int position);
    void createPlant(int iid, int position);

    void wait(int milliseconds);
    void delay(int milliseconds);

signals:
    void gameStateUpdated();

private:
    QMap<int, Zombie*> zombieMap; // ID, Zombie*
    QMap<int, Plant*> plantMap; // ID, Plant*
    QList<QThread*> threads;
    QMutex mutex;


    void initializeMap();
    void moveAndAttack(Zombie *zombie, int position);
    void plantAttack(Plant *plant, int position);
    void updateMap(int position, int id);
    void checkWinningCondition();
    void plumExplode(int position);
    void jalapenoExplode(int position);
};

#endif // GAMELOGICHANDLING_H
