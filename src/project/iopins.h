/*
 * ARMEmuS pins and leds distribution handler
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Mario Alberto López Ocampo  <malo1986@msn.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef IOPINS_H
#define IOPINS_H

#include "aincludes.h"
#include "adefinitions.h"


class IOpins
{
public:

    IOpins();
    virtual ~IOpins();

    QList<QString> pinString;
    QList<PIN> pinsboard;
    double whpin[2];
    int pinRect;
    QList<LED> ledsboard;
    double whled[2];    
    int ledRect;

    void clear();
    void setBoard(int index);
};

#endif // IOPINS_H
