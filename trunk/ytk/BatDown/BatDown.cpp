#include "BatDown.h"

BatDown::BatDown(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	readSettings();
}

BatDown::~BatDown()
{

}

void BatDown::closeEvent(QCloseEvent *event)
{
	event->accept();
}

void BatDown::createActions()
{
}

void BatDown::createMenus()
{
}

void BatDown::createContextMenu()
{
}

void BatDown::createToolBars()
{
}

void BatDown::createStatusBar()
{
}

void BatDown::readSettings()
{
}

void BatDown::writeSettings()
{
}