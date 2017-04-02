#include "aeditor.h"

aeditor::aeditor()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
}

void aeditor::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;
    curFile = tr("untitled%1").arg(sequenceNumber++);

    connect(document(), &QTextDocument::contentsChanged, this, &aeditor::documentWasModified);
}

void aeditor::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool aeditor::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool aeditor::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),curFile);
    if (fileName.isEmpty())
        return false;    
    return saveFile(fileName);
}

bool aeditor::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr(APROJECT_NAME),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}


bool aeditor::maybeSave()
{
    if (!document()->isModified())
        return true;

    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr(APROJECT_NAME),
                                   tr("'%1' has been modified.\n"
                                      "Do you want to save your changes?")
                                   .arg(userFriendlyCurrentFile()),
                                   QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}


void aeditor::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
}


bool aeditor::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr(APROJECT_NAME),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    connect(document(), &QTextDocument::contentsChanged,
            this, &aeditor::documentWasModified);

    return true;
}


QString aeditor::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

bool aeditor::closeEditor()
{
    if (maybeSave()) {
        this->close();
        return true;
    } else {
        return false;
    }
}

QString aeditor::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

bool aeditor::isFileLoad()
{
    return isLoad;
}

void aeditor::isFileLoad(bool load)
{
    isLoad = load;
}
