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

#ifndef ASymbols_H
#define ASymbols_H

#include <QDialog>

namespace Ui {
class asymbols;
}

class asymbols : public QDialog
{
    Q_OBJECT

public:
    explicit asymbols(QWidget *parent = 0);
    ~asymbols();

    QString getSymbol();

private:
    Ui::asymbols *ui;
};

#endif // ASymbols_H
