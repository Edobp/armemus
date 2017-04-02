/********************************************************************************
** Form generated from reading UI file 'abuild.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABUILD_H
#define UI_ABUILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abuild
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QListWidget *listDirectories;
    QWidget *tab_2;
    QToolButton *toolButton_3;
    QListWidget *listSymbols;
    QToolButton *toolButton_4;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QRadioButton *radioButtonW;
    QRadioButton *radioButtonWall;
    QRadioButton *radioButtonWerror;
    QWidget *tab_4;
    QComboBox *comboBoxOptimization;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *abuild)
    {
        if (abuild->objectName().isEmpty())
            abuild->setObjectName(QStringLiteral("abuild"));
        abuild->resize(431, 300);
        verticalLayout = new QVBoxLayout(abuild);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(abuild);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 190, 51, 21));
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(70, 190, 61, 21));
        listDirectories = new QListWidget(tab);
        listDirectories->setObjectName(QStringLiteral("listDirectories"));
        listDirectories->setGeometry(QRect(10, 10, 391, 171));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        toolButton_3 = new QToolButton(tab_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 190, 51, 21));
        listSymbols = new QListWidget(tab_2);
        listSymbols->setObjectName(QStringLiteral("listSymbols"));
        listSymbols->setGeometry(QRect(10, 10, 391, 171));
        toolButton_4 = new QToolButton(tab_2);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(70, 190, 61, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 351, 191));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        radioButtonW = new QRadioButton(groupBox);
        radioButtonW->setObjectName(QStringLiteral("radioButtonW"));
        radioButtonW->setGeometry(QRect(30, 30, 151, 20));
        radioButtonWall = new QRadioButton(groupBox);
        radioButtonWall->setObjectName(QStringLiteral("radioButtonWall"));
        radioButtonWall->setGeometry(QRect(30, 70, 181, 20));
        radioButtonWerror = new QRadioButton(groupBox);
        radioButtonWerror->setObjectName(QStringLiteral("radioButtonWerror"));
        radioButtonWerror->setGeometry(QRect(30, 110, 221, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        comboBoxOptimization = new QComboBox(tab_4);
        comboBoxOptimization->setObjectName(QStringLiteral("comboBoxOptimization"));
        comboBoxOptimization->setGeometry(QRect(80, 30, 211, 22));
        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(abuild);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(abuild);
        QObject::connect(buttonBox, SIGNAL(rejected()), abuild, SLOT(close()));
        QObject::connect(buttonBox, SIGNAL(accepted()), abuild, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(abuild);
    } // setupUi

    void retranslateUi(QDialog *abuild)
    {
        abuild->setWindowTitle(QApplication::translate("abuild", "Build Options", 0));
        toolButton->setText(QApplication::translate("abuild", "Add", 0));
        toolButton_2->setText(QApplication::translate("abuild", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("abuild", "Directories", 0));
        toolButton_3->setText(QApplication::translate("abuild", "Add", 0));
        toolButton_4->setText(QApplication::translate("abuild", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("abuild", "Symbols", 0));
        groupBox->setTitle(QApplication::translate("abuild", "GroupBox", 0));
        radioButtonW->setText(QApplication::translate("abuild", "No Warnings (-W)", 0));
        radioButtonWall->setText(QApplication::translate("abuild", "All Warnings (-Wall)", 0));
        radioButtonWerror->setText(QApplication::translate("abuild", "Warnings as errors (-Werror)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("abuild", "Warnings", 0));
        comboBoxOptimization->clear();
        comboBoxOptimization->insertItems(0, QStringList()
         << QApplication::translate("abuild", "-O0", 0)
         << QApplication::translate("abuild", "-O1", 0)
         << QApplication::translate("abuild", "-O2", 0)
         << QApplication::translate("abuild", "-O3", 0)
         << QApplication::translate("abuild", "-Os", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("abuild", "Optimization", 0));
    } // retranslateUi

};

namespace Ui {
    class abuild: public Ui_abuild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABUILD_H
