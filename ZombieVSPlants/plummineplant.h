#ifndef PLUMMINEPLANT_H
#define PLUMMINEPLANT_H

#include "plant.h"

class PlumMinePlant : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit PlumMinePlant(QObject *parent = nullptr);

signals:

};

#endif // PLUMMINEPLANT_H
