#ifndef XMONITOR_H
#define XMONITOR_H

#include <QtGui/QMainWindow>
#include "../ui_XMonitor.h"

class TopHeader;
class QToolButton;
class QStackedLayout;
class ServerView;
class ServerThread;
class ReportThread;
class ReportView;

class XMonitor : public QMainWindow
{
    Q_OBJECT

public:
    XMonitor(QWidget *parent = 0);
    ~XMonitor();

    ServerView* serverView();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
	void showServerView();
	void showReportView();

	void startBackgroundThread();
	void stopBackgroundThread();

private:
    void drawUi();
    void drawCentralWidget();
    void initGuiConns();
    void readSettings();
    void writeSettings();
    void openDatabase();
    void initDatabase();
    void runSqlScript();

private:
    Ui::XMonitorClass ui;

    TopHeader* 		m_pTopHeader;
    QToolButton*	m_pSvrBtn;
    QToolButton*	m_pRptBtn;
    QToolButton* 	m_pSetBtn;
    QToolButton* 	m_pViewBtn;
    QToolButton*	m_pHelpBtn;

    ServerView*		m_pServerView;
    ReportView*		m_pReportView;
    QStackedLayout*	m_pCentralWidgetLayout;
    QWidget*		m_pOutputView;

    QString m_dbName;
    QString m_dbUsr;
    QString m_dbPwd;

    ServerThread* m_pSvrThrd;
    ReportThread* m_pRptThrd;
    int	m_threadInter;
};

#endif // XMONITOR_H
