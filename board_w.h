#ifndef BOARD_W_H
#define BOARD_W_H

#include <QMainWindow>

namespace Ui {
class Board_W;
}

class Board_W : public QMainWindow
{
    Q_OBJECT

public:
    explicit Board_W(QWidget *parent = 0);
    ~Board_W();

private slots:
    void on_actionBoard_triggered();

private:
    Ui::Board_W *ui;
};

#endif // BOARD_W_H
