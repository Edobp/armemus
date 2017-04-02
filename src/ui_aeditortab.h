/********************************************************************************
** Form generated from reading UI file 'aeditortab.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AEDITORTAB_H
#define UI_AEDITORTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aeditortab
{
public:
    QAction *actionBuild;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *aeditortab)
    {
        if (aeditortab->objectName().isEmpty())
            aeditortab->setObjectName(QStringLiteral("aeditortab"));
        aeditortab->resize(800, 600);
        actionBuild = new QAction(aeditortab);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        centralwidget = new QWidget(aeditortab);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        aeditortab->setCentralWidget(centralwidget);

        retranslateUi(aeditortab);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(aeditortab);
    } // setupUi

    void retranslateUi(QMainWindow *aeditortab)
    {
        aeditortab->setWindowTitle(QApplication::translate("aeditortab", "MainWindow", 0));
        actionBuild->setText(QApplication::translate("aeditortab", "Build", 0));
    } // retranslateUi

};

namespace Ui {
    class aeditortab: public Ui_aeditortab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AEDITORTAB_H
