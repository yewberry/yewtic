/********************************************************************************
** Form generated from reading UI file 'StepScriptDialog.ui'
**
** Created: Wed Mar 16 20:43:05 2011
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepScriptDialogClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *mainLayout;
    QVBoxLayout *editorLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *runCmdBtn;
    QLabel *label_3;
    QLineEdit *svrId;
    QLineEdit *stepId;
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
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        editorLayout = new QVBoxLayout();
        editorLayout->setSpacing(6);
        editorLayout->setObjectName(QString::fromUtf8("editorLayout"));
        label = new QLabel(StepScriptDialogClass);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        editorLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(StepScriptDialogClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        runCmdBtn = new QPushButton(StepScriptDialogClass);
        runCmdBtn->setObjectName(QString::fromUtf8("runCmdBtn"));

        horizontalLayout_2->addWidget(runCmdBtn);


        editorLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(StepScriptDialogClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        editorLayout->addWidget(label_3);


        mainLayout->addLayout(editorLayout);

        mainLayout->setStretch(0, 4);

        verticalLayout_2->addLayout(mainLayout);

        svrId = new QLineEdit(StepScriptDialogClass);
        svrId->setObjectName(QString::fromUtf8("svrId"));

        verticalLayout_2->addWidget(svrId);

        stepId = new QLineEdit(StepScriptDialogClass);
        stepId->setObjectName(QString::fromUtf8("stepId"));

        verticalLayout_2->addWidget(stepId);

        buttonBox = new QDialogButtonBox(StepScriptDialogClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(StepScriptDialogClass);

        QMetaObject::connectSlotsByName(StepScriptDialogClass);
    } // setupUi

    void retranslateUi(QWidget *StepScriptDialogClass)
    {
        StepScriptDialogClass->setWindowTitle(QApplication::translate("StepScriptDialogClass", "Step Script Dialog", 0, QApplication::UnicodeUTF8));
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
