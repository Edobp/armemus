#include "armemus.h"
#include "ui_armemus.h"

armemus::armemus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::armemus)
{
    ui->setupUi(this);
}

armemus::~armemus()
{
    delete ui;
}
