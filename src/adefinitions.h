/*
 * ARMEmuS definitions
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Mario Alberto López Ocampo  <malo1986@msn.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef ADEFINITIOS_H
#define ADEFINITIOS_H

#include <QString>

// ARMEmuS defines

#define APROJECT_NAME   "ARMEmuS"

// ARMEmuS typedef

enum BoardType {ArduinoDue, ArduinoZero, Feather, RaspberryPi, Tiva};

typedef struct
{
    QString name;
    QString path;    
    int boardIndex;
}AProjectInfo;

typedef struct
{
    QString name;
    QString image;    
}Board;

typedef struct
{
    int num;
    double x;
    double y;
    QString color;
}LED;

typedef struct
{
    int num;
    double x;
    double y;
    int led;
}PIN;


#endif // ADEFINITIOS_H
