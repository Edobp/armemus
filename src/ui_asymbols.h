/********************************************************************************
** Form generated from reading UI file 'asymbols.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASYMBOLS_H
#define UI_ASYMBOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_asymbols
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditSymbol;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *asymbols)
    {
        if (asymbols->objectName().isEmpty())
            asymbols->setObjectName(QStringLiteral("asymbols"));
        asymbols->resize(400, 156);
        verticalLayout = new QVBoxLayout(asymbols);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEditSymbol = new QLineEdit(asymbols);
        lineEditSymbol->setObjectName(QStringLiteral("lineEditSymbol"));

        verticalLayout->addWidget(lineEditSymbol);

        buttonBox = new QDialogButtonBox(asymbols);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(asymbols);
        QObject::connect(buttonBox, SIGNAL(accepted()), asymbols, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), asymbols, SLOT(reject()));

        QMetaObject::connectSlotsByName(asymbols);
    } // setupUi

    void retranslateUi(QDialog *asymbols)
    {
        asymbols->setWindowTitle(QApplication::translate("asymbols", "Add Symbol", 0));
    } // retranslateUi

};

namespace Ui {
    class asymbols: public Ui_asymbols {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASYMBOLS_H
