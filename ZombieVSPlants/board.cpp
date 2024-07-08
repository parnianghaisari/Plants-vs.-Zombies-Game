#include "board.h"
#include "sensitiveblock.h"
#include <QDebug>

Board::Board(QGraphicsScene *scene) {
    // Calculate the number of rows and columns based on the given dimensions
    scene->setSceneRect(160,190,1212,426);
   // QGraphicsView view(&scene);
   // view.setRenderHint(QPainter::Antialiasing);
    int rows=6;
    int cols=12;
    // Create a grid of sensitive blocks
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            qreal x = 10 + col * 101; // Starting x position is 10
            qreal y = 20 + row * 71; // Starting y position is 20
            QString labelText = QString("Block %1,%2").arg(row).arg(col);
            SensitiveBlock *block = new SensitiveBlock(x, y, 101, 71, labelText);
            scene->addItem(block);

            // Connect the block's signal to the slot method
            connect(block, &SensitiveBlock::blockClicked, this, &Board::handleBlockClicked);
        }
    }
}

void Board::handleBlockClicked(const QString &labelText) {
    qDebug() << labelText << "clicked!";
}
