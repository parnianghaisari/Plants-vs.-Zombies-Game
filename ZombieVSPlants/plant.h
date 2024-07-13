#ifndef PLANT_H
#define PLANT_H

#include <QObject>

class Plant : public QObject {
    Q_OBJECT

public:
    explicit Plant(int _name, int _health, int _attackPower, int _firingRate, int _sunVal, QObject *parent = nullptr);
    virtual ~Plant();

    int name;
    int health;
    int attackPower;
    int firingRate;
    int sunVal;

signals:
    void plantDied();
};

#endif // PLANT_H
