#ifndef Aproject_H
#define Aproject_H

#include "aincludes.h"
#include "adefinitions.h"

#include <QDirIterator>
#include <QFile>

namespace Ui {
class aproject;
}

class aproject : public QDialog
{
    Q_OBJECT

public:
    explicit aproject(QWidget *parent = 0, QList<Board> boards=QList<Board>());
    ~aproject();

    void getInfo(AProjectInfo &info);
    void getFilePath(QString &file);
    void clear();

private slots:    

    void pathSearch();
    void nextTab();
    void selectBoard(int index);
    void backTab();
    void actionCancel();
    void actionFinish();
    void enableNextButton();

private:
    Ui::aproject *ui;

    QString projectName;    
    QString projectPath;
    int boardIndex;

    QString filePath;
    QString extFile;

    void copyPath(QString src,  QString dst);
    void clearProjectFiles();
};

#endif // Aproject_H
