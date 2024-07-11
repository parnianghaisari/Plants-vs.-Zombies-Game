#include "userhistory.h"

UserHistory::UserHistory()
{

}

QString &UserHistory::rivalVal()
{
    return rival;
}

QString &UserHistory::roun1Val()
{
    return round1;
}

QString &UserHistory::round1WVal()
{
    return round1Winner;
}

QString &UserHistory::round2Val()
{
    return round2;
}

QString &UserHistory::round2WVal()
{
    return round2Winner;
}

QJsonObject UserHistory::toJson() const
{
    QJsonObject json;
    json["rival"] = rival;
    json["rone"] = round1;
    json["ronewinner"] = round1Winner;
    json["rtwo"] = round2;
    json["rtwowinner"] = round2Winner;
    json["date"] = date.toString();
    return json;
}

void UserHistory::fromJson(const QJsonObject &json)
{
    rival = json["rival"].toString();
    round1 = json["rone"].toString();
    round1Winner = json["ronewinner"].toString();
    round2 = json["rtwo"].toString();
    round2Winner = json["rtwowinner"].toString();
    date.fromString(json["date"].toString());

}

QString UserHistory::historyToString() const
{
    return QString("%1, %2, %3, %4, %5, %6")
            .arg(rival)
            .arg(round1)
            .arg(round1Winner)
            .arg(round2)
            .arg(round2Winner)
            .arg(date.toString());
}
