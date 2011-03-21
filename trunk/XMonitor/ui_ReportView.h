/********************************************************************************
** Form generated from reading UI file 'ReportView.ui'
**
** Created: Mon Mar 21 09:07:34 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTVIEW_H
#define UI_REPORTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportViewClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *design;
    QWidget *code;

    void setupUi(QWidget *ReportViewClass)
    {
        if (ReportViewClass->objectName().isEmpty())
            ReportViewClass->setObjectName(QString::fromUtf8("ReportViewClass"));
        ReportViewClass->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ReportViewClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(ReportViewClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        design = new QWidget();
        design->setObjectName(QString::fromUtf8("design"));
        tabWidget->addTab(design, QString());
        code = new QWidget();
        code->setObjectName(QString::fromUtf8("code"));
        tabWidget->addTab(code, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(ReportViewClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReportViewClass);
    } // setupUi

    void retranslateUi(QWidget *ReportViewClass)
    {
        ReportViewClass->setWindowTitle(QApplication::translate("ReportViewClass", "Report", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(design), QApplication::translate("ReportViewClass", "Design", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(code), QApplication::translate("ReportViewClass", "Code", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReportViewClass: public Ui_ReportViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTVIEW_H
