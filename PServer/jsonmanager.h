#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QVector>
#include "users.h"


class JsonManager
{
    QString filePath;
    QVector<Users> arrayOfUsers;
public:
    JsonManager(const QString &file_path);
    void addUsers(const Users &user);
    QVector<Users> getUsers();

    void saveData();
    void loadData();
};

#endif // JSONMANAGER_H
