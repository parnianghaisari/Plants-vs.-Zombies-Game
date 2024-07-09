#ifndef LEAFHEADZOMBIE_H
#define LEAFHEADZOMBIE_H

#include "zombie.h"

class LeafHeadZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit LeafHeadZombie(QObject *parent = nullptr);

signals:

};

#endif // LEAFHEADZOMBIE_H
