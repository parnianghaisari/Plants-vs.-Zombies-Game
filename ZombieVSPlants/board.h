#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QGraphicsScene>

class Board : public QObject {
    Q_OBJECT

public:
    Board(QGraphicsScene *scene);

public slots:
    void handleBlockClicked(const QString &labelText);
};

#endif // BOARD_H
