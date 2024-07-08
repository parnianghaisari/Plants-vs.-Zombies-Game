#ifndef PLANTS_H
#define PLANTS_H

#include <QMainWindow>

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

private:
    Ui::plants *ui;
    void applyStylesheets();
};

#endif // PLANTS_H
