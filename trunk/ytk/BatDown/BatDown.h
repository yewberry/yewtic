#ifndef BATDOWN_H
#define BATDOWN_H

#include <QtGui/QMainWindow>
#include "common.h"
#include "SqliteDB.h"

class WebBrowser;
class QTableView;
class QTreeView;
class FavoritesView;
class QLabel;
class QSplitter;

typedef QMap<QString, QString> settings_t;

class BatDown : public QMainWindow
{
	Q_OBJECT

public:
	BatDown(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BatDown();
	
	SqliteDB&		getDbMgr();
	settings_t&		getSettings();

	FavoritesView*	getFavoritesView();
	WebBrowser*		getWebBrowser();
	QLabel*			getWebProgress();

protected:
	void closeEvent(QCloseEvent *event);

protected slots:
	void analyseUrl();
	void download();
	void editScript();
	void about();

private slots:
	void testMd5();
	void testXml();
	void testJson();

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

	FavoritesView	*m_pFavoritesTree;
	QTableView		*entriesTable;
	QTextEdit		*logAppender;
	WebBrowser		*m_pWebBrowser;

	QLabel			*m_pWebProgress;
	QSplitter		*m_pRightButtomSplitter;
	QSplitter		*m_pRightSplitter;
	QSplitter		*m_pMainSplitter;

private:
	QMenu *fileMenu, *editMenu, *toolsMenu, *optionsMenu, *helpMenu;
	QToolBar *fileToolBar, *editToolBar;

	QAction *analyseAct, *downloadAct, *editScriptAct;
	QAction *quitAct, *aboutAct;
};

class BatDownBase {
public:
	BatDownBase(BatDown *p){m_pApp = p;}
	BatDown* getApp(){return m_pApp;}
	void setApp(BatDown *p){m_pApp = p;}
protected:
	BatDown	*m_pApp;
};

#endif // BATDOWN_H
