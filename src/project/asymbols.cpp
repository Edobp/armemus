/*
 * ARMEmuS build options symbols
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

#include "asymbols.h"
#include "ui_asymbols.h"

asymbols::asymbols(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asymbols)
{
    ui->setupUi(this);
    ui->lineEditSymbol->setFocus();
}

asymbols::~asymbols()
{
    delete ui;
}

QString asymbols::getSymbol()
{
    return ui->lineEditSymbol->text();
}
