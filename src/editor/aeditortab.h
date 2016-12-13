#ifndef aeditortab_H
#define aeditortab_H

#include "armemus_def.h"

namespace Ui {
class aeditortab;
}

class aeditor;
class Highlighter;

class aeditortab : public QMainWindow
{
    Q_OBJECT

public:
    explicit aeditortab(QWidget *parent = 0);
    ~aeditortab();
    void newFile();
    bool openFile(const QString &fileName);
    aeditor *createAEditor();
    aeditor *activeAEditor();
    void asterisk();
    void tabClose();

private slots:
    void tabCloseRequested();

private:
    bool findFile(const QString &fileName);
    bool loadFile(const QString &fileName);

    Ui::aeditortab *ui;

    Highlighter *highlighter;
    QTextEdit *textEdit;
    int findTab;
};

#endif // aeditortab_H
