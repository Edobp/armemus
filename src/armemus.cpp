#include "armemus.h"
#include "ui_armemus.h"

#include <QScrollBar>

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
    connect(ui->actionCloseProject, &QAction::triggered, this, &armemus::actionCloseProject);
    
    connect(ui->actionHelp, &QAction::triggered, this, &armemus::actionHelp);
    connect(ui->actionAbout, &QAction::triggered, this, &armemus::actionAbout);
    connect(ui->actionExit, &QAction::triggered, this, &armemus::actionExit);
    connect(ui->actionBuildOptions, &QAction::triggered, this, &armemus::actionBuildOptions);

    connect(ui->actionNewFile, &QAction::triggered, this, &armemus::actionNewFile);
    connect(ui->actionOpenFile, &QAction::triggered, this, &armemus::actionOpenFile);
    connect(ui->actionCloseFile, &QAction::triggered, this, &armemus::actionCloseFile);    


    //connect(ui->actionBuild, &QAction::triggered, this, &armemus::actionSave);
    connect(ui->actionBuild, &QAction::triggered, this, &armemus::actionBuild);
    connect(&BuildProcess, &QProcess::readyRead, this, &armemus::printBuildProcess);    

    existProject = false;    

    DisableButtons();
    loadBoards();
    project = new aproject(this, boards);

    BuildProcess.setProcessChannelMode(QProcess::MergedChannels);
}


armemus::~armemus()
{
    delete ui;
}

void armemus::actionNew()
{
    update_editorStatus();

    if (!existProject)
        setWorkspace();

    else{         

        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Do you want to close this project and to create a new project?"));

        switch (sel) {
        case QMessageBox::Yes:                        
            if(confirmSave())
                break;
            else
                return;
        case QMessageBox::No:
            return;
        default:
            break;
        }
        clearWorkspace();
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

bool armemus::actionSave()
{
    update_editorStatus();    

    if(editorStatus[1]){
        editor->findtabUnsaved(tabUnsaved);        
        if(!editor->save())
            return false;
        else
            return this->actionSave();
    }

    statusBar()->showMessage(tr("Project saved"), 3000);
    ui->actionBuild->setEnabled(true);
    return true;
}

void armemus::actionHelp()
{
    QMessageBox Help (this);

    Help.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    Help.information(this,tr("Help"),tr("Help Menu"));
}

void armemus::actionAbout()

{
    QMessageBox About(this);

    QLabel link;
    link.setText(APROJECT_NAME"<br>Icons:<a href=\"https://snwh.org/paper/\">Paper Icons</a></br> by Sam Hewitt");
    link.setOpenExternalLinks(true);

    About.about(this,tr("About " APROJECT_NAME), link.text());
}

void armemus::actionExit()
{
    this->close();
}


void armemus::actionBuildOptions()
{
    abuild *buildOptions = new abuild(this, projectInfo.path, projectInfo.name);
    buildOptions->setModal(true);
    buildOptions->show();
}

void armemus::actionBuild()
{    
    outputBrowser->clear();

    QString root = "/home/malo";
    QString ABuilder = "/Escritorio/Arduino Builder/";    

    QString path_File(FileBoard);
    QString path_Build = projectInfo.path+"/"+projectInfo.name+"/Build";

    switch (projectInfo.boardIndex) {
    case ArduinoDue:
        BuildProcess.start(root+ABuilder+"arduino-builder", QStringList()<<"-compile"<<"-logger"<<"machine"<<"-hardware"<<root+ABuilder+"hardware"<<"-hardware"<<root+ABuilder+"arduino-packages/packages"<<"-tools"<<root+ABuilder+"tools-builder"<<"-tools"<<root+ABuilder+"hardware/tools/avr"<<"-tools"<<root+ABuilder+"arduino-packages/packages"<<"-built-in-libraries"<<root+ABuilder+"libraries"<<"-libraries"<<root+ABuilder+"Arduino/libraries"<<"-fqbn"<<"arduino:sam:arduino_due_x"<<"-build-path"<<path_Build<<"-warnings"<<"none"<<"-prefs"<<"build.warn_data_percentage=75"<<"-prefs"<<"-runtime.tools.bossac.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/bossac/1.6.1-arduino"<<"-prefs"<<"runtime.tools.arm-none-eabi-gcc.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1"<<"-verbose"<<path_File);
        break;
    case ArduinoZero:
        BuildProcess.start(root+ABuilder+"arduino-builder", QStringList()<<"-compile"<<"-logger"<<"machine"<<"-hardware"<<root+ABuilder+"hardware"<<"-hardware"<<root+ABuilder+"arduino-packages/packages"<<"-tools"<<root+ABuilder+"tools-builder"<<"-tools"<<root+ABuilder+"hardware/tools/avr"<<"-tools"<<root+ABuilder+"arduino-packages/packages"<<"-built-in-libraries"<<root+ABuilder+"libraries"<<"-libraries"<<root+ABuilder+"Arduino/libraries"<<"-fqbn"<<"arduino:samd:arduino_zero_native"<<"-build-path"<<path_Build<<"-warnings"<<"none"<<"-prefs"<<"build.warn_data_percentage=75"<<"-prefs"<<"-runtime.tools.bossac.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/bossac/1.7.0"<<"-prefs"<<"runtime.tools.arm-none-eabi-gcc.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1"<<"-prefs"<<"runtime.tools.openocd.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/openocd/0.9.0-arduino"<<"-prefs"<<"runtime.tools.CMSIS.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/CMSIS/4.0.0-atmel"<<"-verbose"<<path_File);        
        break;
    default:
        break;
    }
}

void armemus::actionCloseProject()
{
    update_editorStatus();

    if(editorStatus[0]){
        if(confirmSave())
            clearWorkspace();
        else
            return;
    }
    else
        clearWorkspace();
}

void armemus::actionCloseFile()
{

    editor->tabClose();

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

//Workspace settings

inline void armemus::clearWorkspace(){

    existProject=false;    
    DisableButtons();
    delete outputBrowser;
    //delete editor;
    //delete board;
    delete tabs;
}


inline void armemus::DisableButtons()
{

    //menu
    ui->actionNewFile->setEnabled(false);
    ui->actionOpenFile->setEnabled(false);
    ui->actionCloseFile->setEnabled(false);
    ui->actionCloseProject->setEnabled(false);
    ui->actionBuildOptions->setEnabled(false);

    //toolbar
    ui->actionSave->setEnabled(false);
    ui->actionBuild->setEnabled(false);
    ui->actionPlay->setEnabled(false);
    ui->actionStop->setEnabled(false);
    ui->actionStep->setEnabled(false);
}

inline void armemus::setWorkspace()
{
    project->clear();
    project->exec();
    project->getInfo(projectInfo);

    if ( !projectInfo.name.isEmpty() && !projectInfo.path.isEmpty() ){        

        outputBrowser = new QTextBrowser;

        tabs = new QTabWidget;

        editor = new aeditortab(projectInfo.boardIndex);        
        board = new aboardtab;

        tabs->addTab(editor,"Code");
        tabs->addTab(board,"Board");

        ui->mainLayout->addWidget(tabs);
        ui->outputLayout->addWidget(outputBrowser);

        tabs->setCurrentIndex(0);                

        project->getFilePath(FileBoard);
        editor->openFile(FileBoard);
        board->loadFile(":/boards/"+boards[projectInfo.boardIndex].image);

        existProject = true;        

        ui->actionNewFile->setEnabled(true);
        ui->actionOpenFile->setEnabled(true);
        ui->actionCloseFile->setEnabled(true);
        ui->actionCloseProject->setEnabled(true);
        ui->actionBuildOptions->setEnabled(true);
        ui->actionSave->setEnabled(true);

    }
}

void  armemus::printBuildProcess()

{
    QByteArray Lectura;

    Lectura=BuildProcess.readAll();

    outputBrowser->insertPlainText(Lectura);
    outputBrowser->verticalScrollBar()->setValue(outputBrowser->verticalScrollBar()->maximum());
}

bool armemus::confirmSave()

{    
    if(editorStatus[1]){
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Some files have been modified\nDo you want to save before closing it?"));
        switch (sel) {
        case QMessageBox::Yes:
            if(this->actionSave())
                return true;
            else
                return false;
        case QMessageBox::No:
            break;
                return true;
        default:
            break;
        }
    }
    return true;
}


void armemus::update_editorStatus()
{


    if(existProject)
        editor->update_editorStatus(editorStatus, tabUnsaved);

    else{
        editorStatus[0]=false;
        editorStatus[1]=false;
    }


}


void armemus::closeEvent (QCloseEvent *event)
{
    update_editorStatus();

    if(existProject && editorStatus[0]){
        if(editorStatus[1]){
            if(confirmSave())
                event->accept();
            else
                event->ignore();
        }
    }
    else
        event->accept();
}
