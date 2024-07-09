#ifndef TALLZOMBIE_H
#define TALLZOMBIE_H

#include "zombie.h"

class TallZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit TallZombie(QObject *parent = nullptr);

signals:

};

#endif // TALLZOMBIE_H
