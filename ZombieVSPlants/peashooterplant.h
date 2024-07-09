#ifndef PEASHOOTERPLANT_H
#define PEASHOOTERPLANT_H

#include "plant.h"

class PeashooterPlant : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit PeashooterPlant(QObject *parent = nullptr);

signals:

};

#endif // PEASHOOTERPLANT_H
