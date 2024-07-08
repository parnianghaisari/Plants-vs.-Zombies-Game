#include "sensitiveblock.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

SensitiveBlock::SensitiveBlock(qreal x, qreal y, qreal width, qreal height, const QString &labelText)
    : QGraphicsRectItem(x, y, width, height), isClicked(false) {
    setBrush(QBrush(Qt::lightGray));
    setFlag(QGraphicsItem::ItemIsSelectable);

    // Create a label and add it to the block
    QGraphicsTextItem *label = new QGraphicsTextItem(labelText, this);
    label->setPos(width / 2 - label->boundingRect().width() / 2,
                  height / 2 - label->boundingRect().height() / 2);
}

void SensitiveBlock::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // Toggle the clicked state
    isClicked = !isClicked;
    // Change the color based on the state
    if (isClicked) {
        setBrush(QBrush(Qt::blue));
    } else {
        setBrush(QBrush(Qt::lightGray));
    }
    emit blockClicked(static_cast<QGraphicsTextItem*>(childItems().first())->toPlainText());
    QGraphicsRectItem::mousePressEvent(event);
}
