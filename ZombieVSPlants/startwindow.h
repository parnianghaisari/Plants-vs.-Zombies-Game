#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "datahandeler.h"
#include "globals.h"
#include "gamehistory.h"
#include"setting.h"
#include "zambiesgame.h"
#include "plants.h"
#include "globals.h"

#include "client.h"
namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StartWindow *ui;
   DataHandler *dataHandler;
   Client *client;
};

#endif // STARTWINDOW_H
