#include "apainter.h"





apainter::apainter(QGraphicsSvgItem *parent) : m_svgItem(parent)
{

}

void apainter::drawPin(const PIN *pin, const double *whpin, int isRect)
{
    if(pin==nullptr)
        qDebug()<<"error!";

    outputStr.append("Pin"+QString::number(pin->num));
    QAbstractGraphicsShapeItem *ptr_pin;    

    if(isRect)
        ptr_pin=new QGraphicsRectItem(pin->x, pin->y, whpin[0], whpin[1], m_svgItem);

    else
        ptr_pin=new QGraphicsEllipseItem(pin->x, pin->y, whpin[0], whpin[1], m_svgItem);

    ptr_pin->setPen(Qt::NoPen);

    outputList.append(ptr_pin);
    removeInputPin(pin->num);
}

void apainter::drawLed(const LED *led, const double *whled, int isRect)
{

    outputStr.append("Led"+QString::number(led->num));

    QAbstractGraphicsShapeItem *ptr_led;

    if(isRect)
        ptr_led=new QGraphicsRectItem(led->x, led->y, whled[0], whled[1], m_svgItem);

    else
        ptr_led=new QGraphicsEllipseItem(led->x, led->y, whled[0], whled[1], m_svgItem);


    ptr_led->setBrush(QColor(led->color));
    ptr_led->setPen(Qt::NoPen);

    if(led->num!=0)
        ptr_led->hide();

    outputList.append(ptr_led);


}

void apainter::drawInputs(const QList<PIN> &pins, const double *whpin, int isRect)
{
    QPen lines(Qt::white);

    for(int i=0; i<pins.count();i++){
        QAbstractGraphicsShapeItem *ptr_input;
        if(isRect)
            ptr_input=new QGraphicsRectItem(pins.at(i).x-2, pins.at(i).y-2, whpin[0]+4, whpin[1]+4, m_svgItem);
        else
            ptr_input=new QGraphicsEllipseItem(pins.at(i).x, pins.at(i).y, whpin[0], whpin[1], m_svgItem);


        ptr_input->setPen(lines);
        ptr_input->hide();

        inputList.append(ptr_input);
    }
}

void apainter::removeInputPin(int index)
{
    delete inputList[index];
    inputList[index]=new QGraphicsRectItem();    
}

void apainter::drawStatus(const QByteArray &Reader, int i)
{
    QString copyReader(Reader);
    int indexList;
    if(copyReader.contains("led")){
        indexList=outputStr.indexOf("Led"+QString::number(i));
        if(copyReader.contains("HIGH"))
            outputList.at(indexList)->show();
        else
            outputList.at(indexList)->hide();
    }

    else{
        indexList=outputStr.indexOf("Pin"+QString::number(i));
        if(copyReader.contains("HIGH"))
            outputList.at(indexList)->setBrush(Qt::red);
        else
            outputList.at(indexList)->setBrush(Qt::blue);
    }
}

void apainter::inputEvent()
{
    for(int i=0;i<inputList.count();i++){
        if(inputList.at(i)->isUnderMouse())
            qDebug()<<i;

    }
}

void apainter::showInput(QGraphicsView *ptr)
{
    for(int i=0; i<inputList.count();i++){
        if(inputList.at(i)->isUnderMouse()){
            ptr->setCursor(Qt::PointingHandCursor);
            inputList.at(i)->show();
        }
        else
            inputList.at(i)->hide();
    }
}

void apainter::turnOff()
{

    for(int i=0; i<outputList.count();i++)
        delete outputList[i];

    outputList.clear();
    outputStr.clear();


    for(int i=0; i<inputList.count();i++)
        delete inputList[i];

    inputList.clear();
}
