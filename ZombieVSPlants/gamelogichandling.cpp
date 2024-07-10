#include "gamelogichandling.h"
#include <QDebug>

GameLogicHandling::GameLogicHandling(QWidget *parent)
    : QWidget{parent}
{
    initializeMap();
}

GameLogicHandling::~GameLogicHandling()
{
    for (QThread *thread : threads) {
        thread->quit();
        thread->wait();
        delete thread;
    }

    for (auto zombie : zombieMap) {
        delete zombie;
    }

    for (auto plant : plantMap) {
        delete plant;
    }
}

void GameLogicHandling::initializeMap()
{
    for (int i = 1; i < 73; ++i)
        gameMap.insert(i, 0);
}

void GameLogicHandling::createZombie(int iid, int position)
{
    if(position <= 72 && position >= 67 && !gameMap[position])
    {
        Zombie *zombie = nullptr;
        if(iid == 11)
            zombie = new RegularZombie;
        else if (iid == 12)
            zombie = new BucketHeadZombie;
        else if (iid == 13)
            zombie = new LeafHeadZombie;
        else if (iid == 14)
            zombie = new TallZombie;
        else if (iid == 15)
            zombie = new AstronautZombie;
        else
            zombie = new PurpleHairZombie;
        zombieMap[iid] = zombie;
        updateMap(position, zombie->getName());

        QThread *thread = new QThread;
        threads.append(thread);
        zombie->moveToThread(thread);

        connect(thread, &QThread::started, [this, zombie, position]() { moveAndAttack(zombie, position); });
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }
}

void GameLogicHandling::createPlant(int iid, int position)
{
    if(position <= 72 && position >= 67 && !gameMap[position])
    {
        Plant *plant = nullptr;
        if(iid == 21)
            plant = new PeashooterPlant;
        else if (iid == 22)
            plant = new TwoPeashooterPlant;
        else if (iid == 23)
            plant = new WalnutPlant;
        else if (iid == 24)
            plant = new PlumMinePlant;
        else if (iid == 25)
            plant = new Jalapeno;
        else
            plant = new BoomerangPlant;
        plantMap[iid] = plant;
        plantMap[iid] = plant;
        updateMap(position, iid);

        QThread *thread = new QThread;
        threads.append(thread);
        plant->moveToThread(thread);

        connect(thread, &QThread::started, [this, plant, position]() { plantAttack(plant, position); });
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }
}

void GameLogicHandling::moveAndAttack(Zombie *zombie, int position)
{
    int newPosition = position -6;
    int count = 0;
    int count1 = 0;
    while (zombie->getHealth() > 0) {

        if (!gameMap[newPosition])
        {
            if (zombie->getName()/1000 == 15 && !count)
                QThread::sleep(1);
            else
                QThread::sleep(zombie->getDelay());

            gameMap[position] = 0; // Clear the old position

            position = newPosition;

            if (newPosition > 0) { // Check bounds
                updateMap(newPosition, zombie->getName());
            } else {
                winner = 1;
                break; // Exit loop if out of bounds
            }
            ++count;
            newPosition -= 6;
            continue;
        }
        if (newPosition <= 0)
        {
            winner = 1;
            break;
        }

        if (zombie->getName()/1000 == 15 && !count1)
            QThread::sleep(1);
        else
            QThread::sleep(zombie->getTime());

        if (gameMap[newPosition] >= 20000) { // Assuming IDs >= 10000 represent plants
            int plantID = gameMap[newPosition];
            Plant *plant = plantMap[plantID];
            plant->health -= zombie->getPower();
            if (plant->health <= 0) {
                updateMap(newPosition, 0); // Plant dies
                plantMap.remove(plantID);
                delete plant;
            }
        }

        ++count1;

    }

}

void GameLogicHandling::plantAttack(Plant *plant, int position)
{
    while(plant->health > 0)
    {
        QThread::sleep(plant->firingRate);
        for (int i = position; i <= 72; i += 6)
            if (gameMap[i] <= 20000 && gameMap[i])
            {
                int zombieID = gameMap[i];
                Zombie *zombie = zombieMap[zombieID];
                zombie->getHealth() -= plant->health;
                if (zombie->getHealth() <= 0)
                {
                    updateMap(i, 0); //zombie die o ina
                    zombieMap.remove(zombieID);
                    delete zombie;
                }
            }
    }
    if (plant->name/1000 == 24)
    {
        plumExplode(position);
    }
    else if (plant->name/1000 == 25)
        jalapenoExplode(position);
}

void GameLogicHandling::updateMap(int position, int id)
{
    gameMap[position] = id;
    qDebug() << "Updated position" << position << "with ID" << id;
}

void GameLogicHandling::plumExplode(int position)
{
    int loc = position - 12;
    if (loc > 0 && loc <73)
        if (gameMap[loc] < 20000 && gameMap[loc])
        {
            int zombieID = gameMap[loc];
            Zombie *zombie = zombieMap[zombieID];
            zombie->getHealth() -= 500;
            if (zombie->getHealth() <= 0)
            {
                updateMap(loc, 0); //zombie die o ina
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
    loc += 6;
    if (loc > 0 && loc < 73)
        if (gameMap[loc] < 20000 && gameMap[loc])
        {
            int zombieID = gameMap[loc];
            Zombie *zombie = zombieMap[zombieID];
            zombie->getHealth() -= 500;
            if (zombie->getHealth() <= 0)
            {
                updateMap(loc, 0); //zombie die o ina
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
    loc += 12;
    if (loc > 0 && loc < 73)
        if (gameMap[loc] < 20000 && gameMap[loc])
        {
            int zombieID = gameMap[loc];
            Zombie *zombie = zombieMap[zombieID];
            zombie->getHealth() -= 500;
            if (zombie->getHealth() <= 0)
            {
                updateMap(loc, 0); //zombie die o ina
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
    loc += 6;
    if (loc > 0 && loc < 73)
        if (gameMap[loc] < 20000 && gameMap[loc])
        {
            int zombieID = gameMap[loc];
            Zombie *zombie = zombieMap[zombieID];
            zombie->getHealth() -= 500;
            if (zombie->getHealth() <= 0)
            {
                updateMap(loc, 0); //zombie die o ina
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
}

void GameLogicHandling::jalapenoExplode(int position)
{
    int loc = position%6;
    if (!loc)
        loc += 6;
    for (int i = loc; i <= 72; ++i)
        if (gameMap[i] < 20000 && gameMap[i])
        {
            int zombieID = gameMap[i];
            Zombie *zombie = zombieMap[i];
            zombie->getHealth() -= 500;
            if (zombie->getHealth() <= 0)
            {
                updateMap(loc, 0); //zombie die o ina
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
}
