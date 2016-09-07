#ifndef ARMEMUS_H
#define ARMEMUS_H

#include <QMainWindow>

namespace Ui {
class armemus;
}

class armemus : public QMainWindow
{
    Q_OBJECT

public:
    explicit armemus(QWidget *parent = 0);
    ~armemus();

private:
    Ui::armemus *ui;
};

#endif // ARMEMUS_H
