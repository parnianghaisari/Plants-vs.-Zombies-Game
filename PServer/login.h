#ifndef LOGIN_H
#define LOGIN_H

#include "jsonmanager.h"

class Login
{
public:
    Login();
    QString matchPSW(QString us, QString ps);
    QString matchPN(QString us, QString pn);
    void changePSW(QString us, QString Nps);
};

#endif // LOGIN_H
