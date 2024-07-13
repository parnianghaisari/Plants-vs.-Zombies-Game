#include "gamelogichandling.h"
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QThread>

GameLogicHandling::GameLogicHandling(QWidget *parent)
    : QWidget{parent}
{
    initializeMap();
    connect(this, &GameLogicHandling::cleanupZombieSignal, this, &GameLogicHandling::cleanupZombie);
}

GameLogicHandling::~GameLogicHandling()
{
    for (QThread *thread : threads) {
        thread->quit();  // Request thread to exit event loop

        // Wait for thread to exit (with a timeout)
        if (!thread->wait(5000)) {
            qWarning() << "Thread did not exit gracefully. Terminating...";
            thread->terminate();  // Terminate forcibly if it didn't exit
            thread->wait();  // Wait for termination
        }

        // Delete the thread once it's finished
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

        zombieMap.insert(zombie->getName(), zombie);
        updateMap(position, zombie->getName());
        mutex.lock();
        bornZombies.insert(position, zombie->getName());
        qDebug() << bornZombies.size() << "LOGICCCC";
        mutex.unlock();
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

        plantMap.insert(plant->name, plant);
        updateMap(position, plant->name);
        mutex.lock();
        bornPlants.insert(position, plant->name);
        mutex.unlock();
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

void GameLogicHandling::delay(int milliseconds)
{
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void GameLogicHandling::moveAndAttack(Zombie *zombie, int position)
{
    int newPosition = position - 6;
    int count1 = 0;
    while (zombie->getHealth() > 0) {
        if (!gameMap[newPosition])
        {
            delay(zombie->getDelay() * 2000);
            mutex.lock();
            if (zombie->getHealth() <= 0)
            {
                updateMap(position, 0);
                cleanupZombie(zombie);
                mutex.unlock();  // Unlock mutex before returning
                return; // Exit thread if zombie is dead
            }

            updateMap(position, 0); // Clear the old position
            beforeMoving.insert(position, zombie->getName());
            position = newPosition;
            mutex.unlock();
            if (newPosition > 0) { // Check bounds
                updateMap(newPosition, zombie->getName());
            } else {
                winner = 1;
                mutex.unlock();  // Unlock mutex before breaking
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

        delay(zombie->getTime() * 2000);

        if (gameMap[newPosition] >= 20000) { // Assuming IDs >= 20000 represent plants
            int plantID = gameMap[newPosition];
            mutex.lock();  // Lock mutex before accessing plantMap
            Plant *plant = plantMap[plantID];
            if (plant) {
                plant->health -= zombie->getPower();
                if (plant->health <= 0) {
                    updateMap(newPosition, 0); // Plant dies
                    deadPlants.append(newPosition);
                    plantMap.remove(plantID);
                    delete plant;
                    mutex.unlock();
                }
            }
        }

        ++count1;
    }
}

void GameLogicHandling::plantAttack(Plant *plant, int position)
{
    while (plant->health > 0) {
            delay(plant->firingRate * 3000);
            for (int i = position; i <= 72; i += 6) {
                if (gameMap[i] <= 20000 && gameMap[i] >= 11000) {
                    mutex.lock();
                    int zombieID = gameMap[i];
                    qDebug() << "Attempting to find zombie with ID:" << zombieID;


                    if (zombieMap.contains(zombieID)) {
                        Zombie *zombie = zombieMap[zombieID];
                        qDebug() << "Found zombie:" << zombie->getName() << "with health:" << zombie->getHealth();

                        zombie->changeHealth(zombie->getHealth() - plant->health);
                        if (zombie->getHealth() <= 0) {
                            updateMap(i, 0); // Zombie dies
                            qDebug() << "Zombie died at position:" << i;
                            auto it = beforeMoving.find(zombie->getName());
                            if (it != beforeMoving.end()) {
                                beforeMoving.erase(it);
                            }
                            deadZombies.append(i);
                        }
                        mutex.unlock();  // Unlock mutex after accessing zombieMap
                    } else {
                        qDebug() << "Zombie with ID:" << zombieID << "not found in zombieMap";
                        mutex.unlock();
                    }
                }
            }
        }

        if (!plant->health)
        {
            if (plant->name / 1000 == 24) {
                wait(1000);
                plumExplode(position);
                mutex.lock();
                updateMap(position, 0);
                deadPlants.append(position);
                plantMap.remove(plant->name);
                delete plant;
                mutex.unlock();
            } else {
                wait(1000);
                jalapenoExplode(position);
                mutex.lock();
                updateMap(position, 0);
                deadPlants.append(position);
                plantMap.remove(plant->name);
                delete plant;
                mutex.unlock();
            }
        }



}

void GameLogicHandling::updateMap(int position, int id)
{
    if (!id || (id >= 11000 && id <= 30000) )
    {
    gameMap[position] = id;
    emit gameStateUpdated();
    qDebug() << "Updated position" << position << "with ID" << id;
    }
}

void GameLogicHandling::plumExplode(int position)
{
    int loc = position - 14;
    for (int c = 0; c < 5; ++c) {
        for (int i = loc; i <= loc + 24; i += 6)
            if (i > 0 && i < 73 && i != position)
                if (gameMap[i] < 20000 && gameMap[i]) {
                    int zombieID = gameMap[i];
                    qDebug() << zombieID;
                    Zombie *zombie = zombieMap[zombieID];
                    qDebug() << zombie->getHealth() << zombie->getName();
                    zombie->changeHealth(zombie->getHealth() - 500);
                    if (zombie->getHealth() <= 0) {
                        mutex.lock();
                        updateMap(i, 0); // Zombie dies
                        mutex.unlock();
                        auto it = beforeMoving.find(zombie->getName());
                        if (it == beforeMoving.end())
                            deadZombies.append(i);
                        else {
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
    int loc = position % 6;
    if (!loc)
        loc += 6;
    for (int i = loc; i <= 72; ++i)
        if (gameMap[i] < 20000 && gameMap[i]) {
            Zombie *zombie = zombieMap[i];
            zombie->changeHealth(zombie->getHealth() - 300);
            if (zombie->getHealth() <= 0) {
                mutex.lock();
                updateMap(i, 0); // Zombie dies
                mutex.unlock();
                auto it = beforeMoving.find(i);
                if (it == beforeMoving.end())
                    deadZombies.append(i);
                else {
                    beforeMoving.erase(it);
                    deadZombies.append(i);
                }
            }
        }
}

void GameLogicHandling::cleanupZombie(Zombie *zombie)
{
    if (zombie)
    {
        qDebug() << "Cleaning up zombie:" << zombie->getName();

        zombieMap.remove(zombie->getName());

        // Delete the zombie object itself
        delete zombie;

        // Get the thread associated with the zombie
}
}
