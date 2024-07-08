#ifndef ZAMBIESGAME_H
#define ZAMBIESGAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QBrush>
#include "board.h"
namespace Ui {
class zambiesGame;
}

class zambiesGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit zambiesGame(QWidget *parent = nullptr);
    ~zambiesGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::zambiesGame *ui;
     void applyStylesheets();
};


#endif // ZAMBIESGAME_H
