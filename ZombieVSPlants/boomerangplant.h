#ifndef BOOMERANGPLANT_H
#define BOOMERANGPLANT_H

#include "plant.h"

class BoomerangPlant : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit BoomerangPlant(QObject *parent = nullptr);

signals:

};

#endif // BOOMERANGPLANT_H
