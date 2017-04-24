#include "aeditortab.h"
#include "ui_aeditortab.h"

aeditortab::aeditortab(int Index, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aeditortab)
{
    ui->setupUi(this);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &aeditortab::tabCloseRequested);

    BoardIndex=Index;
    EditorSettings(BoardIndex);

    completer = new QCompleter(this);
    completer->setModel(modelFromFile(BoardKey));
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);

}

aeditortab::~aeditortab()
{
    delete ui;
}

void aeditortab::newFile()
{    
    aeditor *editor = createAEditor();

    editor->setFont(font);
    editor->newFile();
    editor->setCompleter(completer);

    highlighter = new Highlighter(BoardIndex,editor->document());
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

    aeditor *editor = createAEditor();

    ui->tabWidget->insertTab(ui->tabWidget->count(),editor,QFileInfo(fileName).fileName());    
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);        

    editor->setFont(font);
    editor->setCompleter(completer);

    highlighter = new Highlighter(BoardIndex, editor->document());
    textEdit = qobject_cast<aeditor*>(ui->tabWidget->currentWidget());    



    const bool succeeded = editor->loadFile(fileName);

    connect(editor->document(), &QTextDocument::contentsChanged, this, &aeditortab::asterisk);

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
    /*
        if(editor->isFileLoad()){

        }

    editor->isFileLoad(true);*/

    if(editor->isWindowModified()){
        QString nameFile = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
        if(nameFile.endsWith("*"))
           ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),nameFile);
        else
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),nameFile.insert(nameFile.size(),"*"));
    }
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


//-----------------------------------------------------

bool aeditortab::save()

{
    bool saveFile;

    aeditor *editor = activeAEditor();

    saveFile=editor->save();

    if(saveFile)
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),QFileInfo(editor->currentFile()).fileName());

    editor->setWindowModified(false);
    return saveFile;
}

void aeditortab::EditorSettings(int BoardIndex)
{
    switch (BoardIndex) {    
    case ArduinoDue:
    case ArduinoZero:
    case Feather:                
        font.setFamily("Monospaced");
        font.setFixedPitch(true);
        font.setPointSize(12);
        BoardKey=":/files/Arduino/autoComplete.txt";
        break;
    case Tiva:
        font.setFamily("Babel");
        font.setFixedPitch(true);
        font.setPointSize(11);
        BoardKey=":/files/Tiva/autoComplete.txt";
        break;
    default:
        break;
    }

}

void aeditortab::update_editorStatus(bool *editorStatus, int &tabUnsaved)
{


    if(ui->tabWidget->count()>0){

        editorStatus[0]=true;        

        for (int i=0; i<=ui->tabWidget->count();i++){
            if(ui->tabWidget->tabText(i).contains('*')){
                editorStatus[1]=true;
                tabUnsaved=i;
                break;
            }
            else{                
                editorStatus[1]=false;
                tabUnsaved=-1;
            }
        }
    }
    else{
        editorStatus[0]=false;  //confirma existencia de pestañas
        editorStatus[1]=false;  //confirma si hay archivos sin guardar
    }    
}

void aeditortab::findtabUnsaved(int tabIndex)
{
    ui->tabWidget->setCurrentIndex(tabIndex);
}

//Para completer

QAbstractItemModel *aeditortab::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, completer);
}
