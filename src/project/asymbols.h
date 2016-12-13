#ifndef ASymbols_H
#define ASymbols_H

#include <QDialog>

namespace Ui {
class asymbols;
}

class asymbols : public QDialog
{
    Q_OBJECT

public:
    explicit asymbols(QWidget *parent = 0);
    ~asymbols();

    QString getSymbol();

private:
    Ui::asymbols *ui;
};

#endif // ASymbols_H
