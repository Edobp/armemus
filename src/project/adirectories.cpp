/*
 * ARMEmuS build options dialog
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Giovanny Rodriguez Sánchez  <giovannyrs19@gmail.com>
 *  Camilo Eduardo Arenas Saavedra  <camiloarenassaavedra@gmail.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

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

