#include "jalapeno.h"

int Jalapeno::id = 25000;

Jalapeno::Jalapeno(QObject *parent) : Plant(id, 0, 300, 0, 150, parent) {}
