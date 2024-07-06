#include "users.h"

Users::Users()
{
    UserName = "";
    PSW = "";
    PNumber = "";
    Email = "";
    Name = "";
}

Users::Users(QString name, QString us, QString ps, QString em, QString num)
{
    UserName = us;
    PSW = ps;
    PNumber = num;
    Name = name;
    Email = em;
}

QJsonObject Users::toJson() const
{
    QJsonObject json;
    json["username"] = UserName;
    json["phoneNumber"] = PNumber;
    json["password"] = PSW;
    json["name"] = Name;
    json["email"] = Email;
    return json;
}

void Users::fromJson(const QJsonObject &json)
{
    UserName = json["username"].toString();
    PNumber = json["phoneNumber"].toString();
    PSW = json["password"].toString();
    Name = json["name"].toString();
    Email = json["email"].toString();
}

QString &Users::userVal()
{
    return UserName;
}

QString &Users::pswVal()
{
    return PSW;
}

QString &Users::numberVal()
{
    return PNumber;
}

QString &Users::nameVal()
{
    return Name;
}


QString &Users::emailVal()
{
    return Email;
}
