#include "jsonmanager.h"

JsonManager::JsonManager(const QString &file_path) : filePath(file_path) {}

JsonManager::JsonManager(const QString &history_path, int i)
{
    historyPath = history_path + ".json";
    aux = i;
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
        for (const UserHistory &history : arrayOfHistories) {
            jsonArray.append(history.toJson());
        }
        QJsonDocument jsonDoc(jsonArray);
        QFile file(historyPath);

        if (!file.open(QIODevice::WriteOnly)) {
            qWarning() << "Could not open file for writing:" << historyPath;
            return;
        }

        file.write(jsonDoc.toJson(QJsonDocument::Indented));
        file.close();
}

void JsonManager::loadHistoryData()
{
    QFile file(historyPath);

        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Could not open file for reading:" << historyPath;
            return;
        }

        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

        if (jsonDoc.isNull() || !jsonDoc.isArray()) {
            qWarning() << "Invalid JSON format in file:" << historyPath;
            return;
        }

        QJsonArray jsonArray = jsonDoc.array();
        arrayOfHistories.clear();

        for (const QJsonValue &value : jsonArray) {
            if (value.isObject()) {
                UserHistory history;
                history.fromJson(value.toObject());
                arrayOfHistories.append(history);
            }
        }
}

void JsonManager::saveData()
{
    qDebug() << "Saving data to file:" << filePath;
    QJsonArray jsonArray;
    for (const Users &user : arrayOfUsers) {
        jsonArray.append(user.toJson());
    }

    qDebug() << "JSON array to save:" << jsonArray;

    QJsonDocument jsonDoc(jsonArray);
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for writing:" << filePath;
        return;
    }

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();
    qDebug() << "Data saved successfully.";
}

void JsonManager::loadData()
{
    qDebug() << "Loading data from file:" << filePath;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file for reading:" << filePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();
    arrayOfUsers.clear();

    for (const QJsonValue &value : jsonArray) {
        if (value.isObject()) {
            Users user;
            user.fromJson(value.toObject());
            arrayOfUsers.append(user);
        }
    }
    qDebug() << "Data loaded successfully.";
}
