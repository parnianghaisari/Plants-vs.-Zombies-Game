#include "users.h"

Users::Users()
{
    UserName = "";
    PSW = "";
    PNumber = "";
    Email = "";
    Name = "";
    Family = "";
}

QJsonObject Users::toJson() const
{
    QJsonObject json;
    json["username"] = UserName;
    json["phoneNumber"] = PNumber;
    json["password"] = PSW;
    json["name"] = Name;
    json["family"] = Family;
    json["email"] = Email;
    return json;
}

void Users::fromJson(const QJsonObject &json)
{
    UserName = json["username"].toString();
    PNumber = json["phoneNumber"].toString();
    PSW = json["password"].toString();
    Name = json["name"].toString();
    Family = json["famili"].toString();
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

QString &Users::familyVal()
{
    return Family;
}

QString &Users::emailVal()
{
    return Email;
}
