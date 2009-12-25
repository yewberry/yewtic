#include <QtGui>

#include "BatDown.h"
#include "DBManager.h"
#include "sqlite3/sqlite3.h"

BatDown::BatDown(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags){
	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();
	createCentralArea();

	readSettings();
}

BatDown::~BatDown(){}

void BatDown::closeEvent(QCloseEvent *event){
	event->accept();
}

void BatDown::analyseUrl(){
}

void BatDown::download(){
}

void BatDown::about(){
}

void BatDown::createActions(){
	quitAct		= new QAction(tr("&Quit"), this);
	connect( quitAct,SIGNAL(triggered(bool)),
			qApp, SLOT(quit()) );

	aboutAct	= new QAction(tr("&About"), this);
	connect( aboutAct, SIGNAL(triggered(bool)),
			this, SLOT(about()) );

	analyseAct	= new QAction(tr("Analyse Url"), this);
	connect( analyseAct, SIGNAL(triggered(bool)),
			this, SLOT(analyseUrl()) );

	downloadAct	= new QAction(tr("Download"), this);
	connect( downloadAct, SIGNAL(triggered(bool)),
			this, SLOT(download()) );
}

void BatDown::createMenus(){
	QMenuBar *mbar = menuBar();

	fileMenu = mbar->addMenu(tr("&File"));
	fileMenu->addAction(analyseAct);
	fileMenu->addAction(downloadAct);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAct);

	helpMenu = mbar->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
}

void BatDown::createContextMenu(){
}

void BatDown::createToolBars(){
	fileToolBar = addToolBar(tr("File"));
	fileToolBar->addAction(analyseAct);
	fileToolBar->addAction(downloadAct);
}

void BatDown::createStatusBar(){
}

void BatDown::createCentralArea(){
	QLabel *demo = new QLabel(tr("Dummy"));

	logAppender = new QTextEdit;
	logAppender->setReadOnly(true);
	logAppender->setWordWrapMode(QTextOption::NoWrap);
	initLogger(logAppender);

	webBrowser = new WebBrowser;
	
	QWidget *centralWidget = new QWidget;

	QHBoxLayout *hbLay = new QHBoxLayout;
    hbLay->setMargin(0);
    hbLay->setSpacing(0);
	hbLay->addWidget(logAppender, 1);
	hbLay->addWidget(webBrowser, 1);

	QVBoxLayout *vbLay = new QVBoxLayout;
    vbLay->setMargin(0);
    vbLay->setSpacing(0);
	vbLay->addWidget(demo, 1);
	vbLay->addLayout(hbLay, 1);

	centralWidget->setLayout(vbLay);
	setCentralWidget(centralWidget);
}

void BatDown::readSettings(){
	resize(800, 600);
}

void BatDown::writeSettings(){
}

void BatDown::initLogger(QTextEdit* appender){
	yewtic::appenders.insert(QString::fromUtf8("batdown_appender"), appender);

	LogLog::getLogLog()->setInternalDebugging(true);
	logger = Logger::getRoot();
	
	try{
		ConfigureAndWatchThread configureThread(LOG4CPLUS_TEXT("log4cplus.properties"), 3*1000);
		LOG4CPLUS_DEBUG(logger, "logger conf done.");
	} catch(...) {
		std::cout << "Exception..." << std::endl;
		LOG4CPLUS_FATAL(logger, "Exception occured...");
	}
}