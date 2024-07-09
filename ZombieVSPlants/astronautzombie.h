#ifndef ASTRONAUTZOMBIE_H
#define ASTRONAUTZOMBIE_H

#include "zombie.h"

class AstronautZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit AstronautZombie(QObject *parent = nullptr);

signals:

};

#endif // ASTRONAUTZOMBIE_H
