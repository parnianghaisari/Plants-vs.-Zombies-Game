#include "purplehairzombie.h"

int PurpleHairZombie::id = 16000;

PurpleHairZombie::PurpleHairZombie(QObject *parent) : Zombie(id, 4000, 1, 75, 0.5, 800, parent)
{
    id++;
}
