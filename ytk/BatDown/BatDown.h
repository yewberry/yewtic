#ifndef BATDOWN_H
#define BATDOWN_H

#include <QtGui/QMainWindow>

class QAction;

class BatDown : public QMainWindow
{
	Q_OBJECT

public:
	BatDown(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BatDown();

protected:
	void closeEvent(QCloseEvent *event);

private:
	void createActions();
	void createMenus();
	void createContextMenu();
	void createToolBars();
	void createStatusBar();
	void readSettings();
	void writeSettings();

private:
	QMenu *fileMenu; QMenu *editMenu; QMenu *toolsMenu;	QMenu *optionsMenu;
	QMenu *helpMenu;

	QToolBar *fileToolBar; QToolBar *editToolBar;

	QAction *downloadAction;
	QAction *aboutAction;
};

#endif // BATDOWN_H
