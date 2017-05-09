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
