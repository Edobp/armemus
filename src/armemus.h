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

private slots:
    void actionNew();
    void actionNewFile();
    void actionOpen();
    void actionOpenFile();
    bool actionSave();
    void actionHelp();
    void actionAbout();
    void actionCloseFile();
    void actionCloseProject();
    void actionExit();
    void actionBuildOptions();
    void actionBuild();
    void actionPlay();
    void actionStop();

    void  printProcess();

private:
    Ui::armemus *ui;


    //Workspace settings

    inline void DisableButtons();    
    inline void clearWorkspace();
    inline void setWorkspace();
    void loadBoards();
    void closeProcess(); //close process channel

    // Center area new project

    QTabWidget* tabs;
    aproject *project;

    // Code editor and Board view

    aboardtab *board;
    aeditortab *editor;

    // Output widget

    QTextBrowser *outputBrowser;

    bool existProject;
    bool editorStatus[2];  //indice 0: indica existencia de pestañas; indice 1: indica si hay archivos sin guardar
    int tabUnsaved;  //se usa para tener conocimiento de pestañas sin guardar

    AProjectInfo projectInfo;
    QList<Board> boards;
    IOpins IOBoard;

    QString FileBoard;

    //Process

    QProcess BuildProcess;
    QProcess QemuProcess;
    QProcess GDBprocess;

    //App events
    void update_editorStatus();
    bool confirmSave();
    int getIndex(const QByteArray &processReader);
    void closeEvent (QCloseEvent *event);
};

#endif // armemus_H
