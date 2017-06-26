/*
 * ARMEmuS pins and leds painter
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Mario Alberto López Ocampo  <malo1986@msn.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef APAINTER_H
#define APAINTER_H

#include "aincludes.h"
#include "adefinitions.h"

#include <QGraphicsView>
#include <QGraphicsSvgItem>
#include <QAbstractGraphicsShapeItem>

class IOpins;

class apainter : public QObject
{
    Q_OBJECT

    QGraphicsView *m_view;
    QGraphicsSvgItem *m_svgItem;
    QList<QAbstractGraphicsShapeItem*> outputPins;
    QList<QAbstractGraphicsShapeItem*> Leds;
    QList<QAbstractGraphicsShapeItem*> inputPins;    
    QList<int> disableInputs;

    QList<bool> inputsState;



public:
    apainter(QGraphicsView * ptr_view, QGraphicsSvgItem *ptr_svgItem);
    virtual ~apainter();

    void setBoard(const IOpins *IOBoard);

    void drawPin(const QByteArray &Reader, int index);
    void drawLed(const QByteArray &Reader, int index);

    void turnOn();
    void turnOff();    
    void clear();

public slots:
    void inputEvent();
    void showInput();

signals:
    void printInputpin(int index, bool state);
};

#endif // APAINTER_H
