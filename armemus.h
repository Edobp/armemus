#ifndef ARMEMUS_H
#define ARMEMUS_H

#include <QMainWindow>
#include "boardwindow.h"
#include "editorwindow.h"

namespace Ui {
class armemus;
}

class armemus : public QMainWindow
{
    Q_OBJECT

public:
    explicit armemus(QWidget *parent = 0);
    ~armemus();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

private:
    Ui::armemus *ui;
    Board_W Board;
    Editor_W Editor;
};

#endif // ARMEMUS_H
