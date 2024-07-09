#include "peashooterplant.h"

int PeashooterPlant::id = 21000;

PeashooterPlant::PeashooterPlant(QObject *parent) : Plant(id, 200, 15, 1, 50, parent)
{
    id++;
}
