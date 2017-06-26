/*
 * ARMEmuS debugger
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Nolberto Andrés Buitrago Velásquez  <andresbury@hotmail.com>
 *  Juan Miguel Cardona Londoño  <juan-mcl@hotmail.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#include "adebug.h"

adebug::adebug()
{
    debug = new QProcess;

    connect(debug, &QProcess::readyReadStandardOutput, this, &adebug::output);
    connect(debug, &QProcess::readyReadStandardError, this, &adebug::output);

    //ui->TablaRegistros->addTopLevelItems(Lista_Registros);
}

void adebug::run()
{
    debug->start("arm-none-eabi-gdb");

    debug->write("target remote :1234\n");
    debug->write("file /home/andres/workspace/blinky/Debug/blinky.elf\n");
    debug->write("y\n");
    debug->write("load\n");

    debug->write("info registers\n");

    debug->write("quit\n");

    debug->waitForFinished();
}

void adebug::output()
{
    QRegExp rx("(r)(\\d)+\\s+(0x)\\d+");

    QString output (debug->readAllStandardOutput());

    if (output.contains(rx)){
        rx.indexIn(output);
        QStringList listReg = rx.capturedTexts();
        qDebug() << listReg.first();
        registersList.append(new QTreeWidgetItem(QStringList(listReg.first())));
    }

}
