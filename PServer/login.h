#ifndef LOGIN_H
#define LOGIN_H

#include "jsonmanager.h"

class Login
{
public:
    Login();
    QString matchPSW(QString us, QString ps);
    QString matchPN(QString us, QString pn);
};

#endif // LOGIN_H
