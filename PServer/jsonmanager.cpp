#include "jsonmanager.h"

JsonManager::JsonManager(const QString &file_path) : filePath(file_path) {}

JsonManager::JsonManager(const QString &history_path, int i)
{
    historyPath = history_path + ".json";
}

void JsonManager::addHistory(const UserHistory &history)
{
    arrayOfHistories.append(history);
}

QVector<UserHistory> JsonManager::getHistory()
{
    return arrayOfHistories;
}

void JsonManager::addUsers(const Users &user)
{
    arrayOfUsers.append(user);
}

QVector<Users> JsonManager::getUsers()
{
    return arrayOfUsers;
}

void JsonManager::saveHistoryData()
{
    QJsonArray jsonArray;
    for (const UserHistory &history : arrayOfHistories)
    {
        jsonArray.append(history.toJson());
    }
    QJsonDocument jsonDoc(jsonArray);
    QFile file(historyPath);

    file.open(QIODevice::WriteOnly);
    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();
}

void JsonManager::loadHistoryData()
{
    QFile file(historyPath);

    file.open(QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    QJsonArray jsonArray = jsonDoc.array();
    arrayOfHistories.clear();

    for (const QJsonValue &value : jsonArray)
    {
        if (value.isObject())
        {
            UserHistory history;
            history.fromJson(value.toObject());
            arrayOfHistories.append(history);
        }
     }
}

void JsonManager::saveData()
{
    QJsonArray jsonArray;
    for (const Users &user : arrayOfUsers) {
        jsonArray.append(user.toJson());
    }
    QJsonDocument jsonDoc(jsonArray);
    QFile file(filePath);

    file.open(QIODevice::WriteOnly);

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();
}

void JsonManager::loadData()
{
    QFile file(filePath);

    file.open(QIODevice::ReadOnly);
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
