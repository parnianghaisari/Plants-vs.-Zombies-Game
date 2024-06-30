#ifndef FORGOTWINDOW_H
#define FORGOTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ForgotWindow;
}

class ForgotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForgotWindow(QWidget *parent = nullptr);
    ~ForgotWindow();

private:
    Ui::ForgotWindow *ui;
};

#endif // FORGOTWINDOW_H
