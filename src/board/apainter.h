#ifndef APAINTER_H
#define APAINTER_H

#include "aincludes.h"
#include "adefinitions.h"

#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QAbstractGraphicsShapeItem>

class apainter
{
    QGraphicsSvgItem *m_svgItem;
    QList<QAbstractGraphicsShapeItem*> outputList;
    QList<QAbstractGraphicsShapeItem*> inputList;
    void removeInputPin(int index);    
public:
    apainter(QGraphicsSvgItem *parent);

    QList<QString> outputStr;

    void drawPin(const PIN *pin, const double *whpin, int isRect);
    void drawLed(const LED *led, const double *whled, int isRect);
    void drawStatus(const QByteArray &Reader, int i);
    void drawInputs(const QList<PIN> &pins, const double *whpin, int isRect);
    void turnOff();

    void inputEvent();
    void showInput(QGraphicsView *ptr);

};

#endif // APAINTER_H
