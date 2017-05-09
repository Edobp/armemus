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
