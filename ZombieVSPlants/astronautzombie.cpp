#include "astronautzombie.h"

int id = 1500;

AstronautZombie::AstronautZombie(QObject *parent) : Zombie(id, 500, 0.5, 20, 0.5, 200, parent)
{
    id++;
}
