#ifndef BATDOWN_H
#define BATDOWN_H

#include <QtGui/QMainWindow>
#include "common.h"
#include "SqliteDB.h"

class WebBrowser;
class QTableView;
class QTreeView;

typedef QMap<QString, QString> settings_t;

class BatDown : public QMainWindow
{
	Q_OBJECT

public:
	BatDown(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BatDown();
	
	SqliteDB& getDbMgr();
	settings_t& getSettings();

protected:
	void closeEvent(QCloseEvent *event);

protected slots:
	void analyseUrl();
	void download();
	void about();

private slots:
	void testMd5();

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

private:
	SqliteDB	m_dbMgr;
	settings_t	m_settings;

	QTreeView	*favoritesTree;
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
