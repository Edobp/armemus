#include "board_w.h"
#include "ui_board_w.h"

#include <qmessagebox.h>

Board_W::Board_W(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Board_W)
{
    ui->setupUi(this);
}

Board_W::~Board_W()
{
    delete ui;
}

void Board_W::on_actionBoard_triggered()
{
    QMessageBox Board_Sel (this);
    Board_Sel.information(this,tr("Boards"), tr("Board Selection Window"));
}
