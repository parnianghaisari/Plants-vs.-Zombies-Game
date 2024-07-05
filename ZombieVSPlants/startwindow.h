#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "datahandeler.h"
namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
public slots:
    void updateLineEdit(const QByteArray &data);
private:
    Ui::StartWindow *ui;
   DataHandler *dataHandler;
};

#endif // STARTWINDOW_H
