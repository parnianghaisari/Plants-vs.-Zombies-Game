#ifndef PLANTS_H
#define PLANTS_H

#include <QMainWindow>
#include "globals.h"

namespace Ui {
class plants;
}

class plants : public QMainWindow
{
    Q_OBJECT

public:
    explicit plants(QWidget *parent = nullptr);
    ~plants();

private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::plants *ui;
    void applyStylesheets();
};

#endif // PLANTS_H
