#ifndef WALNUTPLANT_H
#define WALNUTPLANT_H

#include "plant.h"

class WalnutPlant : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit WalnutPlant(QObject *parent = nullptr);

signals:

};

#endif // WALNUTPLANT_H
