#include "leafheadzombie.h"

int LeafHeadZombie::id = 13000;

LeafHeadZombie::LeafHeadZombie(QObject *parent) : Zombie(id, 800, 1, 25, 1, 150, parent)
{
    id++;
}
