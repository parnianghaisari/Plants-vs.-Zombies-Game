#ifndef SECONDSTRART_H
#define SECONDSTRART_H

#include <QMainWindow>

namespace Ui {
class SecondStrart;
}

class SecondStrart : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondStrart(QWidget *parent = nullptr);
    ~SecondStrart();

private:
    Ui::SecondStrart *ui;
};

#endif // SECONDSTRART_H
