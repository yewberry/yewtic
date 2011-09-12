#include <QtGui>

#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
	setupUi(this);

	createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    setWindowIcon(QIcon(":/images/icon.png"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (okToContinue()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Spreadsheet"),
            tr("<h2>Spreadsheet 1.1</h2>"
               "<p>Copyright &copy; 2008 Software Inc."
               "<p>Spreadsheet is a small application that "
               "demonstrates QAction, QMainWindow, QMenuBar, "
               "QStatusBar, QTableWidget, QToolBar, and many other "
               "Qt classes."));
}


void MainWindow::updateStatusBar()
{
}


void MainWindow::createActions()
{
/*
	newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
*/
	action_New->setStatusTip(tr("Create a new document"));
	connect(action_Save, SIGNAL(triggered()), this, SLOT(other_action_callback()));
	connect(actionFile_one, SIGNAL(triggered()), this, SLOT(other_action_callback()));
	connect(actionFile_two, SIGNAL(triggered()), this, SLOT(other_action_callback()));
	connect(actionFile_three, SIGNAL(triggered()), this, SLOT(other_action_callback()));
	connect(action_About, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::on_action_New_triggered(){
	std::cerr<<"in on_action_New_triggered.\n";
}

void MainWindow::other_action_callback(){
	std::cerr<<"in other_action_callback.\n";
}

void MainWindow::createMenus()
{
/*
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
*/
	QMenu *dynaMenu = menu_Help->addMenu(tr("Dynamic Menu"));
	dynaMenu->addAction(action_New);
	dynaMenu->addAction(action_Save);
}

void MainWindow::createContextMenu()
{
    centralwidget->addAction(action_New);
    centralwidget->addAction(action_Save);
    centralwidget->setContextMenuPolicy(Qt::ActionsContextMenu);

    myGroupBox->addAction(action_About);
    myGroupBox->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
	QToolBar *toolbar = addToolBar(tr("Dynamic ToolBar"));
	toolbar->addAction(action_About);
}

void MainWindow::createStatusBar()
{
	//statusBar()->addWidget();
	updateStatusBar();
}

void MainWindow::readSettings()
{
	QSettings settings("TestQt.ini", QSettings::IniFormat);
    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();
}

void MainWindow::writeSettings()
{
	QSettings settings("TestQt.ini", QSettings::IniFormat);
    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

bool MainWindow::okToContinue()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("Spreadsheet"),
                        tr("The document has been modified.\n"
                           "Do you want to save your changes?"),
                        QMessageBox::Yes | QMessageBox::No
                        | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
            return true;
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}
