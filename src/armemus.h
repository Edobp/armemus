#ifndef armemus_H
#define armemus_H

#include "adefinitions.h"
#include "aincludes.h"

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

    void setWorkspace();
    void loadBoards();

    // Center area new project

    QTabWidget* tabs;
    aproject *project;

    // Code editor and Board view

    aboardtab *board;
    aeditortab *editor;

    // Output widget

    QTextBrowser *outputBrowser;

    bool existProject;

    AProjectInfo projectInfo;
    QList<Board> boards;
};

#endif // armemus_H
