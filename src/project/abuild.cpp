#include "abuild.h"
#include "ui_abuild.h"

#include <QXmlStreamWriter>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

#include <QDebug>
#include <cstdlib>
#include <iostream>


abuild::abuild(QWidget *parent, QString path, QString name) :
    QDialog(parent),
    ui(new Ui::abuild)
{
    ui->setupUi(this);

    projectPath = path;
    projectName = name;


    //read to Xml file

     QFile file(projectPath+"/"+projectName+"/"+projectName+".apf");
     if (file.open(QIODevice::ReadOnly)) {
         QXmlStreamReader reader(file.readAll());
         file.close();
         while(!reader.atEnd()) {
             reader.readNext();

             if (reader.isStartElement() && reader.name() == "Directory") {
                     foreach(const QXmlStreamAttribute &attr, reader.attributes()) {
                         if (attr.name().toString() == QLatin1String("add")) {
                             ui->listDirectories->addItem(attr.value().toString());
                         }

                    }
             }


             if (reader.isStartElement() && reader.name() == "Symbol") {
                     foreach(const QXmlStreamAttribute &attr, reader.attributes()) {
                         if (attr.name().toString() == QLatin1String("add")) {
                             ui->listSymbols->addItem(attr.value().toString());
                         }

                    }
             }

             if (reader.isStartElement() && reader.name() == "Warning") {
                     foreach(const QXmlStreamAttribute &attr, reader.attributes()) {
                         if (attr.name().toString() == QLatin1String("option")) {
                             if(attr.value().toString() == "-W")ui->radioButtonW->setChecked(true);
                             if(attr.value().toString() == "-Wall")ui->radioButtonWall->setChecked(true);
                             if(attr.value().toString() == "-Werror")ui->radioButtonWerror->setChecked(true);
                         }

                    }
             }

             if (reader.isStartElement() && reader.name() == "optimization") {
                     foreach(const QXmlStreamAttribute &attr, reader.attributes()) {
                         if (attr.name().toString() == QLatin1String("option")) {
                             ui->comboBoxOptimization->setCurrentText(attr.value().toString());
                         }

                    }
             }

         }

     if(reader.hasError()) {
                  QMessageBox::critical(this,
                  "xmlFile.xml Parse Error",reader.errorString(),
                  QMessageBox::Ok);
                  return;
          }


     //close reader and flush file
     reader.clear();
     }

     connect(ui->radioButtonW,SIGNAL(clicked()),this,SLOT(changeWarning()));
     connect(ui->radioButtonWall,SIGNAL(clicked()),this,SLOT(changeWarning()));
     connect(ui->radioButtonWerror,SIGNAL(clicked()),this,SLOT(changeWarning()));
}

abuild::~abuild()
{
    delete ui;
}

void abuild::on_toolButton_clicked()
{

    directoriesOptions = new adirectories(this);
    directoriesOptions->setModal(true);

    connect(directoriesOptions, &adirectories::accepted, this, &abuild::addListPath);

    directoriesOptions->show();

}

void abuild::addListPath()
{

    QString folderPath = directoriesOptions->getFolderPath();

    ui->listDirectories->addItem(folderPath);

    QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

        if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "unable to open xml file";

        }
        QByteArray xmlData(file->readAll());
        QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
        doc.setContent(xmlData);

        QDomElement directory = doc.createElement("Directory");
        directory.setAttribute("add",folderPath);

        QDomElement root = doc.firstChildElement("Armemus_Project_File");
        QDomElement parent = root.firstChildElement("Compiler");
        QDomElement child = parent.firstChildElement("Directories");

        child.appendChild(directory);

        file->resize(0);
        QTextStream stream(file);
        stream.setDevice(file);
        doc.save(stream, 4);
        file->close();


}



void abuild::on_toolButton_3_clicked()
{
    symbolsOptions = new asymbols(this);
    symbolsOptions->setModal(true);

    connect(symbolsOptions, SIGNAL(accepted()), this, SLOT(addSymbol()));

    symbolsOptions->show();

}

void abuild::addSymbol()
{
    QString Symbol = symbolsOptions->getSymbol();

    ui->listSymbols->addItem(Symbol);

    QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

        if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "unable to open xml file";

        }
        QByteArray xmlData(file->readAll());
        QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
        doc.setContent(xmlData);

        QDomElement Symboladd = doc.createElement("Symbol");
        Symboladd.setAttribute("add",Symbol);

        QDomElement root = doc.firstChildElement("Armemus_Project_File");
        QDomElement parent = root.firstChildElement("Compiler");
        QDomElement child = parent.firstChildElement("Symbols");

        child.appendChild(Symboladd);

        file->resize(0);
        QTextStream stream(file);
        stream.setDevice(file);
        doc.save(stream, 4);
        file->close();


}


void abuild::on_toolButton_2_clicked()
{

    QList<QListWidgetItem*> itemsD = ui->listDirectories->selectedItems();
    foreach(QListWidgetItem * itemD, itemsD)
    {


        QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

            if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
            {
                qDebug() << "unable to open xml file";

            }
            QByteArray xmlData(file->readAll());
            QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
            doc.setContent(xmlData);

            QDomNodeList domlist = doc.elementsByTagName("Directory");

            QString dirDelete = ui->listDirectories->takeItem(ui->listDirectories->row(itemD))->text();

            for (int i = 0; i < domlist.count(); ++i)
            {
                QDomNode node = domlist.at(i);
                QDomElement child = node.toElement();
                if (!child.isNull() && child.attribute("add") == dirDelete ){
                    node.parentNode().removeChild(child);
                }
            }


            file->resize(0);
            QTextStream stream(file);
            stream.setDevice(file);
            doc.save(stream, 4);
            file->close();

        delete ui->listDirectories->takeItem(ui->listDirectories->row(itemD));
        //ui->listDirectories->removeItemWidget(itemD);

    }
}


void abuild::on_toolButton_4_clicked()
{

    QList<QListWidgetItem*> itemsS = ui->listSymbols->selectedItems();
    foreach(QListWidgetItem * itemS, itemsS)
    {
        QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

            if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
            {
                qDebug() << "unable to open xml file";

            }
            QByteArray xmlData(file->readAll());
            QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
            doc.setContent(xmlData);

            QDomNodeList domlist = doc.elementsByTagName("Symbol");

            QString SymbolDelete = ui->listSymbols->takeItem(ui->listSymbols->row(itemS))->text();

            for (int i = 0; i < domlist.count(); ++i)
            {
                QDomNode node = domlist.at(i);
                QDomElement child = node.toElement();
                if (!child.isNull() && child.attribute("add") == SymbolDelete ){
                    node.parentNode().removeChild(child);                    
                }
            }


            file->resize(0);
            QTextStream stream(file);
            stream.setDevice(file);
            doc.save(stream, 4);
            file->close();

        delete ui->listSymbols->takeItem(ui->listSymbols->row(itemS));
    }

}

void abuild::changeWarning()
{

    QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

        if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "unable to open xml file";

        }
        QByteArray xmlData(file->readAll());
        QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
        doc.setContent(xmlData);

        QDomElement root = doc.firstChildElement("Armemus_Project_File");
        QDomElement parent = root.firstChildElement("Compiler");
        QDomElement child = parent.firstChildElement("Warnings");

        if (ui->radioButtonW->isChecked())child.firstChildElement("Warning").setAttribute("option","-W");
        if (ui->radioButtonWall->isChecked())child.firstChildElement("Warning").setAttribute("option","-Wall");
        if (ui->radioButtonWerror->isChecked())child.firstChildElement("Warning").setAttribute("option","-Werror");


        file->resize(0);
        QTextStream stream(file);
        stream.setDevice(file);
        doc.save(stream, 4);
        file->close();



}

void abuild::on_comboBoxOptimization_currentIndexChanged(const QString &arg1)
{


    QFile *file = new QFile(projectPath+"/"+projectName+"/"+projectName+".apf");

        if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            qDebug() << "unable to open xml file";

        }
        QByteArray xmlData(file->readAll());
        QDomDocument doc(projectPath+"/"+projectName+"/"+projectName+".apf");
        doc.setContent(xmlData);

        QDomElement root = doc.firstChildElement("Armemus_Project_File");
        QDomElement parent = root.firstChildElement("Compiler");
        QDomElement child = parent.firstChildElement("Optimization");

        child.firstChildElement("optimization").setAttribute("option",arg1);


        file->resize(0);
        QTextStream stream(file);
        stream.setDevice(file);
        doc.save(stream, 4);
        file->close();

}
