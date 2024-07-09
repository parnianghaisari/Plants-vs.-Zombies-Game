#include "bucketheadzombie.h"

int BucketHeadZombie::id = 12000;

BucketHeadZombie::BucketHeadZombie(QObject *parent) : Zombie(id, 1950, 2, 50, 1, 200, parent)
{
    id++;
}
