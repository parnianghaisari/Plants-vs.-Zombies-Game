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
#include <QTimer>
#include <QSignalMapper>
#include <QPushButton>
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
    void on_pushButtonC1_clicked();

    void on_pushButton_7_clicked();

    void on_pushButtonC2_clicked();

    void on_pushButtonC3_clicked();

    void on_pushButtonC4_clicked();

    void on_pushButtonC5_clicked();

    void on_pushButtonC6_clicked();
    void generateRandomNumberZ();
    void handleButtonClick();

private:
    Ui::zambiesGame *ui;
    void applyStylesheets();
    QTimer *timer;
    QSignalMapper *signalMapper;
    int locBrain;
};


#endif // ZAMBIESGAME_H
