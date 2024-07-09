#include "twopeashooterplant.h"

int TwoPeashooterPlant::id = 22000;

TwoPeashooterPlant::TwoPeashooterPlant(QObject *parent) : Plant(id, 200, 80, 1, 100, parent)
{
    id++;
}
