#include "tallzombie.h"

int TallZombie::id = 14000;

TallZombie::TallZombie(QObject *parent) : Zombie(id, 500, 1, 30, 1, 150, parent)
{
    id++;
}
