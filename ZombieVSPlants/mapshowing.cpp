#include "mapshowing.h"

MapUpdater::MapUpdater(int first, int last, QObject *parent) : QObject(parent), m_first(first), m_last(last) {
    connect(&m_timer, &QTimer::timeout, this, &MapUpdater::onTimeout);
}

void MapUpdater::startUpdating() {
    m_timer.start(1000); // Update every second
}

void MapUpdater::setGameMap(const QMap<int, int> &gameMap) {
    m_gameMap = gameMap;
}

void MapUpdater::onTimeout() {
    emit updateMapZ(m_gameMap, m_first, m_last);
}
