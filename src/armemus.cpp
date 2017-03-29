#include "armemus.h"
#include "ui_armemus.h"

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

    existProject = false;

    loadBoards();
    project = new aproject(this, boards);
}


armemus::~armemus()
{
    delete ui;
}

void armemus::actionNew()
{
    if (!existProject){
        project->clear();
        project->exec();
        project->getInfo(projectInfo);

        if ( !projectInfo.name.isEmpty() && !projectInfo.path.isEmpty() ){
            setWorkspace();
            existProject = true;
            return;
        }
    }
    else{
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Do you want to close this project and to create a new project?"));
        switch (sel) {
        case QMessageBox::Yes:
            break;
        case QMessageBox::No:
            return;
        default:
            break;
        }
    }

    existProject = false;

    delete outputBrowser;
    delete editor;
    delete board;
    delete tabs;

    project->clear();
    project->exec();
    project->getInfo(projectInfo);

    if ( !projectInfo.name.isEmpty() && !projectInfo.path.isEmpty() ){
        setWorkspace();
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

    QLabel link;
    link.setText(APROJECT_NAME"<br>Icons:<a href=\"https://snwh.org/paper/\">Paper Icons</a></br> por Sam Hewitt");
    link.setOpenExternalLinks(true);

    About.about(this,tr("About " APROJECT_NAME), link.text());
}

void armemus::actionExit()
{
    qApp->quit();
}


void armemus::actionBuildOptions()
{
    abuild *buildOptions = new abuild(this, projectInfo.path, projectInfo.name);
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

void armemus::setWorkspace()
{
    outputBrowser = new QTextBrowser;

    tabs = new QTabWidget;

    editor = new aeditortab;
    board = new aboardtab;

    tabs->addTab(editor,"Code");
    tabs->addTab(board,"Board");

    ui->mainLayout->addWidget(tabs);
    ui->outputLayout->addWidget(outputBrowser);

    tabs->setCurrentIndex(0);

    board->loadFile(":/boards/"+boards[projectInfo.boardIndex].image);
}

void armemus::loadBoards()
{
    QFile fileBoards(":/boards/boards.txt");
    fileBoards.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&fileBoards);
    Board board;

    while (!in.atEnd()) {
        in.readLine();
        in >> board.name >> board.image;
        if( !board.name.isEmpty() )
            boards.append(board);
    }
}

