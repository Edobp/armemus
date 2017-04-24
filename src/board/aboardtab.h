#ifndef Aboardtab_H
#define Aboardtab_H

#include "aincludes.h"
#include "adefinitions.h"

class SvgView;
class apainter;

namespace Ui {
class aboardtab;
}



class aboardtab : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboardtab(QWidget *parent = 0);
    ~aboardtab();
    bool loadFile(const QString &fileName);

    apainter *Painter;
    void turnOn();
    void turnOff();

private slots:
    void showInput();
    void inputEvent();


private:
    Ui::aboardtab *ui;

    SvgView *m_view;

};

#endif // Aboardtab_H
