#include "jsonmanager.h"

JsonManager::JsonManager(const QString &file_path) : filePath(file_path) {}

void JsonManager::addUsers(const Users &user)
{
    arrayOfUsers.append(user);
}

QVector<Users> JsonManager::getUsers()
{
    return arrayOfUsers;
}

void JsonManager::saveData()
{
    QJsonArray jsonArray;
        for (const Users &user : arrayOfUsers) {
            jsonArray.append(user.toJson());
        }

        QJsonDocument jsonDoc(jsonArray);
        QFile file(filePath);

        file.write(jsonDoc.toJson());
        file.close();
}

void JsonManager::loadData()
{
    QFile file(filePath);

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    QJsonArray jsonArray = jsonDoc.array();
    arrayOfUsers.clear();

    for (const QJsonValue &value : jsonArray)
    {
        if (value.isObject())
        {
            Users user;
            user.fromJson(value.toObject());
            arrayOfUsers.append(user);
        }
     }
}
