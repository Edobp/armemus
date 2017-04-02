/********************************************************************************
** Form generated from reading UI file 'aproject.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROJECT_H
#define UI_APROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aproject
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalTab1Layout;
    QGridLayout *gridLogoLayout;
    QLabel *logoLabel;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *pathLineEdit;
    QPushButton *browseButton;
    QLabel *textInfo;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *nameLineEdit;
    QLabel *createLabel;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridPathLayout;
    QPushButton *nextButton;
    QPushButton *cancelButton1;
    QSpacerItem *horizontalSpacer;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalTab2Layout;
    QGridLayout *gridLayout_7;
    QColumnView *columnView;
    QLabel *logoLabel_3;
    QGridLayout *gridLayout_6;
    QLabel *textInfo_3;
    QSpacerItem *verticalSpacer_6;
    QPushButton *cancelButton2;
    QLabel *boardLabel;
    QPushButton *backButton;
    QComboBox *boardComboBox;
    QSpacerItem *verticalSpacer_5;
    QPushButton *finishButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *aproject)
    {
        if (aproject->objectName().isEmpty())
            aproject->setObjectName(QStringLiteral("aproject"));
        aproject->resize(575, 392);
        gridLayout_5 = new QGridLayout(aproject);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabWidget = new QTabWidget(aproject);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabBarAutoHide(true);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        gridLayout_2 = new QGridLayout(tab1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalTab1Layout = new QHBoxLayout();
        horizontalTab1Layout->setSpacing(6);
        horizontalTab1Layout->setObjectName(QStringLiteral("horizontalTab1Layout"));
        gridLogoLayout = new QGridLayout();
        gridLogoLayout->setSpacing(6);
        gridLogoLayout->setObjectName(QStringLiteral("gridLogoLayout"));
        gridLogoLayout->setVerticalSpacing(0);
        logoLabel = new QLabel(tab1);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy);
        logoLabel->setMaximumSize(QSize(220, 118));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/armemus/logo.png")));
        logoLabel->setScaledContents(true);

        gridLogoLayout->addWidget(logoLabel, 0, 3, 1, 1);

        tableWidget = new QTableWidget(tab1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLogoLayout->addWidget(tableWidget, 1, 3, 1, 1);


        horizontalTab1Layout->addLayout(gridLogoLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        nameLabel = new QLabel(tab1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setLayoutDirection(Qt::LeftToRight);
        nameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 2, 0, 1, 1);

        pathLineEdit = new QLineEdit(tab1);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pathLineEdit->sizePolicy().hasHeightForWidth());
        pathLineEdit->setSizePolicy(sizePolicy2);
        pathLineEdit->setMinimumSize(QSize(150, 22));
        pathLineEdit->setMaximumSize(QSize(177, 22));
        pathLineEdit->setReadOnly(false);

        gridLayout->addWidget(pathLineEdit, 3, 1, 1, 1);

        browseButton = new QPushButton(tab1);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        sizePolicy2.setHeightForWidth(browseButton->sizePolicy().hasHeightForWidth());
        browseButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(browseButton, 3, 2, 1, 1);

        textInfo = new QLabel(tab1);
        textInfo->setObjectName(QStringLiteral("textInfo"));

        gridLayout->addWidget(textInfo, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 3);

        nameLineEdit = new QLineEdit(tab1);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        sizePolicy2.setHeightForWidth(nameLineEdit->sizePolicy().hasHeightForWidth());
        nameLineEdit->setSizePolicy(sizePolicy2);
        nameLineEdit->setMinimumSize(QSize(177, 22));
        nameLineEdit->setMaximumSize(QSize(268, 22));

        gridLayout->addWidget(nameLineEdit, 2, 1, 1, 2);

        createLabel = new QLabel(tab1);
        createLabel->setObjectName(QStringLiteral("createLabel"));
        sizePolicy1.setHeightForWidth(createLabel->sizePolicy().hasHeightForWidth());
        createLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(createLabel, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);

        verticalLayout->addLayout(gridLayout);

        gridPathLayout = new QGridLayout();
        gridPathLayout->setSpacing(6);
        gridPathLayout->setObjectName(QStringLiteral("gridPathLayout"));
        nextButton = new QPushButton(tab1);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setEnabled(false);
        sizePolicy2.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy2);
        nextButton->setAutoDefault(true);

        gridPathLayout->addWidget(nextButton, 0, 1, 1, 1);

        cancelButton1 = new QPushButton(tab1);
        cancelButton1->setObjectName(QStringLiteral("cancelButton1"));
        sizePolicy2.setHeightForWidth(cancelButton1->sizePolicy().hasHeightForWidth());
        cancelButton1->setSizePolicy(sizePolicy2);

        gridPathLayout->addWidget(cancelButton1, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridPathLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridPathLayout);


        horizontalTab1Layout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalTab1Layout, 2, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        verticalLayout_4 = new QVBoxLayout(tab2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalTab2Layout = new QHBoxLayout();
        horizontalTab2Layout->setSpacing(6);
        horizontalTab2Layout->setObjectName(QStringLiteral("horizontalTab2Layout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        columnView = new QColumnView(tab2);
        columnView->setObjectName(QStringLiteral("columnView"));
        sizePolicy.setHeightForWidth(columnView->sizePolicy().hasHeightForWidth());
        columnView->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(columnView, 1, 0, 1, 1);

        logoLabel_3 = new QLabel(tab2);
        logoLabel_3->setObjectName(QStringLiteral("logoLabel_3"));
        sizePolicy.setHeightForWidth(logoLabel_3->sizePolicy().hasHeightForWidth());
        logoLabel_3->setSizePolicy(sizePolicy);
        logoLabel_3->setMaximumSize(QSize(220, 118));
        logoLabel_3->setPixmap(QPixmap(QString::fromUtf8(":/armemus/logo.png")));
        logoLabel_3->setScaledContents(true);

        gridLayout_7->addWidget(logoLabel_3, 0, 0, 1, 1);


        horizontalTab2Layout->addLayout(gridLayout_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        textInfo_3 = new QLabel(tab2);
        textInfo_3->setObjectName(QStringLiteral("textInfo_3"));

        gridLayout_6->addWidget(textInfo_3, 0, 1, 1, 4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 4, 1, 1, 1);

        cancelButton2 = new QPushButton(tab2);
        cancelButton2->setObjectName(QStringLiteral("cancelButton2"));

        gridLayout_6->addWidget(cancelButton2, 5, 4, 1, 1);

        boardLabel = new QLabel(tab2);
        boardLabel->setObjectName(QStringLiteral("boardLabel"));

        gridLayout_6->addWidget(boardLabel, 3, 1, 1, 1);

        backButton = new QPushButton(tab2);
        backButton->setObjectName(QStringLiteral("backButton"));

        gridLayout_6->addWidget(backButton, 5, 1, 1, 1);

        boardComboBox = new QComboBox(tab2);
        boardComboBox->setObjectName(QStringLiteral("boardComboBox"));

        gridLayout_6->addWidget(boardComboBox, 3, 3, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 1, 1, 1, 1);

        finishButton = new QPushButton(tab2);
        finishButton->setObjectName(QStringLiteral("finishButton"));
        finishButton->setEnabled(false);

        gridLayout_6->addWidget(finishButton, 5, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 3, 0, 1, 1);


        horizontalTab2Layout->addLayout(gridLayout_6);


        verticalLayout_4->addLayout(horizontalTab2Layout);

        tabWidget->addTab(tab2, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(nameLineEdit, pathLineEdit);
        QWidget::setTabOrder(pathLineEdit, browseButton);
        QWidget::setTabOrder(browseButton, nextButton);
        QWidget::setTabOrder(nextButton, cancelButton1);

        retranslateUi(aproject);

        tabWidget->setCurrentIndex(1);
        browseButton->setDefault(true);
        nextButton->setDefault(true);
        cancelButton1->setDefault(true);
        finishButton->setDefault(true);


        QMetaObject::connectSlotsByName(aproject);
    } // setupUi

    void retranslateUi(QDialog *aproject)
    {
        aproject->setWindowTitle(QApplication::translate("aproject", "New ARMEmuS Project", 0));
        logoLabel->setText(QString());
        nameLabel->setText(QApplication::translate("aproject", "Name:", 0));
        browseButton->setText(QApplication::translate("aproject", "Browse...", 0));
        textInfo->setText(QApplication::translate("aproject", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Project Location</span></p></body></html>", 0));
        createLabel->setText(QApplication::translate("aproject", "Create in:", 0));
        nextButton->setText(QApplication::translate("aproject", "&Next >", 0));
        cancelButton1->setText(QApplication::translate("aproject", "Cancel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("aproject", "Tab 1", 0));
        logoLabel_3->setText(QString());
        textInfo_3->setText(QApplication::translate("aproject", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Board</span></p></body></html>", 0));
        cancelButton2->setText(QApplication::translate("aproject", "Cancel", 0));
        boardLabel->setText(QApplication::translate("aproject", "Board:", 0));
        backButton->setText(QApplication::translate("aproject", "< &Back", 0));
        boardComboBox->clear();
        boardComboBox->insertItems(0, QStringList()
         << QString()
        );
        finishButton->setText(QApplication::translate("aproject", "&Finish", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("aproject", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class aproject: public Ui_aproject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROJECT_H
