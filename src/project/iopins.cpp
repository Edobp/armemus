#include "iopins.h"

IOpins::IOpins()
{    
    clear();
}

void IOpins::clear()
{
    pinString.clear();
    pinsboard.clear();
    whpin[0]=0;
    whpin[1]=0;
    pinRect=0;

    ledsboard.clear();
    whled[0]=0;
    whled[1]=0;
    ledRect=0;
}

void IOpins::setBoard(int index)
{
    QString Reader;
    QString fileName;

    switch (index) {    
    case ArduinoDue:
        fileName=":/files/Arduino/I-O/Arduino Due.txt";
        break;
    case ArduinoZero:
        fileName=":/files/Arduino/I-O/Arduino Zero.txt";
        break;
    default:
        fileName=":/files/Arduino/I-O/Arduino Zero.txt";
        break;
    }

    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream textStream(&file);

    while (!textStream.atEnd()){

        Reader = textStream.readLine();

        if(Reader.contains("\t"))
            Reader.replace("\t"," ");

        Reader=Reader.simplified();        

        if(Reader.contains("isRect")){
            Reader.remove("isRect ");
            QTextStream linea(&Reader);
            linea >> ledRect >>pinRect;            
        }


        if(Reader.contains("whl")){
            Reader.remove("whl ");
            QTextStream linea(&Reader);
            linea >> whled[0] >> whled[1];
        }

        if(Reader.contains("whp")){
            Reader.remove("whp ");
            QTextStream linea(&Reader);
            linea >> whpin[0] >> whpin[1];            
        }

        if(Reader.contains("led")){
            Reader.remove("led ");
            QTextStream linea(&Reader);
            LED ledStruct;
            linea >> ledStruct.num >> ledStruct.x >> ledStruct.y >> ledStruct.color;
            ledsboard.append(ledStruct);
        }

        if(Reader.contains("pin ")){
            Reader.remove("pin ");
            QTextStream linea(&Reader);
            QString pinReader;
            PIN pinStruct;
            linea >> pinReader >> pinStruct.num >> pinStruct.x >> pinStruct.y >> pinStruct.led;            
            pinString.append(pinReader);
            pinsboard.append(pinStruct);
        }

    }
    file.close();
}
