#ifndef SENSITIVEBLOCK_H
#define SENSITIVEBLOCK_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>

class SensitiveBlock : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    SensitiveBlock(qreal x, qreal y, qreal width, qreal height, const QString &labelText);

signals:
    void blockClicked(const QString &labelText);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool isClicked;
};

#endif // SENSITIVEBLOCK_H
