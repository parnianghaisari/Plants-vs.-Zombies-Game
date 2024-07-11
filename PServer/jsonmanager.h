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
#include "userhistory.h"

class JsonManager
{
    QString filePath;
    QString historyPath;
    QVector<Users> arrayOfUsers;
    QVector<UserHistory> arrayOfHistories;
    int aux;
public:
    JsonManager(const QString &file_path);
    JsonManager(const QString &history_path, int i);

    void addHistory(const UserHistory &history);
    QVector<UserHistory> getHistory();

    void addUsers(const Users &user);
    QVector<Users> getUsers();

    void saveHistoryData();
    void loadHistoryData();

    void saveData();
    void loadData();
};

#endif // JSONMANAGER_H
