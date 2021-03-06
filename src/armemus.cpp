#include "armemus.h"
#include "ui_armemus.h"

#include <QScrollBar>
#include <QStandardPaths>

armemus::armemus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::armemus)
{
    ui->setupUi(this);

    /****************************************
     *  Connects signals - slots ARMEmuS App
     ****************************************/

    //Cierra conexión generada por el error

    QProcess closeConnection;

    closeConnection.start("bash",QStringList()<<"-c"<<"fuser -k 1234/tcp");
    closeConnection.waitForFinished(-1);
    closeConnection.close();

    //--------------------------------------------------

    connect(ui->actionNew, &QAction::triggered, this, &armemus::actionNew);
    connect(ui->actionOpen, &QAction::triggered, this, &armemus::actionOpen);
    connect(ui->actionSave, &QAction::triggered, this, &armemus::actionSave);
    connect(ui->actionCloseProject, &QAction::triggered, this, &armemus::actionCloseProject);

    connect(ui->actionHelp, &QAction::triggered, this, &armemus::actionHelp);
    connect(ui->actionAbout, &QAction::triggered, this, &armemus::actionAbout);
    connect(ui->actionExit, &QAction::triggered, this, &armemus::actionExit);
    connect(ui->actionBuildOptions, &QAction::triggered, this, &armemus::actionBuildOptions);

    connect(ui->actionNewFile, &QAction::triggered, this, &armemus::actionNewFile);
    connect(ui->actionOpenFile, &QAction::triggered, this, &armemus::actionOpenFile);
    connect(ui->actionCloseFile, &QAction::triggered, this, &armemus::actionCloseFile);

    connect(ui->actionBuild, &QAction::triggered, this, &armemus::actionBuild);
    connect(ui->actionPlay, &QAction::triggered, this, &armemus::actionPlay);
    connect(ui->actionStop, &QAction::triggered, this, &armemus::actionStop);

    existProject = false;

    DisableButtons();
    loadBoards();
    project = new aproject(this, boards);

    IOBoard.clear();

    BuildProcess.setProcessChannelMode(QProcess::MergedChannels);
    QemuProcess.setProcessChannelMode(QProcess::MergedChannels);

    //-----------------------------------------------    

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &armemus::connected);
    connect(socket, &QTcpSocket::disconnected, this, &armemus::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &armemus::readyRead);
    //connect(socket, &QTcpSocket::bytesWritten, this, &armemus::bytesWritten);
}


armemus::~armemus()
{
    delete ui;
}

void armemus::actionNew()
{
    update_editorStatus();

    if (existProject){

        if(QemuProcess.isOpen())
            emit actionStop();
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Do you want to close this project and to create a new project?"));

        switch (sel) {
        case QMessageBox::Yes:
            if(confirmSave())
                break;
            else
                return;
        case QMessageBox::No:
            return;
        default:
            break;
        }
        clearWorkspace();

    }

    project->clear();
    project->exec();
    project->getInfo(projectInfo);
    project->getFilePath(FileBoard);
    if (!projectInfo.name.isEmpty() && !projectInfo.path.isEmpty())
        setWorkspace();

}


void armemus::actionNewFile()
{
    editor->newFile();

}

void armemus::actionOpen()
{
    update_editorStatus();

    if (existProject){

        if(QemuProcess.isOpen())
            emit actionStop();
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Do you want to close this project and open another one?"));

        switch (sel) {
        case QMessageBox::Yes:
            if(confirmSave())
                break;
            else
                return;
        case QMessageBox::No:
            return;
        default:
            break;
        }

        clearWorkspace();

    }    

    QString projectName = QFileDialog::getOpenFileName(this, tr("Open Proyect"),
                                                            QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last(),
                                                            tr("Proyect Files (*.apf)"));

    if(projectName.isEmpty())
        return;

    QFile file(projectName);

    file.open(QFile::ReadOnly);

    QXmlStreamReader xmlReader(file.readAll());
    file.close();    

    while(!xmlReader.atEnd()){
        xmlReader.readNext();
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="Path")
                projectInfo.path=xmlReader.attributes().first().value().toString();
            if(xmlReader.name()=="Name")
                projectInfo.name=xmlReader.attributes().first().value().toString();
            if(xmlReader.name()=="Board")
                projectInfo.boardIndex=xmlReader.attributes().first().value().toInt();
            if(xmlReader.name()=="File_Path")
                FileBoard=xmlReader.attributes().first().value().toString();
        }
    }

    if(!projectInfo.name.isEmpty() && !projectInfo.path.isEmpty())
        setWorkspace();

    ui->actionBuild->setEnabled(true);

}

void armemus::actionOpenFile()
{
    const QString fileName = QFileDialog::getOpenFileName(this);

    if (!fileName.isEmpty())
        editor->openFile(fileName);
}

bool armemus::actionSave()
{
    update_editorStatus();

    if(editorStatus[1]){
        editor->findtabUnsaved(tabUnsaved);
        if(editor->save())
            return this->actionSave();
        else
            return false;
    }

    statusBar()->showMessage(tr("Project saved"), 3000);
    ui->actionBuild->setEnabled(true);
    return true;
}

void armemus::actionHelp()
{
    QMessageBox Help (this);

    Help.information(this,tr("Help"),tr("Help Menu"));
}

void armemus::actionAbout()

{
    QMessageBox About(this);

    QLabel link;
    link.setText(APROJECT_NAME"<br>Icons:<a href=\"https://snwh.org/paper/\">Paper Icons</a></br> by Sam Hewitt");
    link.setOpenExternalLinks(true);

    About.about(this,tr("About " APROJECT_NAME), link.text());
}

void armemus::actionExit()
{
    this->close();
}


void armemus::actionBuildOptions()
{
    abuild *buildOptions = new abuild(this, projectInfo.path, projectInfo.name);
    buildOptions->setModal(true);
    buildOptions->show();
}

void armemus::actionBuild()
{        
    if(QemuProcess.isOpen())
        emit actionStop();

    ui->actionPlay->setEnabled(false);

    BuildProcess.setProcessChannelMode(QProcess::MergedChannels);
    connect(&BuildProcess, &QProcess::readyRead, this, &armemus::printProcess);
    connect(&BuildProcess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &armemus::closeProcess);

    outputBrowser->clear();

    QString root = "/home/malo";
    QString ABuilder = "/Escritorio/Builders/Arduino Builder/";

    QString path_File(FileBoard);
    QString path_Build = projectInfo.path+"/"+projectInfo.name+"/Build";

    switch (projectInfo.boardIndex) {
    case ArduinoDue:
        BuildProcess.start(root+ABuilder+"arduino-builder", QStringList()<<"-compile"<<"-logger"<<"machine"<<"-hardware"<<root+ABuilder+"hardware"<<"-hardware"<<root+ABuilder+"arduino-packages/packages"<<"-tools"<<root+ABuilder+"tools-builder"<<"-tools"<<root+ABuilder+"hardware/tools/avr"<<"-tools"<<root+ABuilder+"arduino-packages/packages"<<"-built-in-libraries"<<root+ABuilder+"libraries"<<"-libraries"<<root+ABuilder+"Arduino/libraries"<<"-fqbn"<<"arduino:sam:arduino_due_x"<<"-build-path"<<path_Build<<"-warnings"<<"none"<<"-prefs"<<"build.warn_data_percentage=75"<<"-prefs"<<"-runtime.tools.bossac.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/bossac/1.6.1-arduino"<<"-prefs"<<"runtime.tools.arm-none-eabi-gcc.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1"<<"-verbose"<<path_File);
        break;
    case ArduinoZero:
        BuildProcess.start(root+ABuilder+"arduino-builder", QStringList()<<"-compile"<<"-logger"<<"machine"<<"-hardware"<<root+ABuilder+"hardware"<<"-hardware"<<root+ABuilder+"arduino-packages/packages"<<"-tools"<<root+ABuilder+"tools-builder"<<"-tools"<<root+ABuilder+"hardware/tools/avr"<<"-tools"<<root+ABuilder+"arduino-packages/packages"<<"-built-in-libraries"<<root+ABuilder+"libraries"<<"-libraries"<<root+ABuilder+"Arduino/libraries"<<"-fqbn"<<"arduino:samd:arduino_zero_native"<<"-build-path"<<path_Build<<"-warnings"<<"none"<<"-prefs"<<"build.warn_data_percentage=75"<<"-prefs"<<"-runtime.tools.bossac.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/bossac/1.7.0"<<"-prefs"<<"runtime.tools.arm-none-eabi-gcc.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1"<<"-prefs"<<"runtime.tools.openocd.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/openocd/0.9.0-arduino"<<"-prefs"<<"runtime.tools.CMSIS.path="+root+ABuilder+"arduino-packages/packages/arduino/tools/CMSIS/4.0.0-atmel"<<"-verbose"<<path_File);
        break;
    case Tiva:
        //se debe cambiar en el archivo Makefile del resource la linea
        //TIVAWARE_PATH = /home/malo/Escritorio/Builders/SW-EK-TM4C123GXL
        BuildProcess.start("make", QStringList()<<"-C"<<projectInfo.path+"/"+projectInfo.name+"/"+projectInfo.name);
        break;
    default:
        break;
    }    
}

void armemus::actionPlay()
{

    ui->actionStop->setEnabled(true);
    ui->actionPlay->setEnabled(false);    

    tabs->setCurrentIndex(1);


    outputBrowser->clear();

    //Qemu debe estar en el home
    QemuProcess.setWorkingDirectory(QStandardPaths::standardLocations(QStandardPaths::HomeLocation).last());

    QString File; //file that will be executed in the mcu

    switch (projectInfo.boardIndex) {
    case ArduinoDue:
        File=projectInfo.path+"/"+projectInfo.name+"/Build/"+projectInfo.name+".ino.elf";
        QemuProcess.start("qemu-armemus/qemu-system-gnuarmeclipse", QStringList()<<"--mcu"<<"SAM3X8E"<<"--gdb"<<"tcp::1234"<<"-L"<<"qemu-armemus/"<<"--verbose"<<"--verbose");
        break;
    case ArduinoZero:
        File=projectInfo.path+"/"+projectInfo.name+"/Build/"+projectInfo.name+".ino.elf";
        QemuProcess.start("qemu-armemus/qemu-system-gnuarmeclipse", QStringList()<<"--mcu"<<"SAMD21G18"<<"--gdb"<<"tcp::1234"<<"-L"<<"qemu-armemus/"<<"--verbose"<<"--verbose");
        break;
    case Tiva:
        //se debe cambiar en el archivo Makefile del resource la linea
        //TIVAWARE_PATH = /home/malo/Escritorio/Builders/SW-EK-TM4C123GXL
        File=projectInfo.path+"/"+projectInfo.name+"/Build/"+"main.elf";
        QemuProcess.start("qemu-armemus/qemu-system-gnuarmeclipse", QStringList()<<"--mcu"<<"TM4C123GH6PM"<<"--gdb"<<"tcp::1234"<<"-L"<<"qemu-armemus/"<<"--verbose"<<"--verbose");
        break;
    default:
        break;
    }

    QemuProcess.waitForStarted(-1);

    QString command="--eval-command";

    GDBprocess.start("arm-none-eabi-gdb",QStringList()<<command<<"target remote :1234"<<command<<"load"<<File<<command<<"c");

    GDBprocess.waitForStarted(-1);

    QemuProcess.waitForBytesWritten(-1);
    QemuProcess.waitForReadyRead(-1);

    connect(&QemuProcess, &QProcess::readyRead, this, &armemus::printProcess);
    //connect(&QemuProcess, &QProcess::readyRead, this, &armemus::tcpPrinter);
    connect(&QemuProcess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &armemus::closeProcess);

    connect(board->Painter, &apainter::printInputpin, this, &armemus::printInputpin);

    board->turnOn();

    tcpConection(); //conexion tcp, debe haber soporte en QEMU para la conexion
}

void armemus::actionStop()
{    
    socket->disconnectFromHost();
    while(socket->state()!=QAbstractSocket::UnconnectedState){
        socket->disconnectFromHost();
    }

    QemuProcess.close();
    GDBprocess.close();

    disconnect(&QemuProcess, &QProcess::readyRead, this, &armemus::printProcess);
    disconnect(&QemuProcess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &armemus::closeProcess);


    ui->actionPlay->setEnabled(true);
    ui->actionStop->setEnabled(false);

    disconnect(board->Painter, &apainter::printInputpin, this, &armemus::printInputpin);
    board->turnOff();
}

void armemus::actionCloseProject()
{
    update_editorStatus();

    if(editorStatus[0])
        if(!confirmSave())
            return;

    clearWorkspace();
}

void armemus::actionCloseFile()
{
    editor->tabClose();
}

void armemus::loadBoards()
{
    QFile fileBoards(":/boards/boards.txt");
    fileBoards.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&fileBoards);
    Board board;

    while (!in.atEnd()) {
        in >> board.name >> board.image;
        if( !board.name.isEmpty() )
            boards.append(board);
    }
}

//Workspace settings

inline void armemus::clearWorkspace(){

    existProject=false;
    DisableButtons();
    delete outputBrowser;
    //delete editor;
    board->Painter->clear();
    delete board->Painter;
    delete board;
    delete tabs;
    IOBoard.clear();    
}


inline void armemus::DisableButtons()
{

    //menu
    ui->actionNewFile->setEnabled(false);
    ui->actionOpenFile->setEnabled(false);
    ui->actionCloseFile->setEnabled(false);
    ui->actionCloseProject->setEnabled(false);
    ui->actionBuildOptions->setEnabled(false);

    //toolbar
    ui->actionSave->setEnabled(false);
    ui->actionBuild->setEnabled(false);
    ui->actionPlay->setEnabled(false);
    ui->actionStop->setEnabled(false);
    ui->actionStep->setEnabled(false);
}

inline void armemus::setWorkspace()
{
    outputBrowser = new QTextBrowser;

    tabs = new QTabWidget;

    editor = new aeditortab(projectInfo.boardIndex);
    board = new aboardtab;
    IOBoard.setBoard(projectInfo.boardIndex);

    tabs->addTab(editor,"Code");
    tabs->addTab(board,"Board");

    ui->mainLayout->addWidget(tabs);
    ui->outputLayout->addWidget(outputBrowser);

    tabs->setCurrentIndex(0);    
    editor->openFile(FileBoard);

    if(board->loadFile(":/boards/"+boards[projectInfo.boardIndex].image))
        board->Painter->setBoard(&IOBoard);

    existProject = true;    

    ui->actionNewFile->setEnabled(true);
    ui->actionOpenFile->setEnabled(true);
    ui->actionCloseFile->setEnabled(true);
    ui->actionCloseProject->setEnabled(true);
    ui->actionBuildOptions->setEnabled(true);
    ui->actionSave->setEnabled(true);
}

void  armemus:: printProcess()

{
    QByteArray processReader;

    if(BuildProcess.isReadable()){
        processReader=BuildProcess.readAll();
        outputBrowser->insertPlainText(processReader);
    }

    else{           //if(QemuProcess.isReadable()){

        processReader=QemuProcess.readAll();

        if(processReader.contains("HIGH") || processReader.contains("LOW")){

            while(processReader.count('\n')){

                QByteArray singleLine(processReader.left(processReader.indexOf("\n")));
                processReader=processReader.mid(processReader.indexOf("\n")+1);

                int index=IOBoard.pinString.indexOf(singleLine.left(singleLine.indexOf(":")));

                if(index==-1 || index>=IOBoard.pinsboard.count())
                    continue;

                board->Painter->drawPin(singleLine, index);

                if(IOBoard.pinsboard[index].led!=-1)
                    board->Painter->drawLed(singleLine, IOBoard.pinsboard[index].led);

                outputBrowser->append(singleLine);
            }
        }
        else
            outputBrowser->insertPlainText(processReader);

    }

    outputBrowser->verticalScrollBar()->setValue(outputBrowser->verticalScrollBar()->maximum());
}


bool armemus::confirmSave()

{
    if(editorStatus[1]){
        const QMessageBox::StandardButton sel =
                QMessageBox::question(this,
                                      tr(APROJECT_NAME),
                                      tr("Some files have been modified\nDo you want to save before closing it?"));
        switch (sel) {
        case QMessageBox::Yes:
            if(!this->actionSave())
                return false;
        case QMessageBox::No:
            break;
        default:
            break;
        }
    }

    return true;
}

void armemus::closeProcess()
{
    if(BuildProcess.isOpen()){
        BuildProcess.close();
        disconnect(&BuildProcess, &QProcess::readyRead, this, &armemus::printProcess);
        disconnect(&BuildProcess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &armemus::closeProcess);
        ui->actionPlay->setEnabled(true);
    }

    if(QemuProcess.isOpen())
        emit actionStop();
}


void armemus::update_editorStatus(){


    if(existProject)
        editor->update_editorStatus(editorStatus, tabUnsaved);

    else{
        editorStatus[0]=false;
        editorStatus[1]=false;
    }


}


void armemus::printInputpin(int index, bool state)
{    
    QString inputLevelS(IOBoard.pinString.at(index));

    inputLevelS.insert(inputLevelS.indexOf(QRegExp("(-?\\d+(?:[\\.,]\\d+(?:e\\d+)?)?)")),":");

    if(state)
        inputLevelS.append(":1");
    else
        inputLevelS.append(":0");

    //statusBar()->showMessage(tr("%1 level at %2").arg(outputState).arg(IOBoard.pinString.at(index)), 1500);
    //statusBar()->showMessage(tr("Input at PIN %1").arg(index), 1500);

    inputLevel=inputLevelS.toUtf8();

    socket->write(inputLevel);

    //qDebug()<<inputLevel;
}



void armemus::closeEvent (QCloseEvent *event)
{
    update_editorStatus();

    if(QemuProcess.isOpen())
        emit actionStop();    

    if(existProject && editorStatus[0]){
        if(editorStatus[1]){
            if(confirmSave()){
                clearWorkspace();
                event->accept();
            }
            else
                event->ignore();
        }
    }
    else
        event->accept();
}


//--------------------------

/*void armemus::tcpPrinter()
{
    QByteArray reader;

    reader=QemuProcess.readAll();

    outputBrowser->append(reader);
}*/

void armemus::tcpConection()
{
    socket->connectToHost("localhost", 4321);
    while(!socket->waitForConnected()){
        //qDebug() << socket->error();
        socket->connectToHost("localhost", 4321);
    }


    /*while(!socket->waitForDisconnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
        //tcpConection();
        socket->connectToHost("localhost", 4321);
    }*/
}

void armemus::connected()
{
    //outputBrowser->clear();
    //outputBrowser->append("Connected!");

}

void armemus::readyRead()
{
    //qDebug() << "Reading...";
    //qDebug() << socket->readAll();
}

void armemus::disconnected()
{
    /*qDebug() << "Disconnected!";
    process.close();
    process.start("qemu-armemus/server");
    process.waitForStarted(-1);*/

}

