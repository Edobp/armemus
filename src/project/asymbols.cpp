#include "asymbols.h"
#include "ui_asymbols.h"

asymbols::asymbols(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asymbols)
{
    ui->setupUi(this);
    ui->lineEditSymbol->setFocus();
}

asymbols::~asymbols()
{
    delete ui;
}

QString asymbols::getSymbol()
{
    return ui->lineEditSymbol->text();
}
