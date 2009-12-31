#include <QtGui>

#include "BatDown.h"
#include "SqliteDB.h"
#include "WebBrowser.h"
#include "EntryModel.h"

SqliteDB BatDown::dbMgr;

BatDown::BatDown(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags){
	init();
}

BatDown::~BatDown(){
	delete m_setting;
}

void BatDown::init(){
	initLogger();
	dbMgr.open(("ytk.db"));

	m_setting = new QMap<QString, QString>;

	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();
	createCentralArea();

	readSettings();
}

void BatDown::closeEvent(QCloseEvent *event){
	writeSettings();
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
	EntryModel *model = new EntryModel;
	entriesTable = new QTableView;
	entriesTable->setModel(model);
	entriesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	//entriesTable->resizeColumnsToContents();

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
	vbLay->addWidget(entriesTable, 1);
	vbLay->addLayout(hbLay, 1);

	centralWidget->setLayout(vbLay);
	setCentralWidget(centralWidget);
}

void BatDown::readSettings(){
	recList_t rs = dbMgr.query("select * from btdl_conf where id=1", true);
	//TODO load default
	QStringList fldK = rs.at(0);
	QStringList fldV = rs.at(1);

	for(int i=0,len=fldK.size(); i<len; ++i){
		m_setting->insert( fldK.at(i), fldV.at(i) );
	}

	QStringList pos = m_setting->value("app_pos").split(",");
	setGeometry(pos[0].toInt(), pos[1].toInt(), pos[2].toInt(), pos[3].toInt());
}

void BatDown::writeSettings(){
	QRect rect = geometry();
	QString pos = QString("%1,%2,%3,%4")
					.arg(rect.x())
					.arg(rect.y())
					.arg(rect.width())
					.arg(rect.height());
	m_setting->insert("app_pos", pos);

	dbMgr.updateRecord( *m_setting, "rowid=1", "btdl_conf" );
}


void BatDown::initLogger(){
	logAppender = new QTextEdit;
	logAppender->setReadOnly(true);
	logAppender->setWordWrapMode(QTextOption::NoWrap);
	yewtic::appenders.insert(QString::fromUtf8("batdown_appender"), logAppender);

	//LogLog::getLogLog()->setInternalDebugging(true);
	//logger = Logger::getRoot();
	
	try{
		ConfigureAndWatchThread configureThread(LOG4CPLUS_TEXT("log4cplus.properties"), 3*1000);
		yDEBUG("logger conf done.");
	} catch(...) {
		std::cout << "Exception..." << std::endl;
		yERROR("Exception occured...");
	}
}