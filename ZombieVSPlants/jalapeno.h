#ifndef JALAPENO_H
#define JALAPENO_H

#include "plant.h"

class Jalapeno : public Plant
{
    Q_OBJECT

protected:
    static int id;
public:
    explicit Jalapeno(QObject *parent = nullptr);

signals:

};

#endif // JALAPENO_H
