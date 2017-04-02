/********************************************************************************
** Form generated from reading UI file 'armemus.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMEMUS_H
#define UI_ARMEMUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_armemus
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionCloseProject;
    QAction *actionPlay;
    QAction *actionStop;
    QAction *actionStep;
    QAction *actionBuild;
    QAction *actionBuildOptions;
    QAction *actionNewFile;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionExit;
    QAction *actionCloseFile;
    QAction *actionRecent;
    QAction *actionA;
    QAction *action;
    QAction *actionOpenFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *mainWidget;
    QGridLayout *mainLayout;
    QWidget *outputWidget;
    QGridLayout *outputLayout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecent_Files;
    QMenu *menuRecent_P_rojects;
    QMenu *menuHelp;
    QMenu *menuBuild;
    QMenu *menuEdit;

    void setupUi(QMainWindow *armemus)
    {
        if (armemus->objectName().isEmpty())
            armemus->setObjectName(QStringLiteral("armemus"));
        armemus->resize(653, 449);
        armemus->setAutoFillBackground(false);
        armemus->setStyleSheet(QStringLiteral(""));
        actionNew = new QAction(armemus);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(armemus);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(armemus);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionHelp = new QAction(armemus);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionAbout = new QAction(armemus);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionCloseProject = new QAction(armemus);
        actionCloseProject->setObjectName(QStringLiteral("actionCloseProject"));
        actionPlay = new QAction(armemus);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionPlay->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon5);
        actionStop = new QAction(armemus);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon6);
        actionStep = new QAction(armemus);
        actionStep->setObjectName(QStringLiteral("actionStep"));
        actionStep->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/step.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon7);
        actionBuild = new QAction(armemus);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        actionBuild->setEnabled(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/build.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuild->setIcon(icon8);
        actionBuildOptions = new QAction(armemus);
        actionBuildOptions->setObjectName(QStringLiteral("actionBuildOptions"));
        actionNewFile = new QAction(armemus);
        actionNewFile->setObjectName(QStringLiteral("actionNewFile"));
        actionNewFile->setEnabled(true);
        actionCut = new QAction(armemus);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon9);
        actionPaste = new QAction(armemus);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon10);
        actionExit = new QAction(armemus);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon11);
        actionCloseFile = new QAction(armemus);
        actionCloseFile->setObjectName(QStringLiteral("actionCloseFile"));
        actionRecent = new QAction(armemus);
        actionRecent->setObjectName(QStringLiteral("actionRecent"));
        actionA = new QAction(armemus);
        actionA->setObjectName(QStringLiteral("actionA"));
        action = new QAction(armemus);
        action->setObjectName(QStringLiteral("action"));
        actionOpenFile = new QAction(armemus);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        centralWidget = new QWidget(armemus);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy);
        mainLayout = new QGridLayout(mainWidget);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(mainWidget);

        outputWidget = new QWidget(centralWidget);
        outputWidget->setObjectName(QStringLiteral("outputWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(outputWidget->sizePolicy().hasHeightForWidth());
        outputWidget->setSizePolicy(sizePolicy1);
        outputLayout = new QGridLayout(outputWidget);
        outputLayout->setSpacing(0);
        outputLayout->setContentsMargins(11, 11, 11, 11);
        outputLayout->setObjectName(QStringLiteral("outputLayout"));
        outputLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(outputWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        armemus->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(armemus);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        armemus->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(armemus);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        armemus->setStatusBar(statusBar);
        menuBar = new QMenuBar(armemus);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRecent_Files = new QMenu(menuFile);
        menuRecent_Files->setObjectName(QStringLiteral("menuRecent_Files"));
        menuRecent_P_rojects = new QMenu(menuFile);
        menuRecent_P_rojects->setObjectName(QStringLiteral("menuRecent_P_rojects"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuBuild = new QMenu(menuBar);
        menuBuild->setObjectName(QStringLiteral("menuBuild"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        armemus->setMenuBar(menuBar);

        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBuild);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionStep);
        mainToolBar->addSeparator();
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuBuild->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewFile);
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuRecent_Files->menuAction());
        menuFile->addAction(menuRecent_P_rojects->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionCloseProject);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionCloseFile);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuBuild->addAction(actionBuild);
        menuBuild->addAction(actionPlay);
        menuBuild->addAction(actionStop);
        menuBuild->addAction(actionStep);
        menuBuild->addAction(actionBuildOptions);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);

        retranslateUi(armemus);

        QMetaObject::connectSlotsByName(armemus);
    } // setupUi

    void retranslateUi(QMainWindow *armemus)
    {
        armemus->setWindowTitle(QApplication::translate("armemus", "MainWindow", 0));
        actionNew->setText(QApplication::translate("armemus", "New Project", 0));
        actionNew->setShortcut(QApplication::translate("armemus", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("armemus", "Open Project", 0));
        actionOpen->setShortcut(QApplication::translate("armemus", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("armemus", "Save", 0));
        actionSave->setShortcut(QApplication::translate("armemus", "Ctrl+S", 0));
        actionHelp->setText(QApplication::translate("armemus", "Help", 0));
        actionHelp->setShortcut(QApplication::translate("armemus", "F1", 0));
        actionAbout->setText(QApplication::translate("armemus", "About", 0));
        actionCloseProject->setText(QApplication::translate("armemus", "Close Project", 0));
        actionPlay->setText(QApplication::translate("armemus", "Play", 0));
        actionStop->setText(QApplication::translate("armemus", "Stop", 0));
        actionStep->setText(QApplication::translate("armemus", "Step", 0));
        actionBuild->setText(QApplication::translate("armemus", "Build", 0));
        actionBuildOptions->setText(QApplication::translate("armemus", "Build Options", 0));
        actionNewFile->setText(QApplication::translate("armemus", "New File", 0));
        actionNewFile->setShortcut(QApplication::translate("armemus", "Ctrl+Shift+N", 0));
        actionCut->setText(QApplication::translate("armemus", "Cu&t", 0));
        actionCut->setShortcut(QApplication::translate("armemus", "Ctrl+X", 0));
        actionPaste->setText(QApplication::translate("armemus", "&Paste", 0));
        actionPaste->setShortcut(QApplication::translate("armemus", "Ctrl+V", 0));
        actionExit->setText(QApplication::translate("armemus", "E&xit", 0));
        actionExit->setShortcut(QApplication::translate("armemus", "Ctrl+Q", 0));
        actionCloseFile->setText(QApplication::translate("armemus", "Close File", 0));
        actionCloseFile->setShortcut(QApplication::translate("armemus", "Ctrl+W", 0));
        actionRecent->setText(QApplication::translate("armemus", "Recent Files", 0));
        actionA->setText(QApplication::translate("armemus", "...", 0));
        action->setText(QApplication::translate("armemus", "...", 0));
        actionOpenFile->setText(QApplication::translate("armemus", "Open File", 0));
        actionOpenFile->setShortcut(QApplication::translate("armemus", "Ctrl+Shift+O", 0));
        menuFile->setTitle(QApplication::translate("armemus", "&File", 0));
        menuRecent_Files->setTitle(QApplication::translate("armemus", "Recent &Files", 0));
        menuRecent_P_rojects->setTitle(QApplication::translate("armemus", "Recent P&rojects", 0));
        menuHelp->setTitle(QApplication::translate("armemus", "&Help", 0));
        menuBuild->setTitle(QApplication::translate("armemus", "&Build", 0));
        menuEdit->setTitle(QApplication::translate("armemus", "&Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class armemus: public Ui_armemus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMEMUS_H
