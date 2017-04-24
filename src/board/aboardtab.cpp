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

    Painter=new apainter(m_view->getSvgItem());

    return true;
}

void aboardtab::inputEvent()
{
    Painter->inputEvent();

}
void aboardtab::showInput()
{
    Painter->showInput(m_view);
}

void aboardtab::turnOn()
{
    connect(m_view, &SvgView::showInput, this, &aboardtab::showInput);
    connect(m_view, &SvgView::inputEvent, this, &aboardtab::inputEvent);
}

void aboardtab::turnOff()
{
    Painter->turnOff();
    disconnect(m_view, &SvgView::showInput, this, &aboardtab::showInput);
    disconnect(m_view, &SvgView::inputEvent, this, &aboardtab::inputEvent);
}
