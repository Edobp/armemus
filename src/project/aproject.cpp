#include "aproject.h"
#include "ui_aproject.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QXmlStreamWriter>
#include <QMessageBox>

aproject::aproject(QWidget *parent, QList<Board> boards) :
    QDialog(parent),
    ui(new Ui::aproject)
{
    ui->setupUi(this);

    ui->tabWidget->tabBar()->hide();

    clear();
    ui->nameLineEdit->setFocus();

    /************************************************
     *  Connects signals - slots ARMEmuS New Project
     ************************************************/

    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &aproject::enableNextButton);
    connect(ui->pathLineEdit, &QLineEdit::textChanged, this, &aproject::enableNextButton);

    connect(ui->browseButton, &QPushButton::clicked, this, &aproject::pathSearch);
    connect(ui->cancelButton1, &QPushButton::clicked, this, &aproject::actionCancel);
    connect(ui->cancelButton2, &QPushButton::clicked, this, &aproject::actionCancel);
    connect(ui->nextButton, &QPushButton::clicked, this, &aproject::nextTab);
    connect(ui->backButton, &QPushButton::clicked, this, &aproject::backTab);
    connect(ui->boardComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &aproject::selectBoard);
    connect(ui->finishButton, &QPushButton::clicked, this, &aproject::actionFinish);

    for( int index=0; index<boards.size(); index++){
        ui->boardComboBox->addItem( boards[index].name );
    }
}

aproject::~aproject()
{
    delete ui;

}


void aproject::actionCancel()
{
    ui->pathLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->boardComboBox->setCurrentIndex(0);

    this->close();

}

void aproject::clear()
{
    projectName.clear();    
    projectPath.clear();    
    boardIndex=0;

    filePath.clear();    

    ui->nameLineEdit->clear();
    ui->boardComboBox->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);

    ui->pathLineEdit->setText(QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last());

}

/* ******************************************************************************************
 *  Tab 1: File path
 * ******************************************************************************************/

void aproject::pathSearch()
{
    QString DirectoryPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"),ui->pathLineEdit->text());
    if (!DirectoryPath.isNull())
        ui->pathLineEdit->setText(DirectoryPath);
}


void aproject::enableNextButton()
{
    if(!ui->nameLineEdit->text().isEmpty()&&!ui->pathLineEdit->text().isEmpty())
        ui->nextButton->setEnabled(true);
    else
        ui->nextButton->setEnabled(false);
}

void aproject::nextTab()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->boardComboBox->setFocus();
}

/* ******************************************************************************************
 *  Tab 2: Board select
 * ******************************************************************************************/

void aproject::selectBoard(int index)
{
    if(index)
        ui->finishButton->setEnabled(true);
    else
        ui->finishButton->setEnabled(false);
}

void aproject::backTab()
{
    ui->tabWidget->setCurrentIndex(0);
}

void aproject::actionFinish()
{
    projectName = ui->nameLineEdit->text();
    projectPath = ui->pathLineEdit->text();
    boardIndex = ui->boardComboBox->currentIndex();

    // Create folder that contains the project
    QDir dir(projectPath+"/"+projectName);    

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    // Create file .apf that contains the project configurations
    QXmlStreamWriter xmlWriter;

    QFile file(projectPath+"/"+projectName+"/"+projectName+".apf");

    //Overwrite project and folders if user accepts

    if(file.exists()){
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Project \"%1.apf\" already exists\nDo you want to overwrite it?\n(Note: All previous project folders created will be removed)").arg(projectName));
        switch (sel) {
        case QMessageBox::Yes:
            clearProjectFiles();
            break;
        case QMessageBox::No:
            ui->tabWidget->setCurrentIndex(0);
            projectName.clear();
            projectPath.clear();
            boardIndex=0;
            return;
        default:
            break;
        }
    }

//--------------------------------------------------------------------------------------------------------

    if (!file.open(QIODevice::WriteOnly)){
        QMessageBox::warning(0, "Error!", "Error opening file");
    }
    else{
        xmlWriter.setDevice(&file);

        // Write a document start with the XML version number.
        xmlWriter.writeStartDocument();
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartElement("Armemus_Project_File");

        xmlWriter.writeStartElement("Compiler");

        xmlWriter.writeStartElement("Directories");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("Symbols");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("Warnings");

        xmlWriter.writeStartElement("Warning");
        xmlWriter.writeAttribute("option","-W");
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("Optimization");

        xmlWriter.writeStartElement("optimization");
        xmlWriter.writeAttribute("option","-O0");
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
        /*end document */

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
    }

    dir.mkpath("Build");

    QString Source;
    QString Destination(projectPath+"/"+projectName);

    switch (boardIndex-1) {
    case ArduinoDue:
    case ArduinoZero:
    case Feather:        
        Source=":/files/Arduino/Arduino";
        break;
    case Tiva:        
        Source=":/files/Tiva/Tiva";
        break;
    default:
        break;
    }

    copyProjectFolders(Source, Destination);
    this->close();
}


void aproject::copyProjectFolders(QString src,  QString dst)
{

    QDirIterator Folders(src,QDir::Dirs | QDir::NoDotAndDotDot);

    QDir dir(dst);

    if(!dir.exists())
        dir.mkpath(".");

    while(Folders.hasNext())
    {
        Folders.next();

        if(Folders.fileName()=="template")
            copyProjectFolders(Folders.filePath(),dst+QDir::separator()+projectName);
        else
            copyProjectFolders(Folders.filePath(),dst+QDir::separator()+Folders.fileName());
    }

    QDirIterator Files(src,QDir::Files);

    while(Files.hasNext())
    {
        Files.next();

        if(Files.fileName().contains("template")){

            if(Files.fileName()=="template.ino"){
                filePath=dst+QDir::separator()+projectName+".ino";
                QFile::copy(Files.filePath(),filePath);
                QFile::setPermissions(filePath, QFile::WriteOwner | QFile::ReadOwner);
            }
        }

        else {
            QFile::copy(Files.filePath(),dst+QDir::separator()+Files.fileName());
            QFile::setPermissions(dst+QDir::separator()+Files.fileName(), QFile::WriteOwner | QFile::ReadOwner);
            if(Files.fileName()=="main.c")
                filePath=dst+QDir::separator()+Files.fileName();
        }
    }
}

void aproject::clearProjectFiles()
{
    //remove apf

    QFile::remove(projectPath+"/"+projectName+"/"+projectName+".apf");

    //remove all folders of previous project with their contents

    QDir dir;

    QDirIterator Folders(projectPath+"/"+projectName,QDir::Dirs | QDir::NoDotAndDotDot);

    while (Folders.hasNext())
    {
        Folders.next();
        if((Folders.fileName()=="Build")||(Folders.fileName()==projectName)){
            dir.setPath(Folders.filePath());
            dir.removeRecursively();
        }
    }
}

/* ******************************************************************************************
 * ******************************************************************************************/

void aproject::getInfo(AProjectInfo &info)
{
    info.name = projectName;
    info.path = projectPath;    
    info.boardIndex = boardIndex-1;
}

void aproject::getFilePath(QString &file)
{
    file=filePath;
}
