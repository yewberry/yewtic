/********************************************************************************
** Form generated from reading UI file 'StepForm.ui'
**
** Created: Sun Mar 13 19:47:09 2011
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepFormClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *svrId;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *seq;
    QPushButton *scriptBtn;
    QLabel *label_5;
    QPlainTextEdit *desc;
    QHBoxLayout *horizontalLayout;
    QLineEdit *cmd;
    QLineEdit *cmdResult;
    QLineEdit *script;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *StepFormClass)
    {
        if (StepFormClass->objectName().isEmpty())
            StepFormClass->setObjectName(QString::fromUtf8("StepFormClass"));
        StepFormClass->resize(416, 258);
        verticalLayout = new QVBoxLayout(StepFormClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(StepFormClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QLineEdit(StepFormClass);
        id->setObjectName(QString::fromUtf8("id"));
        id->setEnabled(false);

        gridLayout->addWidget(id, 0, 1, 1, 4);

        label_2 = new QLabel(StepFormClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        svrId = new QLineEdit(StepFormClass);
        svrId->setObjectName(QString::fromUtf8("svrId"));
        svrId->setEnabled(false);

        gridLayout->addWidget(svrId, 1, 1, 1, 4);

        label_3 = new QLabel(StepFormClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        name = new QLineEdit(StepFormClass);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 2, 1, 1, 1);

        label_4 = new QLabel(StepFormClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        seq = new QLineEdit(StepFormClass);
        seq->setObjectName(QString::fromUtf8("seq"));

        gridLayout->addWidget(seq, 2, 3, 1, 1);

        scriptBtn = new QPushButton(StepFormClass);
        scriptBtn->setObjectName(QString::fromUtf8("scriptBtn"));

        gridLayout->addWidget(scriptBtn, 2, 4, 1, 1);

        label_5 = new QLabel(StepFormClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        desc = new QPlainTextEdit(StepFormClass);
        desc->setObjectName(QString::fromUtf8("desc"));

        gridLayout->addWidget(desc, 3, 1, 1, 4);

        gridLayout->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cmd = new QLineEdit(StepFormClass);
        cmd->setObjectName(QString::fromUtf8("cmd"));

        horizontalLayout->addWidget(cmd);

        cmdResult = new QLineEdit(StepFormClass);
        cmdResult->setObjectName(QString::fromUtf8("cmdResult"));

        horizontalLayout->addWidget(cmdResult);

        script = new QLineEdit(StepFormClass);
        script->setObjectName(QString::fromUtf8("script"));

        horizontalLayout->addWidget(script);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(StepFormClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StepFormClass);

        QMetaObject::connectSlotsByName(StepFormClass);
    } // setupUi

    void retranslateUi(QWidget *StepFormClass)
    {
        StepFormClass->setWindowTitle(QApplication::translate("StepFormClass", "MyQtLog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StepFormClass", "ID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StepFormClass", "Server ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StepFormClass", "Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StepFormClass", "Seq. :", 0, QApplication::UnicodeUTF8));
        scriptBtn->setText(QApplication::translate("StepFormClass", "Script...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StepFormClass", "Description:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StepFormClass: public Ui_StepFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPFORM_H
