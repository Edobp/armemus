#ifndef Aboardtab_H
#define Aboardtab_H

#include "aincludes.h"
#include "adefinitions.h"

class SvgView;

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

private slots:

private:
    Ui::aboardtab *ui;

    SvgView *m_view;
};

#endif // Aboardtab_H
