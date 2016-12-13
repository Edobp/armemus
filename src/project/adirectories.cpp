#include "adirectories.h"
#include "ui_adirectories.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

adirectories::adirectories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adirectories)
{
    ui->setupUi(this);
    ui->lineEditDirectories->setFocus();
}

adirectories::~adirectories()
{
    delete ui;
}

void adirectories::on_toolButton_clicked()
{

    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select folder"),QString());


    ui->lineEditDirectories->setText(folderPath);
}

QString adirectories::getFolderPath()
{
    return ui->lineEditDirectories->text();
}

