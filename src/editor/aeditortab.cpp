#include "aeditortab.h"
#include "ui_aeditortab.h"

aeditortab::aeditortab(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aeditortab)
{
    ui->setupUi(this);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &aeditortab::tabCloseRequested);
}

aeditortab::~aeditortab()
{
    delete ui;
}

void aeditortab::newFile()
{
    QFont font;
    aeditor *editor = createAEditor();

    font.setFamily("Babel");
    font.setFixedPitch(true);
    font.setPointSize(11);

    editor->setFont(font);
    editor->newFile();

    highlighter = new Highlighter(editor->document());
    textEdit = qobject_cast<QTextEdit*>(ui->tabWidget->currentWidget());

    ui->tabWidget->insertTab(ui->tabWidget->count(),editor,QString(editor->userFriendlyCurrentFile()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    connect(editor->document(), &QTextDocument::contentsChanged, this, &aeditortab::asterisk);
}


bool aeditortab::openFile(const QString &fileName)
{
    if (findFile(fileName)) {
        ui->tabWidget->setCurrentIndex(findTab);
        return true;
    }

    const bool succeeded = loadFile(fileName);

    return succeeded;
}

bool aeditortab::findFile(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();
    if(!fileName.isEmpty()){
        for(int i=0;i < ui->tabWidget->count();i++)
        {
            aeditor *editor = qobject_cast<aeditor *>(ui->tabWidget->widget(i));
            if (editor->currentFile() == canonicalFilePath){
                findTab = i;
                return true;
            }
        }
    }
      return 0;
}


bool aeditortab::loadFile(const QString &fileName)
{
    QFont font;
    aeditor *editor = createAEditor();

    ui->tabWidget->insertTab(ui->tabWidget->count(),editor,QFileInfo(fileName).fileName());
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    font.setFamily("Babel");
    font.setFixedPitch(true);
    font.setPointSize(11);
    editor->setFont(font);

    highlighter = new Highlighter(editor->document());
    textEdit = qobject_cast<aeditor*>(ui->tabWidget->currentWidget());

    connect(editor->document(), &QTextDocument::contentsChanged, this, &aeditortab::asterisk);

    const bool succeeded = editor->loadFile(fileName);
    if (succeeded)
        editor->show();
    else
        editor->close();

    //armemus::prependToRecentFiles(fileName);

    return succeeded;
}


void aeditortab::asterisk()
{
    aeditor *editor = activeAEditor();

    if(editor->isFileLoad()){
        QString nameFile = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
        if(nameFile.endsWith("*"))
           ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),nameFile);
        else
           ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),nameFile.insert(nameFile.size(),"*"));
    }

    editor->isFileLoad(true);
}

aeditor *aeditortab::activeAEditor()
{
    if ((ui->tabWidget->currentWidget()) != NULL)
        return qobject_cast<aeditor *>(ui->tabWidget->currentWidget());
    return 0;
}

aeditor *aeditortab::createAEditor()
{
    aeditor *editor = new aeditor;

#ifndef QT_NO_CLIPBOARD
    //connect(editor, &QTextEdit::copyAvailable, ui->action_Cut, &QAction::setEnabled);
    //connect(editor, &QTextEdit::copyAvailable, ui->action_Copy, &QAction::setEnabled);
#endif

    return editor;
}

void aeditortab::tabCloseRequested()
{
    tabClose();
}

void aeditortab::tabClose()
{
    aeditor *editor = activeAEditor();

    bool close = editor->closeEditor();

    if( close ){
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    }

}
