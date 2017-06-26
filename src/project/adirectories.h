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

#ifndef ADirectories_H
#define ADirectories_H

#include "aincludes.h"
#include "adefinitions.h"

namespace Ui {
class adirectories;
}

class adirectories : public QDialog
{
    Q_OBJECT

public:
    explicit adirectories(QWidget *parent = 0);
    ~adirectories();

    QString getFolderPath();

private slots:
    void on_toolButton_clicked();

private:
    Ui::adirectories *ui;
};

#endif // ADirectories_H
