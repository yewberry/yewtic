#ifndef XMONITOR_H
#define XMONITOR_H

#include <QtGui/QMainWindow>
#include "../ui_XMonitor.h"

class TopHeader;
class QToolButton;
class QStackedLayout;

class XMonitor : public QMainWindow
{
    Q_OBJECT

public:
    XMonitor(QWidget *parent = 0);
    ~XMonitor();

protected:
    void closeEvent(QCloseEvent *event);

public slots:
	void showServerView();
	void showReportView();

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

    QStackedLayout*	m_pCentralWidgetLayout;

    QString m_dbName;
    QString m_dbUsr;
    QString m_dbPwd;
};

#endif // XMONITOR_H
