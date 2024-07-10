#ifndef MAPUPDATER_H
#define MAPUPDATER_H

#include <QObject>
#include <QMap>
#include <QTimer>

class MapUpdater : public QObject {
    Q_OBJECT

public:
    explicit MapUpdater(int first, int last, QObject *parent = nullptr);

    void startUpdating();
    void setGameMap(const QMap<int, int> &gameMap);

signals:
    void updateMapZ(QMap<int, int> gameMap, int first, int last);

private slots:
    void onTimeout();

private:
    QMap<int, int> m_gameMap;
    int m_first;
    int m_last;
    QTimer m_timer;
};

#endif // MAPUPDATER_H
