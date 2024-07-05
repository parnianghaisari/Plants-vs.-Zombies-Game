#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QJsonObject>

class Users
{
public:
    Users();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &json);

    QString& userVal();
    QString& pswVal();
    QString& numberVal();
    QString& nameVal();
    QString& familyVal();
    QString& emailVal();

private:
    QString UserName;
    QString PSW;
    QString PNumber;
    QString Name;
    QString Email;
    QString Family;
};

#endif // USERS_H
