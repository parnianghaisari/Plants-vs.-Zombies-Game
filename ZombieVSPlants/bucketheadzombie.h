#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H

#include "zombie.h"

class BucketHeadZombie : public Zombie
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit BucketHeadZombie(QObject *parent = nullptr);

signals:

};

#endif // BUCKETHEADZOMBIE_H
