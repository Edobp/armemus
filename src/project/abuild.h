#ifndef ABuild_H
#define ABuild_H

#include "armemus_def.h"

namespace Ui {
class abuild;
}

class adirectories;
class asymbols;

class abuild : public QDialog
{
    Q_OBJECT

public:
    explicit abuild(QWidget *parent = 0, QString path=NULL, QString name=NULL);
    ~abuild();

private slots:
    void on_toolButton_clicked();
    void addListPath();
    void addSymbol();
    void changeWarning();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_2_clicked();

    void on_comboBoxOptimization_currentIndexChanged(const QString &arg1);

private:
    Ui::abuild *ui;

    adirectories *directoriesOptions;
    asymbols *symbolsOptions;

    QString projectPath;
    QString projectName;

    QStringList listDirectories;
    QStringList listSymbols;
    QString warning;
    QString optimization;

    QStringRef nameXml;
};

#endif // ABuild_H
