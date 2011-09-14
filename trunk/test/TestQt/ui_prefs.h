/********************************************************************************
** Form generated from reading UI file 'prefs.ui'
**
** Created: Wed Sep 14 10:23:07 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFS_H
#define UI_PREFS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPreferences
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QCheckBox *checkBox;
    QWidget *page_2;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *MyPreferences)
    {
        if (MyPreferences->objectName().isEmpty())
            MyPreferences->setObjectName(QString::fromUtf8("MyPreferences"));
        MyPreferences->resize(400, 300);
        buttonBox = new QDialogButtonBox(MyPreferences);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(MyPreferences);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 40, 141, 192));
        stackedWidget = new QStackedWidget(MyPreferences);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(170, 40, 211, 181));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        checkBox = new QCheckBox(page);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 70, 72, 17));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        buttonBox_2 = new QDialogButtonBox(page_2);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(30, 80, 156, 23));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_2);

        retranslateUi(MyPreferences);
        QObject::connect(buttonBox, SIGNAL(accepted()), MyPreferences, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MyPreferences, SLOT(reject()));
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        listWidget->setCurrentRow(0);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MyPreferences);
    } // setupUi

    void retranslateUi(QDialog *MyPreferences)
    {
        MyPreferences->setWindowTitle(QApplication::translate("MyPreferences", "Preferences", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MyPreferences", "setting 1", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MyPreferences", "setting 2", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        checkBox->setText(QApplication::translate("MyPreferences", "CheckBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyPreferences: public Ui_MyPreferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFS_H
