#include <QtGui>

#include "BatDown.h"
#include "SqliteDB.h"
#include "TabWidget.h"
#include "TabManager.h"
#include "EntryModel.h"
#include "FavoritesView.h"
#include "TreeNode.h"
#include "PostView.h"
#include "MusicView.h"
#include "ScriptDialog.h"
#include "md5.h"
#include "json.h"
#include "BatDownUtils.h"

BatDown::BatDown(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags){
	initLogger();
	m_dbMgr.open(("ytk.db"));
	init();
	readSettings();
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

void BatDown::editScript()
{
	if(0 == m_pFavoritesTree)return;
	QModelIndex idx = m_pFavoritesTree->selectionModel()->currentIndex();
	TreeNode *node = static_cast<TreeNode*>(idx.internalPointer());
	QString scriptFilename = node->getScriptFilename();

	ScriptDialog *editor = new ScriptDialog(scriptFilename, this);
	editor->show();
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

void BatDown::testPostView()
{
	record_t t;
	t.insert("cata","Fuck");
	t.insert("title","Shit");
	PostModel *m = static_cast<PostModel*>( m_pPostView->model() );
	m->insertRecord(t, 1);
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

	editScriptAct = new QAction(tr("Edit Script"), this);
	connect( editScriptAct, SIGNAL(triggered(bool)),
		this, SLOT(editScript()) );
}

void BatDown::createMenus(){
	QMenuBar *mbar = menuBar();

	fileMenu = mbar->addMenu(tr("&File"));
	fileMenu->addAction(analyseAct);
	fileMenu->addAction(downloadAct);
	fileMenu->addAction(editScriptAct);
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

	QAction *testPost = new QAction("Test Post", this);
	connect( testPost, SIGNAL(triggered(bool)), this, SLOT(testPostView()) );
	testToollBar->addAction(testPost);

}

void BatDown::createStatusBar(){
	m_pWebProgress = new QLabel;
	statusBar()->addPermanentWidget(m_pWebProgress);
}

void BatDown::createCentralArea(){
	m_pFavoritesTree = new FavoritesView(this);
	m_pFavoritesTree->expandToDepth(0);
	m_pMusicView = new MusicView(this);
	m_pPostView = new PostView(this);
	m_pWebTabWidget = new TabWidget(this);
	TabManager::tabManager()->setTabWidget(m_pWebTabWidget);
	TabManager::tabManager()->addTab();

	m_pRightTopSplitter = new QSplitter(Qt::Horizontal);
	m_pRightTopSplitter->addWidget(m_pMusicView);
	m_pRightTopSplitter->addWidget(m_pPostView);

	m_pRightButtomSplitter = new QSplitter(Qt::Horizontal);
	m_pRightButtomSplitter->addWidget(logAppender);
	m_pRightButtomSplitter->addWidget(m_pWebTabWidget);

	m_pRightSplitter = new QSplitter(Qt::Vertical);
	m_pRightSplitter->addWidget(m_pRightTopSplitter);
	m_pRightSplitter->addWidget(m_pRightButtomSplitter);

	m_pMainSplitter = new QSplitter(Qt::Horizontal);
	m_pMainSplitter->addWidget(m_pFavoritesTree);
	m_pMainSplitter->addWidget(m_pRightSplitter);

	setCentralWidget(m_pMainSplitter);
}

void BatDown::readSettings(){
	m_settings = BatDownUtils::readJsonFileToMap("BatDown.json");
	QStringList ls;

	ls = m_settings.value("main_splitter").split(",");
	m_pMainSplitter->setSizes(BatDownUtils::stringListToIntList(ls));
	ls = m_settings.value("r_splitter").split(",");
	m_pRightSplitter->setSizes(BatDownUtils::stringListToIntList(ls));
	ls = m_settings.value("r_t_splitter").split(",");
	m_pRightTopSplitter->setSizes(BatDownUtils::stringListToIntList(ls));
	ls = m_settings.value("r_b_splitter").split(",");
	m_pRightButtomSplitter->setSizes(BatDownUtils::stringListToIntList(ls));

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

	m_settings.insert("r_t_splitter",
		BatDownUtils::intListToStringList(m_pRightTopSplitter->sizes()).join(",") );
	m_settings.insert("r_b_splitter",
		BatDownUtils::intListToStringList(m_pRightButtomSplitter->sizes()).join(",") );
	m_settings.insert("r_splitter",
		BatDownUtils::intListToStringList(m_pRightSplitter->sizes()).join(",") );
	m_settings.insert("main_splitter",
		BatDownUtils::intListToStringList(m_pMainSplitter->sizes()).join(",") );

	BatDownUtils::writeMapToJsonFile(m_settings, "BatDown.json");
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
		yINFO("��־�����ļ�������ϡ�");
	} catch(...) {
		std::cout << "Exception..." << std::endl;
		yERROR("Exception occured...");
	}
}

SqliteDB& BatDown::getDbMgr()
{
	return m_dbMgr;
}

QMap<QString, QString>& BatDown::getSettings()
{
	return m_settings;
}
TabWidget* BatDown::getTabWidget()
{
	return m_pWebTabWidget;
}
FavoritesView* BatDown::getFavoritesView()
{
	return m_pFavoritesTree;
}
PostView* BatDown::getPostView()
{
	return m_pPostView;
}
QLabel* BatDown::getWebProgress()
{
	return m_pWebProgress;
}