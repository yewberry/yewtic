#include "XMonitor.h"
#include <QtGui>
#include <QtSql>

#include "TopHeader.h"
#include "TitleBar.h"
#include "ServerView.h"
#include "ServerForm.h"
#include "Comm.h"

#ifdef WIN32
#include "windows.h"
#else
#include <unistd.h>
#endif

pthread_t XMonitor::threads[10];

XMonitor::XMonitor(QWidget *parent) :
	QMainWindow(parent) {
	ui.setupUi(this);
	drawUi();
	initGuiConns();
	readSettings();
	openDatabase();
	showServerView();
	m_pServerView->loadFromDb();
	startServerMonitorThread();
}

XMonitor::~XMonitor() {

}

void XMonitor::closeEvent(QCloseEvent *event) {
	if (QMessageBox::question(this, tr("Confirm?"), tr("Confirm to close?"),
			QMessageBox::Yes | QMessageBox::Cancel) == QMessageBox::Yes) {
		writeSettings();
	} else {
		event->ignore();
	}
}

void XMonitor::showServerView() {
	m_pCentralWidgetLayout->setCurrentIndex(0);
}

void XMonitor::showReportView() {
	m_pCentralWidgetLayout->setCurrentIndex(1);
}

void* XMonitor::serverMonitorThread(void *arg){
	int tid;
	tid = *((int *) arg);
	printf("Hello World! It's me, thread %d!\n", tid);

	while(true){
		printf("thread %d do work\n", tid);

#ifdef WIN32
		Sleep(1000);
#else
		sleep(1000);
#endif
	}
}

void XMonitor::startServerMonitorThread(){
	pthread_t threads[2];
	int thread_args[2];
	int rc, i;

	/* create all threads */
	for (i = 0; i < 2; ++i) {
		thread_args[i] = i;
		printf("In main: creating thread %d\n", i);
		rc = pthread_create(&threads[i], NULL, XMonitor::serverMonitorThread, (void *) &thread_args[i]);
		assert(0 == rc);
	}
}

void XMonitor::stopServerMonitorThread(){

}

void XMonitor::drawUi() {
	QDockWidget *dock = new QDockWidget(this);
	dock->setFloating(false);
	dock->setTitleBarWidget(new QWidget);
	m_pTopHeader = new TopHeader(dock);
	dock->setWidget(m_pTopHeader);
	addDockWidget(Qt::TopDockWidgetArea, dock);

	m_pSvrBtn = new QToolButton(m_pTopHeader);
	m_pSvrBtn->setIcon(QIcon(":/images/pc.png"));
	m_pSvrBtn->setIconSize(QSize(70, 70));
	m_pSvrBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pSvrBtn->setToolTip(tr("Server Monitor View"));
	m_pSvrBtn->setStatusTip(m_pSvrBtn->toolTip());
	m_pSvrBtn->setFocusPolicy(Qt::NoFocus);
	m_pSvrBtn->move(145, 39);
	m_pSvrBtn->setProperty("kind", "toolbar");
	m_pSvrBtn->setText(tr("&Server"));

	m_pRptBtn = new QToolButton(m_pTopHeader);
	m_pRptBtn->setIcon(QIcon(":/images/report.png"));
	m_pRptBtn->setIconSize(QSize(70, 70));
	m_pRptBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pRptBtn->setToolTip(tr("Report Manage View"));
	m_pRptBtn->setStatusTip(m_pRptBtn->toolTip());
	m_pRptBtn->setFocusPolicy(Qt::NoFocus);
	m_pRptBtn->move(220, 39);//145+70+5
	m_pRptBtn->setProperty("kind", "toolbar");
	m_pRptBtn->setText(tr("&Report"));

	m_pSetBtn = new QToolButton(m_pTopHeader);
	m_pSetBtn->setIcon(QIcon(":/images/setting.png"));
	m_pSetBtn->setIconSize(QSize(70, 70));
	m_pSetBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pSetBtn->setToolTip(tr("Setting"));
	m_pSetBtn->setStatusTip(m_pSetBtn->toolTip());
	m_pSetBtn->setFocusPolicy(Qt::NoFocus);
	m_pSetBtn->move(295, 39);//220+70+5
	m_pSetBtn->setProperty("kind", "toolbar");
	m_pSetBtn->setText(tr("&Setting"));

	m_pViewBtn = new QToolButton(m_pTopHeader);
	m_pViewBtn->setIcon(QIcon(":/images/vw.png"));
	m_pViewBtn->setIconSize(QSize(70, 70));
	m_pViewBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pViewBtn->setToolTip(tr("Setting the window view"));
	m_pViewBtn->setStatusTip(m_pViewBtn->toolTip());
	m_pViewBtn->setFocusPolicy(Qt::NoFocus);
	m_pViewBtn->move(370, 39);//295+70+5
	m_pViewBtn->setProperty("kind", "toolbar");
	m_pViewBtn->setText(tr("&View"));

	m_pHelpBtn = new QToolButton(m_pTopHeader);
	m_pHelpBtn->setIcon(QIcon(":/images/help.png"));
	m_pHelpBtn->setIconSize(QSize(70, 70));
	m_pHelpBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_pHelpBtn->setToolTip(tr("Help"));
	m_pHelpBtn->setStatusTip(m_pHelpBtn->toolTip());
	m_pHelpBtn->setFocusPolicy(Qt::NoFocus);
	m_pHelpBtn->move(445, 39);//370+70+5
	m_pHelpBtn->setProperty("kind", "toolbar");
	m_pHelpBtn->setText(tr("&Help"));

	//dock = new QDockWidget(tr("Properties"), this);

	dock = new QDockWidget(this);
	dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::LeftDockWidgetArea
			| Qt::RightDockWidgetArea);
	MyQtLog::init("log.html", dock);
	dock->setWidget(MyQtLog::log);
	TitleBar *title = new TitleBar(dock);
	title->setTitleText(tr("Output"));
	dock->setTitleBarWidget(title);
	addDockWidget(Qt::BottomDockWidgetArea, dock);

	drawCentralWidget();

	yDEBUG("Draw main ui done.");

}

void XMonitor::drawCentralWidget() {

	QComboBox *comboBox;
	QTextEdit *textEdit;
	QLineEdit *lineEdit;

	QWidget *central = new QWidget;
	QHBoxLayout *hLay = new QHBoxLayout(central);

	QStackedLayout *sLay = new QStackedLayout;
	m_pServerView = new ServerView(central);
	sLay->addWidget(m_pServerView);

	textEdit = new QTextEdit(central);
	textEdit->setObjectName(QString::fromUtf8("textEdit"));
	sLay->addWidget(textEdit);

	lineEdit = new QLineEdit(central);
	lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
	sLay->addWidget(lineEdit);

	hLay->addLayout(sLay);
	m_pCentralWidgetLayout = sLay;

	setCentralWidget(central);
}

void XMonitor::initGuiConns() {
	yDEBUG("Initialize GUI Connections.");
	connect(m_pSvrBtn, SIGNAL(clicked()), this, SLOT(showServerView()));
	connect(m_pRptBtn, SIGNAL(clicked()), this, SLOT(showReportView()));

}

void XMonitor::readSettings() {
	QSettings st("XMonitor.ini", QSettings::IniFormat);
	st.beginGroup("system");
	restoreGeometry(st.value("geometry").toByteArray());
	st.endGroup();

	st.beginGroup("database");
	m_dbName = st.value("name", "data.db").toString();
	m_dbUsr = st.value("usr", "xpa").toString();
	m_dbPwd = st.value("pwd", "xpa").toString();
	st.endGroup();
}

void XMonitor::writeSettings() {
	QSettings st("XMonitor.ini", QSettings::IniFormat);
	st.beginGroup("system");
	st.setValue("geometry", saveGeometry());
	st.endGroup();

	st.beginGroup("database");
	st.setValue("name", m_dbName);
	st.setValue("usr", m_dbUsr);
	st.setValue("pwd", m_dbPwd);
	st.endGroup();

	m_pServerView->saveScene();
}

void XMonitor::openDatabase() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(m_dbName);
	db.setUserName(m_dbUsr);
	db.setPassword(m_dbPwd);
	if (!db.open()) {
		QMessageBox::critical(0, QObject::tr("Database Error"),
				db.lastError().text());
		yFATAL(QString("Can't open db: %1").arg(m_dbName));
	}
	QFile dbFile(m_dbName);
	if (dbFile.size() == 0) {
		initDatabase();
	}
}

void XMonitor::initDatabase() {
	yINFO("Initialize Database...");
	QProgressDialog progress;
	progress.setWindowModality(Qt::WindowModal);
	progress.setWindowTitle(QObject::tr("Database"));
	progress.setLabelText(QObject::tr("Initialize Database..."));
	progress.setMinimum(0);

	QString sql = Comm::stringFromResource(":/script/db.sql");
	QSqlQuery query;
	QStringList ls = sql.split("\n");

	progress.setMaximum(ls.length() + 1);
	progress.setValue(1);

	int i = 1;
	Q_FOREACH(QString str, ls){
		bool r = query.exec(str);
		progress.setValue(++i);
		qApp->processEvents();
	}
	progress.setValue(progress.maximum());
	qApp->processEvents();
	yINFO("Initialize Done.");

}

void serverMonitorThread(void *arg);
