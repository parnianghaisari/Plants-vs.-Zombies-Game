#ifndef FORGOTWINDOW_H
#define FORGOTWINDOW_H

#include <QMainWindow>
#include"globals.h"
namespace Ui {
class ForgotWindow;
}

class ForgotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForgotWindow(QWidget *parent = nullptr);
    ~ForgotWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ForgotWindow *ui;
};

#endif // FORGOTWINDOW_H
