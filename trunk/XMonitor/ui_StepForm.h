/********************************************************************************
** Form generated from reading UI file 'StepForm.ui'
**
** Created: Tue Mar 8 16:12:46 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPFORM_H
#define UI_STEPFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepFormClass
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *svrId;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_8;
    QLineEdit *seq;
    QLabel *label_4;
    QPlainTextEdit *desc;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *cmd;
    QPushButton *pushButton;
    QLabel *label_6;
    QLineEdit *cmdResult;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLineEdit *script;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *StepFormClass)
    {
        if (StepFormClass->objectName().isEmpty())
            StepFormClass->setObjectName(QString::fromUtf8("StepFormClass"));
        StepFormClass->resize(406, 247);
        verticalLayout = new QVBoxLayout(StepFormClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(StepFormClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QLineEdit(tab);
        id->setObjectName(QString::fromUtf8("id"));
        id->setReadOnly(true);

        gridLayout->addWidget(id, 0, 1, 1, 3);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        svrId = new QLineEdit(tab);
        svrId->setObjectName(QString::fromUtf8("svrId"));

        gridLayout->addWidget(svrId, 1, 1, 1, 3);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        name = new QLineEdit(tab);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 2, 1, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        seq = new QLineEdit(tab);
        seq->setObjectName(QString::fromUtf8("seq"));

        gridLayout->addWidget(seq, 2, 3, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        desc = new QPlainTextEdit(tab);
        desc->setObjectName(QString::fromUtf8("desc"));

        gridLayout->addWidget(desc, 3, 1, 1, 3);


        horizontalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        cmd = new QLineEdit(tab_2);
        cmd->setObjectName(QString::fromUtf8("cmd"));
        cmd->setReadOnly(true);

        gridLayout_2->addWidget(cmd, 0, 1, 1, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 2, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        cmdResult = new QLineEdit(tab_2);
        cmdResult->setObjectName(QString::fromUtf8("cmdResult"));
        cmdResult->setReadOnly(true);

        gridLayout_2->addWidget(cmdResult, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 2, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        script = new QLineEdit(tab_2);
        script->setObjectName(QString::fromUtf8("script"));
        script->setReadOnly(true);

        gridLayout_2->addWidget(script, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(StepFormClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StepFormClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StepFormClass);
    } // setupUi

    void retranslateUi(QWidget *StepFormClass)
    {
        StepFormClass->setWindowTitle(QApplication::translate("StepFormClass", "MyQtLog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StepFormClass", "ID: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StepFormClass", "Server ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StepFormClass", "Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StepFormClass", "Seq:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StepFormClass", "Description:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StepFormClass", "General", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StepFormClass", "Command:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("StepFormClass", "Edit...", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StepFormClass", "Result:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("StepFormClass", "Edit...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("StepFormClass", "Script:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("StepFormClass", "Eidt...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("StepFormClass", "Script", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StepFormClass: public Ui_StepFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPFORM_H
