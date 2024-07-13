#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include <QThread>

class Zombie : public QObject {
    Q_OBJECT

protected:
    int name;
    int health;
    double movementDelay;
    int powerAttack;
    double timeBetweenAttack;
    int brainVal;
public:
    explicit Zombie(int _name, int _health, double _movementDelay, int _powerAttack, double _timeBetweenAttack, int _brainVal, QObject *parent = nullptr);
    virtual ~Zombie();

    int getName();
    int getHealth();
    double getDelay();
    int getPower();
    double getTime();
    int getBrain();

    void changeHealth(int _health);


signals:
        void zombieDied();
};

#endif // ZOMBIE_H
