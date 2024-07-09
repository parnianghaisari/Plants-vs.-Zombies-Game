#ifndef TWOPEASHOOTERPLANT_H
#define TWOPEASHOOTERPLANT_H

#include "plant.h"

class TwoPeashooterPlant : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit TwoPeashooterPlant(QObject *parent = nullptr);

signals:

};

#endif // TWOPEASHOOTERPLANT_H
