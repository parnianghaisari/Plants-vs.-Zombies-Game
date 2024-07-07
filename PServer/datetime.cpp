#include "datetime.h"

DateTime::DateTime() {
    dateTime = QDateTime::currentDateTime();
}

DateTime::DateTime(const QDateTime &dateTime) {
    this->dateTime = dateTime;
}

DateTime::DateTime(const QString &dateTimeString) {
    fromString(dateTimeString);
}

void DateTime::setCurrentDateTime() {
    dateTime = QDateTime::currentDateTime();
}

QString DateTime::toString() const {
    return dateTime.toString(Qt::ISODate);
}

void DateTime::fromString(const QString &dateTimeString) {
    dateTime = QDateTime::fromString(dateTimeString, Qt::ISODate);
}

QDateTime DateTime::getDateTime() const {
    return dateTime;
}
