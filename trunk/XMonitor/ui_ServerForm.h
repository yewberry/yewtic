/********************************************************************************
** Form generated from reading UI file 'ServerForm.ui'
**
** Created: Fri Mar 4 19:58:29 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERFORM_H
#define UI_SERVERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerFormClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *ip;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_4;
    QPlainTextEdit *desc;
    QLabel *label_5;
    QLineEdit *usr;
    QLabel *label_8;
    QLineEdit *itemPos;
    QLabel *label_6;
    QLineEdit *pwd;
    QLabel *label_7;
    QCheckBox *isActive;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ServerFormClass)
    {
        if (ServerFormClass->objectName().isEmpty())
            ServerFormClass->setObjectName(QString::fromUtf8("ServerFormClass"));
        ServerFormClass->resize(400, 300);
        verticalLayout = new QVBoxLayout(ServerFormClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ServerFormClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        id = new QLineEdit(ServerFormClass);
        id->setObjectName(QString::fromUtf8("id"));
        id->setEnabled(false);

        gridLayout->addWidget(id, 0, 1, 1, 2);

        label_2 = new QLabel(ServerFormClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        ip = new QLineEdit(ServerFormClass);
        ip->setObjectName(QString::fromUtf8("ip"));

        gridLayout->addWidget(ip, 1, 1, 1, 2);

        label_3 = new QLabel(ServerFormClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        name = new QLineEdit(ServerFormClass);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 2, 1, 1, 2);

        label_4 = new QLabel(ServerFormClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        desc = new QPlainTextEdit(ServerFormClass);
        desc->setObjectName(QString::fromUtf8("desc"));

        gridLayout->addWidget(desc, 3, 1, 1, 3);

        label_5 = new QLabel(ServerFormClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        usr = new QLineEdit(ServerFormClass);
        usr->setObjectName(QString::fromUtf8("usr"));

        gridLayout->addWidget(usr, 4, 1, 1, 1);

        label_8 = new QLabel(ServerFormClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);

        itemPos = new QLineEdit(ServerFormClass);
        itemPos->setObjectName(QString::fromUtf8("itemPos"));
        itemPos->setEnabled(false);

        gridLayout->addWidget(itemPos, 4, 3, 1, 1);

        label_6 = new QLabel(ServerFormClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        pwd = new QLineEdit(ServerFormClass);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pwd, 5, 1, 1, 1);

        label_7 = new QLabel(ServerFormClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        isActive = new QCheckBox(ServerFormClass);
        isActive->setObjectName(QString::fromUtf8("isActive"));

        gridLayout->addWidget(isActive, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ServerFormClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ServerFormClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), ServerFormClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerFormClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(ServerFormClass);
    } // setupUi

    void retranslateUi(QDialog *ServerFormClass)
    {
        ServerFormClass->setWindowTitle(QApplication::translate("ServerFormClass", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerFormClass", "ID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerFormClass", "IP:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ServerFormClass", "Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ServerFormClass", "Description:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ServerFormClass", "User:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ServerFormClass", "Item Pos:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ServerFormClass", "Password:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ServerFormClass", "is Active?", 0, QApplication::UnicodeUTF8));
        isActive->setText(QApplication::translate("ServerFormClass", "CheckBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerFormClass: public Ui_ServerFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERFORM_H
