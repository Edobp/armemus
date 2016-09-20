#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qlayout.h>
#include <qfiledialog.h>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    //QVBoxLayout* Main_layout = new QVBoxLayout;

    QTabWidget* Tabs = new QTabWidget;

    Tabs -> addTab(&Board,"Board");
    Tabs -> addTab(&Editor,"Code Editor");

    this -> setCentralWidget(Tabs);
}




void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Proyect"), QString(),
                tr("Proyect Files (*.pr)"));
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Proyect"), QString(),
                tr("Proyect Files (*.pr)"));
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox Help (this);

    Help.information(this,tr("Help"),tr("Help Menu"));

}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox About(this);

    About.about(this,tr("About ARMEMUS"), tr("ARMEMUS Uniquindio"));
}
