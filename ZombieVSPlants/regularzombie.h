#ifndef REGULARZOMBIE_H
#define REGULARZOMBIE_H

#include "zombie.h"

class RegularZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit RegularZombie(QObject *parent = nullptr);

signals:

};

#endif // REGULARZOMBIE_H
