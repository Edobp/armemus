/********************************************************************************
** Form generated from reading UI file 'adirectories.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADIRECTORIES_H
#define UI_ADIRECTORIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_adirectories
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditDirectories;
    QToolButton *toolButton;

    void setupUi(QDialog *adirectories)
    {
        if (adirectories->objectName().isEmpty())
            adirectories->setObjectName(QStringLiteral("adirectories"));
        adirectories->resize(400, 158);
        buttonBox = new QDialogButtonBox(adirectories);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEditDirectories = new QLineEdit(adirectories);
        lineEditDirectories->setObjectName(QStringLiteral("lineEditDirectories"));
        lineEditDirectories->setGeometry(QRect(30, 30, 321, 22));
        toolButton = new QToolButton(adirectories);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(360, 30, 28, 21));

        retranslateUi(adirectories);
        QObject::connect(buttonBox, SIGNAL(accepted()), adirectories, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), adirectories, SLOT(reject()));

        QMetaObject::connectSlotsByName(adirectories);
    } // setupUi

    void retranslateUi(QDialog *adirectories)
    {
        adirectories->setWindowTitle(QApplication::translate("adirectories", "Select File", 0));
        toolButton->setText(QApplication::translate("adirectories", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class adirectories: public Ui_adirectories {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADIRECTORIES_H
