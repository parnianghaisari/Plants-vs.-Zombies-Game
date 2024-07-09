#include "plant.h"

Plant::Plant(int _name, int _health, int _attackPower, int _firingRate, int _sunVal, QObject *parent) :  QObject(parent), name(_name), health(_health), attackPower(_attackPower), firingRate(_firingRate), sunVal(_sunVal) {}

Plant::~Plant() {}
