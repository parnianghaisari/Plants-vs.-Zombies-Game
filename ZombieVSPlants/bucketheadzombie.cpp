#include "bucketheadzombie.h"

int id = 1200;

BucketHeadZombie::BucketHeadZombie(QObject *parent) : Zombie(id, 1950, 2, 50, 1, 200, parent)
{
    id++;
}
