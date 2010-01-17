#include "WebPage.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui>

#include "BatDownUtils.h"
#include "ScriptDialog.h"
#include "SqliteDB.h"
#include "PostView.h"

WebPage::WebPage(BatDown* app, QWidget *parent, Qt::WFlags flags)
: QWidget(parent, flags), BatDownBase(app)
{
	QFile file;
	file.setFileName(":/BatDown/jquery.min.js");
	file.open(QIODevice::ReadOnly);
	m_jsLib = file.readAll();
	file.close();

	file.setFileName(":/BatDown/jquery.json.min.js");
	file.open(QIODevice::ReadOnly);
	m_jsLib.append( file.readAll() );
	file.close();

	file.setFileName(":/BatDown/yewtic.js");
	file.open(QIODevice::ReadOnly);
	m_jsLib.append(";");
	m_jsLib.append( file.readAll() );
	m_jsLib.append(";");
	file.close();

	m_pWebView = new QWebView;
	m_pAddrBar = new QLineEdit;

	QVBoxLayout *lay = new QVBoxLayout;
	//lay->addLayout(btns);
	//lay->addWidget(m_pAddrBar);
	lay->addWidget(m_pWebView);

	connect(m_pWebView, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(finishLoading(bool)));
	connect(m_pWebView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));

	setLayout(lay);
	setWindowTitle(tr("Web Browser"));

	//TODO Settings dialog
	QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, false);
}

WebPage::~WebPage(void)
{
}

void WebPage::openUrl(const QString &url)
{
	QString msg = QString::fromLocal8Bit("打开地址:%1").arg(url);
	yINFO((const char *)msg.toLocal8Bit());
	m_pWebView->load( QUrl(url) );
}
void WebPage::openUrl(const QString &url, const QString &scriptFilename)
{
	QFile file;
	file.setFileName(scriptFilename);
	file.open(QIODevice::ReadOnly);
	m_scriptFilename.clear();
	m_script.clear();
	m_scriptFilename = scriptFilename;
	m_script = QString::fromLocal8Bit( file.readAll() );
	file.close();

	openUrl(url);
}

void WebPage::procPostList(const QString &jsonStr)
{
	recs_t recs = BatDownUtils::jsonStringToRecordList(jsonStr);
	for(int i=0, len=recs.size(); i<len; ++i){
		record_t rec = recs.at(i);
		ptime t(second_clock::local_time());
		rec.insert( "last_index_dt", QString::fromStdString(to_iso_extended_string(t)) );

		QString url = rec.value("url");
		QString sql = QString("SELECT COUNT(*) FROM btdl_post WHERE url='%1'").arg( url );
		QStringList count = m_pApp->getDbMgr().query( sql.toLocal8Bit().data() ).at(0);
		int c = QString( count.at(0) ).toInt();
		if(c == 0){
			static_cast<PostModel*>( m_pApp->getPostView()->model() )->insertRecord(rec, 0);
		} else if(c == 1){
			m_pApp->getDbMgr().updateRecord(rec, QString("url='%1'").arg(url).toLatin1().data() ,"btdl_post");
		} else {
			yERROR(QString::fromLocal8Bit("Duplicate record! key:%1, table:btdl_post")
				.arg(url).toLocal8Bit().data());
		}
	}
}

QString WebPage::openPageSilently(const QString &url, const QString &step, const QString &retProp){
	WebPage *wb = new WebPage(m_pApp);
	wb->setProperty("nextStep", step);
	wb->openUrl(url, m_scriptFilename);
	wb->show();
	int a = 0;
	QString ret = wb->getProperty(retProp);
	int b = 0;
	return "";
}

void WebPage::evalStepScript(const QString &script){
	evalScript(m_jsLib);
	evalScript(m_script);

	if(!script.isEmpty()){
		yINFO(QString::fromLocal8Bit("处理脚本：%1").arg(script).toLocal8Bit().data());
		evalScript(script);
	}
}

void WebPage::finishLoading(bool)
{
	if( !m_props.contains("nextStep") ){
		m_props.insert("nextStep", "Yew.main()");
	}
		
	QString nextStep = m_props.value("nextStep");
	if( nextStep.isEmpty() || nextStep.compare("SYS_END") == 0 )return;

	yDEBUG(QString("Finish loading and execuate script: '%1'").arg(nextStep).toLatin1().data());
	evalStepScript(nextStep);
}

void WebPage::adjustLocation()
{
	m_pAddrBar->setText(m_pWebView->url().toString());
}

void WebPage::setProgress(int p)
{
	QLabel *statusBarField = this->m_pApp->getWebProgress();
	if(p <= 0 || p >= 100){
		statusBarField->setText("Done");
	} else {
		statusBarField->setText(QString("%1%").arg(p));
	}
}

void WebPage::logInfo(const QString &msg)
{
	yINFO(msg.toLocal8Bit().data());
}

void WebPage::logDebug(const QString &msg)
{
	yDEBUG(msg.toLocal8Bit().data());
}

void WebPage::setProperty(const QString &name, const QString &value)
{
	m_props.insert(name, value);
}

QString WebPage::getProperty(const QString &name)
{
	return m_props.value(name);
}

void WebPage::removeProperty(const QString &name)
{
	m_props.remove(name);
}

void WebPage::populateJavaScriptWindowObject(){
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("yewtic", this);
}

void WebPage::evalScript(const QString &script){
	m_pWebView->page()->mainFrame()->evaluateJavaScript(script);
}