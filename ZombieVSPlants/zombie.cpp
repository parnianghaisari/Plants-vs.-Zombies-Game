#include "zombie.h"

#include <QDebug>

Zombie::Zombie(int _name, int _health, double _movementDelay, int _powerAttack, double _timeBetweenAttack, int _brainVal, QObject *parent) : QObject(parent), name(_name), health(_health), movementDelay(_movementDelay), powerAttack(_powerAttack), timeBetweenAttack(_timeBetweenAttack), brainVal(_brainVal) {}

Zombie::~Zombie() {}

int Zombie::getName()
{
    return name;
}

int Zombie::getHealth()
{
    return health;
}

double Zombie::getDelay()
{
    return movementDelay;
}

int Zombie::getPower()
{
    return powerAttack;
}

double Zombie::getTime()
{
    return timeBetweenAttack;
}

int Zombie::getBrain()
{
    return brainVal;
}

void Zombie::changeHealth(int _health)
{
    health = _health;
}
