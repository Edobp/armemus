#ifndef ADEFINITIOS_H
#define ADEFINITIOS_H

#include <QString>

// ARMEmuS defines

#define APROJECT_NAME   "ARMEmuS"

// ARMEmuS typedef

enum BoardType {ArduinoDue, ArduinoZero, Feather, Tiva};

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


#endif // ADEFINITIOS_H
