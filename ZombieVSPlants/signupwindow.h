#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>
#include "globals.h"
#include "startwindow.h"
namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
