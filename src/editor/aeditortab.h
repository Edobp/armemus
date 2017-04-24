#ifndef aeditortab_H
#define aeditortab_H

#include "aincludes.h"
#include "adefinitions.h"

namespace Ui {
class aeditortab;
}

class aeditor;
class Highlighter;

class aeditortab : public QMainWindow
{
    Q_OBJECT

public:
    explicit aeditortab(int Index,QWidget *parent = 0);
    ~aeditortab();
    void newFile();
    bool openFile(const QString &fileName);    
    aeditor *createAEditor();
    aeditor *activeAEditor();
    void asterisk();
    void tabClose();

    bool save();
    void update_editorStatus(bool *editorStatus, int &tabUnsaved);
    void findtabUnsaved(int tabIndex);

private slots:
    void tabCloseRequested();

private:    

    bool findFile(const QString &fileName);
    bool loadFile(const QString &fileName);    

    void EditorSettings(int BoardIndex);    

    QAbstractItemModel *modelFromFile(const QString& fileName);

    Ui::aeditortab *ui;

    Highlighter *highlighter;
    QTextEdit *textEdit;
    int findTab;

    QFont font;
    QString BoardKey;
    QCompleter *completer;
    int BoardIndex;
};

#endif // aeditortab_H
