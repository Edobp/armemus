#include "armemus.h"
#include "ui_armemus.h"

#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>


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

void armemus::on_actionNew_triggered()
{
    //QVBoxLayout* Main_layout = new QVBoxLayout;

    QTabWidget* Tabs = new QTabWidget;

    Tabs -> addTab(&Board,"Board");
    Tabs -> addTab(&Editor,"Code Editor");

    this -> setCentralWidget(Tabs);
}




void armemus::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Proyect"), QString(),
                tr("Proyect Files (*.pr)"));
}

void armemus::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Proyect"), QString(),
                tr("Proyect Files (*.pr)"));
}

void armemus::on_actionHelp_triggered()
{
    QMessageBox Help (this);

    Help.information(this,tr("Help"),tr("Help Menu"));

}


void armemus::on_actionAbout_triggered()
{
    QMessageBox About(this);

    About.about(this,tr("About ARMEMUS"), tr("ARMEMUS Uniquindio"));
}
