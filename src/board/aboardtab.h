/*
 * ARMEmuS board viewer tab
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Eduardo Augusto Bermúdez Parra  <edobp5@gmail.com>
 *  Alex Román López Coy  <alex.roman.lopez@gmail.com>
 *  Mario Alberto López Ocampo  <malo1986@msn.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef Aboardtab_H
#define Aboardtab_H

#include "aincludes.h"
#include "adefinitions.h"

class SvgView;
class apainter;

namespace Ui {
class aboardtab;
}



class aboardtab : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboardtab(QWidget *parent = 0);
    ~aboardtab();
    bool loadFile(const QString &fileName);

    apainter *Painter;
    void turnOn();
    void turnOff();

private:
    Ui::aboardtab *ui;

    SvgView *m_view;

};

#endif // Aboardtab_H
