#ifndef PLANTS_H
#define PLANTS_H

#include <QMainWindow>
#include"globals.h"
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

    void on_pushButtonC1_2_clicked();

    void on_pushButtonC2_2_clicked();

    void on_pushButtonC3_2_clicked();

    void on_pushButtonC4_2_clicked();

    void on_pushButtonC5_2_clicked();

    void on_pushButtonC6_2_clicked();

private:
    Ui::plants *ui;
    void applyStylesheets();
    void generateRandomNumberS();
     QTimer *timer;
};

#endif // PLANTS_H
