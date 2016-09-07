#include "armemus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    armemus w;
    w.setWindowState((w.windowState() & ~(Qt::WindowMinimized |
                                      Qt::WindowFullScreen)) | Qt::WindowMaximized);
    w.show();

    return a.exec();
}
