/*
 * ARMEmuS editor
 *
 * Copyright (c) 2017 ARMEmuS
 *
 * Authors:
 *  Sebastian Marin Velasquez  <jhoanmarin89@hotmail.com>
 *  Nataly Vanegas Restrepo  <nvanegasr@uqvirtual.edu.co>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef Aeditor_H
#define Aeditor_H

#include "aincludes.h"
#include "adefinitions.h"

#include "textedit.h"

class aeditor : public TextEdit
{
    Q_OBJECT

public:
    aeditor();

    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile();
    QString currentFile() { return curFile; }
    bool isFileLoad();
    void isFileLoad(bool load);
    bool closeEditor();    

protected:

private slots:
    void documentWasModified();

private:
    bool maybeSave();    
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
    bool isLoad;
};
#endif // Aeditor_H
