#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QMainWindow>
#include"globals.h"
#include"startwindow.h"
#include <QTextEdit>
namespace Ui {
class gameHistory;
}

class gameHistory : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameHistory(QWidget *parent = nullptr);
     void setTextInTextEdit(const QString &text);
    ~gameHistory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gameHistory *ui;
    QTextEdit *textEdit;
};

#endif // GAMEHISTORY_H
