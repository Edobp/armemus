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
