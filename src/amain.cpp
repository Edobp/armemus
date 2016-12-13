#include "armemus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    armemus w;

    w.setWindowTitle(APROJECT_NAME);
    w.showMaximized();

    return a.exec();
}
