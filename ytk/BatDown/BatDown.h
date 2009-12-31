#ifndef BATDOWN_H
#define BATDOWN_H

#include <QtGui/QMainWindow>
#include "common.h"

class SqliteDB;
class WebBrowser;
class QTableView;

class BatDown : public QMainWindow
{
	Q_OBJECT

public:
	BatDown(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BatDown();

protected:
	void closeEvent(QCloseEvent *event);

protected slots:
	void analyseUrl();
	void download();
	void about();

private:
	void createActions();
	void createMenus();
	void createContextMenu();
	void createToolBars();
	void createStatusBar();
	void createCentralArea();

	void readSettings();
	void writeSettings();

	void init();
	void initLogger();

public:
	static SqliteDB dbMgr;

private:
	QMap<QString, QString> *m_setting;

	QTableView	*entriesTable;
	QTextEdit	*logAppender;
	WebBrowser	*webBrowser;


private:
	QMenu *fileMenu, *editMenu, *toolsMenu, *optionsMenu, *helpMenu;
	QToolBar *fileToolBar, *editToolBar;

	QAction *analyseAct, *downloadAct;
	QAction *quitAct, *aboutAct;
};

#endif // BATDOWN_H
