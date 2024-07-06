#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QJsonObject>

class Users
{
public:
    Users();
    Users(QString name, QString us, QString ps, QString em, QString num);

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &json);

    QString& userVal();
    QString& pswVal();
    QString& numberVal();
    QString& nameVal();
    QString& emailVal();

private:
    QString UserName;
    QString PSW;
    QString PNumber;
    QString Name;
    QString Email;
};

#endif // USERS_H
