#ifndef armemus_H
#define armemus_H

#include "armemus_def.h"

namespace Ui {
class armemus;
}

class armemus : public QMainWindow
{
    Q_OBJECT

public:
    explicit armemus(QWidget *parent = 0);
    ~armemus();

public slots:
    void actionNew();
    void actionNewFile();
    void actionOpen();
    void actionOpenFile();
    void actionSave();
    void actionHelp();
    void actionAbout();
    void actionCloseFile();
    void actionCloseProject();
    void actionExit();
    void actionBuildOptions();

private:
    Ui::armemus *ui;

    // Center area new project

    QTabWidget* tabs;
    aproject *project;

    // Code editor and Board view

    aboardtab *board;
    aeditortab *editor;

    // Output widget

    QTextBrowser *outputBrowser;

    // Path and name project

    QString projectName;
    QString projectPath;
    int boardIndex;

};

#endif // armemus_H
