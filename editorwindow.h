#ifndef EDITOR_W_H
#define EDITOR_W_H

#include <QMainWindow>

namespace Ui {
class Editor_W;
}

class Editor_W : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor_W(QWidget *parent = 0);
    ~Editor_W();

private slots:
    void on_actionBuild_triggered();

private:
    Ui::Editor_W *ui;
};

#endif // EDITOR_W_H
