#ifndef PURPLEHAIRZOMBIE_H
#define PURPLEHAIRZOMBIE_H

#include "zombie.h"

class PurpleHairZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit PurpleHairZombie(QObject *parent = nullptr);

signals:

};

#endif // PURPLEHAIRZOMBIE_H
