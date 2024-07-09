#include "boomerangplant.h"

int id = 26000;

BoomerangPlant::BoomerangPlant(QObject *parent) : Plant(id, 200, 30, 1, 125, parent)
{
    id++;
}
