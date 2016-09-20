#include "editor_w.h"
#include "ui_editor_w.h"

Editor_W::Editor_W(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor_W)
{
    ui->setupUi(this);
}

Editor_W::~Editor_W()
{
    delete ui;
}

void Editor_W::on_actionBuild_triggered()
{
    ui -> textBrowser -> setText("Building...");
}
