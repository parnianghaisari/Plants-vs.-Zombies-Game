#ifndef LASTPAGE_H
#define LASTPAGE_H

#include <QMainWindow>

namespace Ui {
class lastPage;
}

class lastPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit lastPage(QWidget *parent = nullptr);
    ~lastPage();

private:
    Ui::lastPage *ui;
};

#endif // LASTPAGE_H
