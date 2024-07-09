#include "regularzombie.h"

int RegularZombie::id = 11000;

RegularZombie::RegularZombie(QObject *parent) : Zombie(id, 500, 1, 25, 1, 100, parent)
{
    id++;
}
