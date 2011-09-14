#include <QApplication>
#include <QPushButton>

#include "gotocelldialog.h"
#include "sortdialog.h"
#include "mainwindow.h"
#include "iconeditor.h"
#include "ui_prefs.h"

void testDialog(){
	/*
	 * 1. public extend from QDialog and ui file.
	 * 2. Q_OBJECT after class {, write constructor (QWidget *parent = 0).
	 * 3. setupUi(this) in constructor.
	 */
    GoToCellDialog *dialog = new GoToCellDialog;
    dialog->show();
    /*
     * An extension dialog need:
     * 1. a toggle button
     * 2. a few extra signal¨Cslot connections
     * 3. a non-resizable layout.
     */
	SortDialog *sortDialog = new SortDialog;
	sortDialog->show();
}

void testMainWindow(){
	/*
	 * see the "Creating Main Windows in Qt Designer"
	 * chapter in Qt Designer's online manual.
	 */
	MainWindow *mainWnd = new MainWindow;
	mainWnd->show();
}

void testCustomWidget(){
    IconEditor *iconEditor = new IconEditor;
    iconEditor->setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor->setIconImage(QImage(":/images/mouse.png"));
    iconEditor->show();
}

void testDatabase(){

}

void testPrefs(){
    Ui::MyPreferences ui;
    QDialog *dialog = new QDialog;
    ui.setupUi(dialog);
    dialog->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testDialog();
    testMainWindow();
    testCustomWidget();
    testDatabase();
    testPrefs();
    return app.exec();
}
