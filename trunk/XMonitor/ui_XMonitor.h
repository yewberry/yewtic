/********************************************************************************
** Form generated from reading UI file 'XMonitor.ui'
**
** Created: Sat Feb 26 11:39:49 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMONITOR_H
#define UI_XMONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XMonitorClass
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *XMonitorClass)
    {
        if (XMonitorClass->objectName().isEmpty())
            XMonitorClass->setObjectName(QString::fromUtf8("XMonitorClass"));
        XMonitorClass->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        XMonitorClass->setWindowIcon(icon);
        centralwidget = new QWidget(XMonitorClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        XMonitorClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(XMonitorClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        XMonitorClass->setStatusBar(statusbar);

        retranslateUi(XMonitorClass);

        QMetaObject::connectSlotsByName(XMonitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *XMonitorClass)
    {
        XMonitorClass->setWindowTitle(QApplication::translate("XMonitorClass", "XMonitor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XMonitorClass: public Ui_XMonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMONITOR_H
