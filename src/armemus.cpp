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

    /****************************************
     *  Connects signals - slots ARMEmuS App
     ****************************************/

    connect(ui->actionNew, &QAction::triggered, this, &armemus::actionNew);
    connect(ui->actionOpen, &QAction::triggered, this, &armemus::actionOpen);
    connect(ui->actionSave, &QAction::triggered, this, &armemus::actionSave);
    connect(ui->actionHelp, &QAction::triggered, this, &armemus::actionHelp);
    connect(ui->actionAbout, &QAction::triggered, this, &armemus::actionAbout);
    connect(ui->actionExit, &QAction::triggered, this, &armemus::actionExit);
    connect(ui->actionBuildOptions, &QAction::triggered, this, &armemus::actionBuildOptions);

    connect(ui->actionNewFile, &QAction::triggered, this, &armemus::actionNewFile);
    connect(ui->actionOpenFile, &QAction::triggered, this, &armemus::actionOpenFile);
    connect(ui->actionCloseFile, &QAction::triggered, this, &armemus::actionCloseFile);
}


armemus::~armemus()
{
    delete ui;
}

void armemus::actionNew()
{
    project = new aproject;
    project->exec();

    project->getInfo(projectName, projectPath, boardIndex);

    if ( !projectName.isEmpty() && !projectPath.isEmpty() && boardIndex ){

        outputBrowser = new QTextBrowser;

        tabs = new QTabWidget;

        editor = new aeditortab;
        board = new aboardtab;

        tabs->addTab(editor,"Code");
        tabs->addTab(board,"Board");

        //ui->actionSave->setEnabled(true);
        ui->mainLayout->addWidget(tabs);
        ui->outputLayout->addWidget(outputBrowser);

        tabs->setCurrentIndex(0);

        board->loadFile(":/boards/tiva_tm4c123g.svg");
    }
}

void armemus::actionNewFile()
{
    editor->newFile();
}

void armemus::actionOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Proyect"), QString(),
                tr("Proyect Files (*.apf)"));
}

void armemus::actionOpenFile()
{
    const QString fileName = QFileDialog::getOpenFileName(this);

    if (!fileName.isEmpty())
        editor->openFile(fileName);
}

void armemus::actionSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Proyect"), QString(),
                tr("Proyect Files (*.apf)"));
}

void armemus::actionHelp()
{
    QMessageBox Help (this);

    Help.information(this,tr("Help"),tr("Help Menu"));

}

void armemus::actionAbout()
{
    QMessageBox About(this);

    About.about(this,tr("About " APROJECT_NAME), tr(APROJECT_NAME));
}

void armemus::actionExit()
{
    qApp->quit();
}


void armemus::actionBuildOptions()
{
    abuild *buildOptions = new abuild(this, projectPath, projectName);
    buildOptions->setModal(true);
    buildOptions->show();
}

void armemus::actionCloseProject()
{

}

void armemus::actionCloseFile()
{
    editor->tabClose();
}
