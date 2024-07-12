#include "lastpage.h"
#include "ui_lastpage.h"

lastPage::lastPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lastPage)
{
    ui->setupUi(this);
}

lastPage::~lastPage()
{
    delete ui;
}
