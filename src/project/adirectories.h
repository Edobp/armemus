#ifndef ADirectories_H
#define ADirectories_H

#include "aincludes.h"
#include "adefinitions.h"

namespace Ui {
class adirectories;
}

class adirectories : public QDialog
{
    Q_OBJECT

public:
    explicit adirectories(QWidget *parent = 0);
    ~adirectories();

    QString getFolderPath();

private slots:
    void on_toolButton_clicked();

private:
    Ui::adirectories *ui;
};

#endif // ADirectories_H
