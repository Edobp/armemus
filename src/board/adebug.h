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

#ifndef ADebug_H
#define ADebug_H

#include "aincludes.h"
#include "adefinitions.h"

class adebug : public QTreeWidget
{
    Q_OBJECT

public:
    explicit adebug();
    void run();

private slots:
    void output();

private:
    QProcess* debug;

    QList<QTreeWidgetItem*> registersList;
};

#endif // ADebug_H
