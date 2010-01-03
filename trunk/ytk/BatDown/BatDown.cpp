#include <QtGui>

#include "BatDown.h"
#include "SqliteDB.h"
#include "WebBrowser.h"
#include "EntryModel.h"
#include "FavoritesView.h"
#include "md5.h"
#include "json.h"

BatDown::BatDown(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags){
	initLogger();
	m_dbMgr.open(("ytk.db"));
	readSettings();

	init();
}

BatDown::~BatDown(){
	m_dbMgr.close();
}

void BatDown::init(){
	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();
	createCentralArea();
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

void BatDown::testMd5(){
	char *fn = "jquery.min.js";
	QFile testFile(fn);
	testFile.open( QIODevice::ReadOnly );
	QByteArray ba = testFile.readAll();
	const char *test = (const char *)ba;

	md5_state_t state;
	md5_byte_t digest[16];
	char hex_output[16*2 + 1];
	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)test, strlen(test));
	md5_finish(&state, digest);
	int di;
	for(di = 0; di < 16; ++di)
		sprintf(hex_output + di * 2, "%02x", digest[di]);
	yDEBUG(hex_output);
}
void BatDown::testXml(){
	/*
	try
	{
	XMLPlatformUtils::Initialize();
	XercesDOMParser *parser = new XercesDOMParser;
	parser->setValidationScheme(false);
	parser->setDoNamespaces(false);
	parser->setDoSchema(false);
	parser->setValidationSchemaFullChecking(false);
	parser->setCreateEntityReferenceNodes(false);

	} catch(...) {
	XMLPlatformUtils::Terminate();
	}
	*/
}
void BatDown::testJson(){
	char *fn = "script/2.json";
	QFile testFile(fn);
	if(!testFile.open(QIODevice::ReadOnly | QIODevice::Text) )
		return;
	QByteArray ba = testFile.readAll();
	char* json = ba.data();
	json_t* root = NULL;
	json_t* item;

	assert (JSON_OK == json_parse_document (&root, json));
	assert (root->child);
	item = json_find_first_label (root, "title");
	QString ss = QString::fromLocal8Bit(item->child->text);
	yDEBUG(ss.toLocal8Bit().data());
	json_free_value (&item);
	json_free_value (&root);
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

	QToolBar *testToollBar = addToolBar("Test");
	QAction *testMd5 = new QAction("Test MD5", this);
	connect( testMd5, SIGNAL(triggered(bool)), this, SLOT(testMd5()) );
	testToollBar->addAction(testMd5);
	/*
	QAction *testXml = new QAction("Test XML", this);
	connect( testXml, SIGNAL(triggered(bool)), this, SLOT(testXml()) );
	testToollBar->addAction(testXml);
	*/
	QAction *testJson = new QAction("Test JSON", this);
	connect( testJson, SIGNAL(triggered(bool)), this, SLOT(testJson()) );
	testToollBar->addAction(testJson);

}

void BatDown::createStatusBar(){
}

void BatDown::createCentralArea(){
	m_pFavoritesTree = new FavoritesView(this);
	m_pFavoritesTree->expandToDepth(0);

	EntryModel *entryModel = new EntryModel(this);
	entriesTable = new QTableView;
	entriesTable->setModel(entryModel);
	entriesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	entriesTable->horizontalHeader()->setStretchLastSection(true);
	entriesTable->resizeColumnsToContents();
	entriesTable->resizeRowsToContents();
	entriesTable->setColumnWidth(0, 200);

	m_pWebBrowser = new WebBrowser(this);

	QHBoxLayout *hbLay = new QHBoxLayout;
	hbLay->setMargin(0);
	hbLay->setSpacing(0);
	hbLay->addWidget(logAppender, 1);
	hbLay->addWidget(m_pWebBrowser, 1);

	QVBoxLayout *vbLay = new QVBoxLayout;
	vbLay->setMargin(0);
	vbLay->setSpacing(0);
	vbLay->addWidget(entriesTable, 1);
	vbLay->addLayout(hbLay, 1);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	mainLayout->addWidget(m_pFavoritesTree, 1);
	mainLayout->addLayout(vbLay, 5);

	QWidget *centralWidget = new QWidget;
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);
}

void BatDown::readSettings(){
	recList_t rs = m_dbMgr.query("select * from btdl_conf where id=1", true);
	//TODO load default
	QStringList fldK = rs.at(0);
	QStringList fldV = rs.at(1);

	for(int i=0,len=fldK.size(); i<len; ++i){
		m_settings.insert( fldK.at(i), fldV.at(i) );
	}

	QStringList pos = m_settings.value("app_pos").split(",");
	setGeometry(pos[0].toInt(), pos[1].toInt(), pos[2].toInt(), pos[3].toInt());
}

void BatDown::writeSettings(){
	QRect rect = geometry();
	QString pos = QString("%1,%2,%3,%4")
		.arg(rect.x())
		.arg(rect.y())
		.arg(rect.width())
		.arg(rect.height());
	m_settings.insert("app_pos", pos);
	m_dbMgr.updateRecord( m_settings, "rowid=1", "btdl_conf" );
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
		yINFO("日志配置文件加载完毕。");
	} catch(...) {
		std::cout << "Exception..." << std::endl;
		yERROR("Exception occured...");
	}
}

SqliteDB& BatDown::getDbMgr()
{
	return m_dbMgr;
}

settings_t& BatDown::getSettings()
{
	return m_settings;
}
WebBrowser* BatDown::getWebBrowser()
{
	return m_pWebBrowser;
}
FavoritesView* BatDown::getFavoritesView()
{
	return m_pFavoritesTree;
}