/********************************************************************************
** Form generated from reading UI file 'MyQtLog.ui'
**
** Created: Fri Mar 11 09:47:17 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTLOG_H
#define UI_MYQTLOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyQtLogClass
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *logBrs;

    void setupUi(QWidget *MyQtLogClass)
    {
        if (MyQtLogClass->objectName().isEmpty())
            MyQtLogClass->setObjectName(QString::fromUtf8("MyQtLogClass"));
        MyQtLogClass->resize(400, 300);
        verticalLayout = new QVBoxLayout(MyQtLogClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logBrs = new QTextBrowser(MyQtLogClass);
        logBrs->setObjectName(QString::fromUtf8("logBrs"));

        verticalLayout->addWidget(logBrs);


        retranslateUi(MyQtLogClass);

        QMetaObject::connectSlotsByName(MyQtLogClass);
    } // setupUi

    void retranslateUi(QWidget *MyQtLogClass)
    {
        MyQtLogClass->setWindowTitle(QApplication::translate("MyQtLogClass", "MyQtLog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyQtLogClass: public Ui_MyQtLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTLOG_H
