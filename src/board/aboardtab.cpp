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

#include "aboardtab.h"
#include "ui_aboardtab.h"

aboardtab::aboardtab(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboardtab)
{
    ui->setupUi(this);

    m_view = new SvgView;

    ui->graphicGridLayout->addWidget(m_view);

}

aboardtab::~aboardtab()
{
    delete ui;
}


bool aboardtab::loadFile(const QString &fileName)
{
    if (!m_view->openFile(fileName)) {
        return false;
    }

    QSize availableSize = this->size();
    double widthScale =  ((double)m_view->width()) / (double)availableSize.width();
    double heightScale =  ((double)m_view->height()) / (double)availableSize.height();

    m_view->scale(widthScale, heightScale);

    Painter=new apainter(m_view, m_view->getSvgItem());

    return true;
}

void aboardtab::turnOn()
{
    Painter->drawLed("HIGH", 0);    
    connect(m_view, &SvgView::inputEvent, Painter, &apainter::inputEvent);
    connect(m_view, &SvgView::showInput, Painter, &apainter::showInput);
}

void aboardtab::turnOff()
{
    disconnect(m_view, &SvgView::inputEvent, Painter, &apainter::inputEvent);
    disconnect(m_view, &SvgView::showInput, Painter, &apainter::showInput);
    Painter->turnOff();
}
