#ifndef DATETIME_H
#define DATETIME_H

#include <QDateTime>
#include <QString>

class DateTime {
public:
    DateTime();
    DateTime(const QDateTime &dateTime);

    void setCurrentDateTime();
    QString toString() const;
    void fromString(const QString &dateTimeString);

    QDateTime getDateTime() const;

private:
    QDateTime dateTime;
};

#endif // DATETIME_H
