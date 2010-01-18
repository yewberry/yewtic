#include "WebView.h"
#include "TabManager.h"
#include "Tab.h"
#include "NetworkAccessManager.h"

#include "BatDownUtils.h"
#include "SqliteDB.h"
#include "PostView.h"

#include <QtWebKit/QWebPage>

WebView::WebView(BatDown *app, QWidget *parent)
        : QWebView(parent), BatDownBase(app)
{
    //m_pWebPage = new WebPage(this);
	m_pWebPage = new QWebPage(this);
	NetworkAccessManager *manager = NetworkAccessManager::networkAccessManager();
    m_pWebPage->setNetworkAccessManager(manager);
    setPage(m_pWebPage);

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

	connect(this, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
	connect(this, SIGNAL(loadFinished(bool)), this, SLOT(finishLoading(bool)));
	connect(m_pWebPage->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));

	setWindowTitle(tr("Web Browser"));

	//TODO Settings dialog
	QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, false);
}

QWebView* WebView::createWindow(QWebPage::WebWindowType /*type*/)
{
    return TabManager::tabManager()->addTab(QUrl())->webView();
}


void WebView::openUrl(const QUrl &url)
{
	QString msg = QString::fromLocal8Bit("打开地址:%1").arg(url.toString());
	yINFO((const char *)msg.toLocal8Bit());
	this->load( url );
}
void WebView::openUrl(const QUrl &url, const QString &scriptFilename)
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

void WebView::procPostList(const QString &jsonStr)
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

QString WebView::openPageSilently(const QString &url, const QString &step, const QString &retProp){
	/*
	WebPage *wb = new WebPage(m_pApp);
	wb->setProperty("nextStep", step);
	wb->openUrl(url, m_scriptFilename);
	wb->show();
	int a = 0;
	QString ret = wb->getProperty(retProp);
	int b = 0;
	*/
	return "";
}

void WebView::evalStepScript(const QString &script){
	evalScript(m_jsLib);
	evalScript(m_script);

	if(!script.isEmpty()){
		yINFO(QString::fromLocal8Bit("处理脚本：%1").arg(script).toLocal8Bit().data());
		evalScript(script);
	}
}

void WebView::finishLoading(bool)
{
	if( !m_props.contains("nextStep") ){
		m_props.insert("nextStep", "Yew.main()");
	}
		
	QString nextStep = m_props.value("nextStep");
	if( nextStep.isEmpty() || nextStep.compare("SYS_END") == 0 )return;

	yDEBUG(QString("Finish loading and execuate script: '%1'").arg(nextStep).toLatin1().data());
	evalStepScript(nextStep);
}

void WebView::logInfo(const QString &msg)
{
	yINFO(msg.toLocal8Bit().data());
}

void WebView::logDebug(const QString &msg)
{
	yDEBUG(msg.toLocal8Bit().data());
}

void WebView::setProperty(const QString &name, const QString &value)
{
	m_props.insert(name, value);
}

QString WebView::getProperty(const QString &name)
{
	return m_props.value(name);
}

void WebView::removeProperty(const QString &name)
{
	m_props.remove(name);
}

void WebView::populateJavaScriptWindowObject(){
	m_pWebPage->mainFrame()->addToJavaScriptWindowObject("yewtic", this);
}

void WebView::evalScript(const QString &script){
	m_pWebPage->mainFrame()->evaluateJavaScript(script);
}