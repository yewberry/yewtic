#ifndef XMONITOR_H
#define XMONITOR_H

#include <QtGui/QMainWindow>
#include "../ui_XMonitor.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

class TopHeader;
class QToolButton;
class QStackedLayout;
class ServerView;

class XMonitor : public QMainWindow
{
    Q_OBJECT

public:
    XMonitor(QWidget *parent = 0);
    ~XMonitor();

	static void* serverMonitorThread(void *arg);
	static pthread_t threads[];

protected:
    void closeEvent(QCloseEvent *event);

private slots:
	void showServerView();
	void showReportView();

	void startServerMonitorThread();
	void stopServerMonitorThread();

private:
    void drawUi();
    void drawCentralWidget();
    void initGuiConns();
    void readSettings();
    void writeSettings();
    void openDatabase();
    void initDatabase();

private:
    Ui::XMonitorClass ui;

    TopHeader* 		m_pTopHeader;
    QToolButton*	m_pSvrBtn;
    QToolButton*	m_pRptBtn;
    QToolButton* 	m_pSetBtn;
    QToolButton* 	m_pViewBtn;
    QToolButton*	m_pHelpBtn;

    ServerView*		m_pServerView;
    QStackedLayout*	m_pCentralWidgetLayout;

    QString m_dbName;
    QString m_dbUsr;
    QString m_dbPwd;
};

#endif // XMONITOR_H
