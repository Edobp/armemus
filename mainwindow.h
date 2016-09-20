#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"board_w.h"
#include"editor_w.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    Board_W Board;
    Editor_W Editor;
};

#endif // MAINWINDOW_H
