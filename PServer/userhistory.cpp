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
    return json;
}

void UserHistory::fromJson(const QJsonObject &json)
{
    rival = json["rival"].toString();
    round1 = json["rone"].toString();
    round1Winner = json["ronewinner"].toString();
    round2 = json["rtwo"].toString();
    round2Winner = json["rtwowinner"].toString();
}
