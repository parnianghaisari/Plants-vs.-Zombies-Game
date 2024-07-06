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

private:
    Ui::plants *ui;
};

#endif // PLANTS_H
