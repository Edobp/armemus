#include "aproject.h"
#include "ui_aproject.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QXmlStreamWriter>
#include <QMessageBox>

aproject::aproject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aproject)
{
    ui->setupUi(this);

    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);

    ui->pathLineEdit->setText(QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last());

    ui->nameLineEdit->setFocus();

    projectName.clear();
    projectPath.clear();
    boardIndex=0;

    /************************************************
     *  Connects signals - slots ARMEmuS New Project
     ************************************************/

    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &aproject::enableNextButton);
    connect(ui->pathLineEdit, &QLineEdit::textChanged, this, &aproject::enableNextButton);

    connect(ui->browseButton, &QPushButton::clicked, this, &aproject::pathSearch);
    connect(ui->cancelButton1, &QPushButton::clicked, this, &aproject::actionCancel);
    connect(ui->cancelButton2, &QPushButton::clicked, this, &aproject::actionCancel);
    connect(ui->nextButton, &QPushButton::pressed, this, &aproject::nextTab);
    connect(ui->backButton, &QPushButton::clicked, this, &aproject::backTab);
    connect(ui->boardComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &aproject::selectBoard);
    connect(ui->finishButton, &QPushButton::clicked, this, &aproject::actionFinish);
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

    this->close();
}

/* ******************************************************************************************
 * ******************************************************************************************/

void aproject::getInfo(QString& project, QString& path,int& Index)
{
    project = projectName;
    path = projectPath;
    Index = boardIndex;
}
