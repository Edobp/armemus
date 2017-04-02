/********************************************************************************
** Form generated from reading UI file 'aboardtab.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOARDTAB_H
#define UI_ABOARDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboardtab
{
public:
    QAction *actionBoard;
    QWidget *boardWidget;
    QGridLayout *boardGridLayout;
    QWidget *graphicWidget;
    QGridLayout *graphicGridLayout;
    QTabWidget *debugWidget;
    QWidget *registers;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QWidget *variables;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget_2;
    QWidget *peripherals;
    QGridLayout *gridLayout_3;
    QTreeWidget *treeWidget_3;

    void setupUi(QMainWindow *aboardtab)
    {
        if (aboardtab->objectName().isEmpty())
            aboardtab->setObjectName(QStringLiteral("aboardtab"));
        aboardtab->resize(667, 494);
        actionBoard = new QAction(aboardtab);
        actionBoard->setObjectName(QStringLiteral("actionBoard"));
        boardWidget = new QWidget(aboardtab);
        boardWidget->setObjectName(QStringLiteral("boardWidget"));
        boardGridLayout = new QGridLayout(boardWidget);
        boardGridLayout->setSpacing(0);
        boardGridLayout->setObjectName(QStringLiteral("boardGridLayout"));
        boardGridLayout->setContentsMargins(6, 6, 6, 6);
        graphicWidget = new QWidget(boardWidget);
        graphicWidget->setObjectName(QStringLiteral("graphicWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicWidget->sizePolicy().hasHeightForWidth());
        graphicWidget->setSizePolicy(sizePolicy);
        graphicGridLayout = new QGridLayout(graphicWidget);
        graphicGridLayout->setObjectName(QStringLiteral("graphicGridLayout"));
        graphicGridLayout->setContentsMargins(0, 0, 3, 0);

        boardGridLayout->addWidget(graphicWidget, 0, 0, 1, 1);

        debugWidget = new QTabWidget(boardWidget);
        debugWidget->setObjectName(QStringLiteral("debugWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(debugWidget->sizePolicy().hasHeightForWidth());
        debugWidget->setSizePolicy(sizePolicy1);
        registers = new QWidget();
        registers->setObjectName(QStringLiteral("registers"));
        gridLayout = new QGridLayout(registers);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(registers);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("Register"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setColumnCount(2);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        debugWidget->addTab(registers, QString());
        variables = new QWidget();
        variables->setObjectName(QStringLiteral("variables"));
        gridLayout_2 = new QGridLayout(variables);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget_2 = new QTreeWidget(variables);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("Name"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setColumnCount(2);

        gridLayout_2->addWidget(treeWidget_2, 0, 0, 1, 1);

        debugWidget->addTab(variables, QString());
        peripherals = new QWidget();
        peripherals->setObjectName(QStringLiteral("peripherals"));
        gridLayout_3 = new QGridLayout(peripherals);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        treeWidget_3 = new QTreeWidget(peripherals);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("Port"));
        treeWidget_3->setHeaderItem(__qtreewidgetitem2);
        treeWidget_3->setObjectName(QStringLiteral("treeWidget_3"));

        gridLayout_3->addWidget(treeWidget_3, 0, 0, 1, 1);

        debugWidget->addTab(peripherals, QString());

        boardGridLayout->addWidget(debugWidget, 0, 1, 1, 1);

        aboardtab->setCentralWidget(boardWidget);

        retranslateUi(aboardtab);

        debugWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(aboardtab);
    } // setupUi

    void retranslateUi(QMainWindow *aboardtab)
    {
        aboardtab->setWindowTitle(QApplication::translate("aboardtab", "MainWindow", 0));
        actionBoard->setText(QApplication::translate("aboardtab", "Board", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("aboardtab", "Value", 0));
        debugWidget->setTabText(debugWidget->indexOf(registers), QApplication::translate("aboardtab", "Registers", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("aboardtab", "Value", 0));
        debugWidget->setTabText(debugWidget->indexOf(variables), QApplication::translate("aboardtab", "Variables", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_3->headerItem();
        ___qtreewidgetitem2->setText(2, QApplication::translate("aboardtab", "Value", 0));
        ___qtreewidgetitem2->setText(1, QApplication::translate("aboardtab", "Direction", 0));
        debugWidget->setTabText(debugWidget->indexOf(peripherals), QApplication::translate("aboardtab", "Peripherals", 0));
    } // retranslateUi

};

namespace Ui {
    class aboardtab: public Ui_aboardtab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOARDTAB_H
