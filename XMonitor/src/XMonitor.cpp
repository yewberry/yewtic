#include "XMonitor.h"
#include <QtGui>
#include "MyQtLog.h"

#include "TopHeader.h"

XMonitor::XMonitor(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	drawUi();
}

XMonitor::~XMonitor()
{

}

void XMonitor::drawUi(){
	QDockWidget *dock = new QDockWidget(this);
	dock->setFloating(false);
	dock->setTitleBarWidget(new QWidget);
	m_pTopHeader = new TopHeader(dock);
	dock->setWidget(m_pTopHeader);
	addDockWidget(Qt::TopDockWidgetArea, dock);

	m_pSvrBtn = new QToolButton(m_pTopHeader);
	m_pSvrBtn->setIcon(QIcon(":/images/pc.png"));
	m_pSvrBtn->setIconSize(QSize(70,70));
	m_pSvrBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pSvrBtn->setToolTip(tr("Server Monitor View"));
	m_pSvrBtn->setStatusTip(m_pSvrBtn->toolTip());
	m_pSvrBtn->setFocusPolicy(Qt::NoFocus);
	m_pSvrBtn->move(145,39);
	m_pSvrBtn->setProperty("kind","toolbar");
	m_pSvrBtn->setText(tr("&Server"));

	m_pRptBtn = new QToolButton(m_pTopHeader);
	m_pRptBtn->setIcon(QIcon(":/images/report.png"));
	m_pRptBtn->setIconSize(QSize(70,70));
	m_pRptBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pRptBtn->setToolTip(tr("Report Manage View"));
	m_pRptBtn->setStatusTip(m_pRptBtn->toolTip());
	m_pRptBtn->setFocusPolicy(Qt::NoFocus);
	m_pRptBtn->move(220,39);//145+70+5
	m_pRptBtn->setProperty("kind","toolbar");
	m_pRptBtn->setText(tr("&Report"));

	m_pHelpBtn = new QToolButton(m_pTopHeader);
	m_pHelpBtn->setIcon(QIcon(":/images/help.png"));
	m_pHelpBtn->setIconSize(QSize(70,70));
	m_pHelpBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pHelpBtn->setToolTip(tr("Help"));
	m_pHelpBtn->setStatusTip(m_pHelpBtn->toolTip());
	m_pHelpBtn->setFocusPolicy(Qt::NoFocus);
	m_pHelpBtn->move(295,39);//220+70+5
	m_pHelpBtn->setProperty("kind","toolbar");
	m_pHelpBtn->setText(tr("&Help"));

	//dock = new QDockWidget(tr("Properties"), this);

	dock = new QDockWidget(tr("Output"), this);
	dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
	MyQtLog::init("log.html", dock);
	dock->setWidget(MyQtLog::log);
	addDockWidget(Qt::BottomDockWidgetArea, dock);

	yDEBUG("Draw main ui done.");

}
