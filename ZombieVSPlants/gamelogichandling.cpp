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

        bornZombies.insert(position, zombie->getName());

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
    if(position <= 36 && position >= 1 && !gameMap[position])
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
        updateMap(position, plant->name);

        bornPlants.insert(position, plant->name);

        QThread *thread = new QThread;
        threads.append(thread);
        plant->moveToThread(thread);

        connect(thread, &QThread::started, [this, plant, position]() { plantAttack(plant, position); });
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }
}

void GameLogicHandling::wait(int milliseconds)
{
    QElapsedTimer timer;
    timer.start();

   while (timer.elapsed() < milliseconds) {
       QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
   }
}

void GameLogicHandling::moveAndAttack(Zombie *zombie, int position)
{
    int newPosition = position - 6;
    int count1 = 0;
    while (zombie->getHealth() > 0) {

        if (!gameMap[newPosition])
        {
            if (zombie->getName()/1000 == 15 && position >= 67 && position <= 72)
                QThread::sleep(1 * 2);
            else
                QThread::sleep(zombie->getDelay() * 2);

            updateMap(position, 0); // Clear the old position

            beforeMoving.insert(position, zombie->getName());

            position = newPosition;

            if (newPosition > 0) { // Check bounds
                updateMap(newPosition, zombie->getName());
            } else {
                winner = 1;
                break; // Exit loop if out of bounds
            }
            newPosition -= 6;
            continue;
        }
        if (newPosition <= 0)
        {
            winner = 1;
            break;
        }

        if (zombie->getName()/1000 == 15 && !count1)
            QThread::sleep(1 * 2);
        else
            QThread::sleep(zombie->getTime() * 2);

        if (gameMap[newPosition] >= 20000) { // Assuming IDs >= 10000 represent plants
            int plantID = gameMap[newPosition];
            Plant *plant = plantMap[plantID];
            plant->health -= zombie->getPower();
            if (plant->health <= 0) {
                updateMap(newPosition, 0); // Plant dies
                deadPlants.append(newPosition);
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
        QThread::sleep(plant->firingRate * 2);
        for (int i = position; i <= 72; i += 6)
            if (gameMap[i] <= 20000 && gameMap[i] >= 11000)
            {
                int zombieID = gameMap[i];
                Zombie *zombie = zombieMap[zombieID];
                zombie->getHealth() -= plant->health;
                if (zombie->getHealth() <= 0)
                {
                    updateMap(i, 0); //zombie die o ina
                    auto it = beforeMoving.find(i);
                    if (it == beforeMoving.end())
                        deadZombies.append(i);
                    else
                    {
                        beforeMoving.erase(it);
                        deadZombies.append(i);
                    }
                    zombieMap.remove(zombieID);
                    delete zombie;
                }
            }
    }
    if (plant->name/1000 == 24)
    {
        wait(1000);
        plumExplode(position);
        updateMap(position, 0);
        deadPlants.append(position);
        plantMap.remove(plant->name);
        delete plant;
    }
    else
    {
        wait(1000);
        jalapenoExplode(position);
        updateMap(position, 0);
        deadPlants.append(position);
        plantMap.remove(plant->name);
        delete plant;
    }
}

void GameLogicHandling::updateMap(int position, int id)
{
    gameMap[position] = id;
    emit gameStateUpdated();
    qDebug() << "Updated position" << position << "with ID" << id;
}

void GameLogicHandling::plumExplode(int position)
{
    int loc = position - 14;
    for (int c = 0; c < 5; ++c)
    {
        for (int i = loc; i <= loc + 24; i += 6)
            if (i > 0 && i <73 && i != position)
                if (gameMap[i] < 20000 && gameMap[i])
                {
                    int zombieID = gameMap[i];
                    Zombie *zombie = zombieMap[zombieID];
                    zombie->getHealth() -= 500;
                    if (zombie->getHealth() <= 0)
                    {
                        updateMap(i, 0); //zombie die o ina
                        auto it = beforeMoving.find(i);
                        if (it == beforeMoving.end())
                            deadZombies.append(i);
                        else
                        {
                            beforeMoving.erase(it);
                            deadZombies.append(i);
                        }
                        zombieMap.remove(zombieID);
                        delete zombie;
                    }
                }
        ++loc;
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
                updateMap(i, 0); //zombie die o ina
                auto it = beforeMoving.find(i);
                if (it == beforeMoving.end())
                    deadZombies.append(i);
                else
                {
                    beforeMoving.erase(it);
                    deadZombies.append(i);
                }
                zombieMap.remove(zombieID);
                delete zombie;
            }
        }
}
