#ifndef Aproject_H
#define Aproject_H

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
class aproject;
}

class aproject : public QDialog
{
    Q_OBJECT

public:
    explicit aproject(QWidget *parent = 0);
    ~aproject();

    void getInfo(QString& project, QString& path,int& Index);

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
};

#endif // Aproject_H
