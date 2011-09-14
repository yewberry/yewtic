/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Sep 14 10:23:07 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Save;
    QAction *actionFile_one;
    QAction *actionFile_two;
    QAction *actionFile_three;
    QAction *action_About;
    QWidget *centralwidget;
    QGroupBox *myGroupBox;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuOpen_recetly;
    QMenu *menu_Edit;
    QMenu *menu_Help;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(447, 269);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        actionFile_one = new QAction(MainWindow);
        actionFile_one->setObjectName(QString::fromUtf8("actionFile_one"));
        actionFile_two = new QAction(MainWindow);
        actionFile_two->setObjectName(QString::fromUtf8("actionFile_two"));
        actionFile_three = new QAction(MainWindow);
        actionFile_three->setObjectName(QString::fromUtf8("actionFile_three"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/gotocell.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myGroupBox = new QGroupBox(centralwidget);
        myGroupBox->setObjectName(QString::fromUtf8("myGroupBox"));
        myGroupBox->setGeometry(QRect(260, 40, 120, 80));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 447, 18));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuOpen_recetly = new QMenu(menu_File);
        menuOpen_recetly->setObjectName(QString::fromUtf8("menuOpen_recetly"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Save);
        menu_File->addSeparator();
        menu_File->addAction(menuOpen_recetly->menuAction());
        menuOpen_recetly->addAction(actionFile_one);
        menuOpen_recetly->addAction(actionFile_two);
        menuOpen_recetly->addAction(actionFile_three);
        menu_Help->addAction(action_About);
        toolBar->addAction(action_New);
        toolBar->addAction(action_Save);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_New->setText(QApplication::translate("MainWindow", "&New", 0, QApplication::UnicodeUTF8));
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionFile_one->setText(QApplication::translate("MainWindow", "file one", 0, QApplication::UnicodeUTF8));
        actionFile_two->setText(QApplication::translate("MainWindow", "file two", 0, QApplication::UnicodeUTF8));
        actionFile_three->setText(QApplication::translate("MainWindow", "file three", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        myGroupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuOpen_recetly->setTitle(QApplication::translate("MainWindow", "Open recetly", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
