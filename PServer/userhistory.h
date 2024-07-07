#ifndef USERHISTORY_H
#define USERHISTORY_H


#include <QString>
#include <QJsonObject>

#include "datetime.h"

class UserHistory
{
    QString rival;
    QString round1;
    QString round1Winner;
    QString round2;
    QString round2Winner;
public:
    DateTime date;
    UserHistory();
    QString& rivalVal();
    QString& roun1Val();
    QString& round1WVal();
    QString& round2Val();
    QString& round2WVal();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &json);
    QString historyToString();
};

#endif // USERHISTORY_H
