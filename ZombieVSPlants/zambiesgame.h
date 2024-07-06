#ifndef ZAMBIESGAME_H
#define ZAMBIESGAME_H

#include <QMainWindow>

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

private:
    Ui::zambiesGame *ui;
};

#endif // ZAMBIESGAME_H
