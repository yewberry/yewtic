/********************************************************************************
** Form generated from reading UI file 'StepScriptDialog.ui'
**
** Created: Wed Mar 9 20:25:57 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPSCRIPTDIALOG_H
#define UI_STEPSCRIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepScriptDialogClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListView *steplist;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *cmd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *runCmdBtn;
    QTextEdit *cmdResult;
    QLabel *label_3;
    QTextEdit *script;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *StepScriptDialogClass)
    {
        if (StepScriptDialogClass->objectName().isEmpty())
            StepScriptDialogClass->setObjectName(QString::fromUtf8("StepScriptDialogClass"));
        StepScriptDialogClass->resize(765, 493);
        verticalLayout_2 = new QVBoxLayout(StepScriptDialogClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        steplist = new QListView(StepScriptDialogClass);
        steplist->setObjectName(QString::fromUtf8("steplist"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(steplist->sizePolicy().hasHeightForWidth());
        steplist->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(steplist);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(StepScriptDialogClass);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        cmd = new QTextEdit(StepScriptDialogClass);
        cmd->setObjectName(QString::fromUtf8("cmd"));
        sizePolicy.setHeightForWidth(cmd->sizePolicy().hasHeightForWidth());
        cmd->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(cmd);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(StepScriptDialogClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_2);

        runCmdBtn = new QPushButton(StepScriptDialogClass);
        runCmdBtn->setObjectName(QString::fromUtf8("runCmdBtn"));

        horizontalLayout_2->addWidget(runCmdBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        cmdResult = new QTextEdit(StepScriptDialogClass);
        cmdResult->setObjectName(QString::fromUtf8("cmdResult"));
        sizePolicy.setHeightForWidth(cmdResult->sizePolicy().hasHeightForWidth());
        cmdResult->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(cmdResult);

        label_3 = new QLabel(StepScriptDialogClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_3);

        script = new QTextEdit(StepScriptDialogClass);
        script->setObjectName(QString::fromUtf8("script"));
        sizePolicy.setHeightForWidth(script->sizePolicy().hasHeightForWidth());
        script->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(script);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(5, 4);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(StepScriptDialogClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(StepScriptDialogClass);

        QMetaObject::connectSlotsByName(StepScriptDialogClass);
    } // setupUi

    void retranslateUi(QWidget *StepScriptDialogClass)
    {
        StepScriptDialogClass->setWindowTitle(QApplication::translate("StepScriptDialogClass", "MyQtLog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StepScriptDialogClass", "Command:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StepScriptDialogClass", "Result:", 0, QApplication::UnicodeUTF8));
        runCmdBtn->setText(QApplication::translate("StepScriptDialogClass", "Run Command", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StepScriptDialogClass", "Script:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StepScriptDialogClass: public Ui_StepScriptDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPSCRIPTDIALOG_H
