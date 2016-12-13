#include "adebug.h"

adebug::adebug()
{
    debug = new QProcess;

    connect(debug, &QProcess::readyReadStandardOutput, this, &adebug::output);
    connect(debug, &QProcess::readyReadStandardError, this, &adebug::output);

    //ui->TablaRegistros->addTopLevelItems(Lista_Registros);
}

void adebug::run()
{
    debug->start("arm-none-eabi-gdb");

    debug->write("target remote :1234\n");
    debug->write("file /home/andres/workspace/blinky/Debug/blinky.elf\n");
    debug->write("y\n");
    debug->write("load\n");

    debug->write("info registers\n");

    debug->write("quit\n");

    debug->waitForFinished();
}

void adebug::output()
{
    QRegExp rx("(r)(\\d)+\\s+(0x)\\d+");

    QString output (debug->readAllStandardOutput());

    if (output.contains(rx)){
        rx.indexIn(output);
        QStringList listReg = rx.capturedTexts();
        qDebug() << listReg.first();
        registersList.append(new QTreeWidgetItem(QStringList(listReg.first())));
    }

}
