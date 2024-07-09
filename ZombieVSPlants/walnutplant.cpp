#include "walnutplant.h"

int WalnutPlant::id = 23000;

WalnutPlant::WalnutPlant(QObject *parent) : Plant(id, 400, 0, 0, 100, parent)
{
    id++;
}
