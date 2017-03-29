#ifndef ADebug_H
#define ADebug_H

#include "aincludes.h"
#include "adefinitions.h"

class adebug : public QTreeWidget
{
    Q_OBJECT

public:
    explicit adebug();
    void run();

private slots:
    void output();

private:
    QProcess* debug;

    QList<QTreeWidgetItem*> registersList;
};

#endif // ADebug_H
