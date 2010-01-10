#include "WebBrowser.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui>

#include "BatDownUtils.h"
#include "ScriptDialog.h"
#include "SqliteDB.h"
#include "PostView.h"

WebBrowser::WebBrowser(BatDown* app, QWidget *parent, Qt::WFlags flags)
: QWidget(parent, flags), BatDownBase(app)
{
	//once test hit set "TRUE", related step's script will be eval
	//even whe loading is not finish.
	m_props.insert("_test_hit", "FALSE");

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
}

WebBrowser::~WebBrowser(void)
{
}

void WebBrowser::openUrl(const QString &url)
{
	m_pWebView->load( QUrl(url) );
}
void WebBrowser::openUrl(const QString &url, const QString &scriptFilename)
{
	ScriptDialog script(scriptFilename);
	m_stepSeq	= script.getStepSeq();
	m_steps		= script.getSteps();
	m_stepTests = script.getStepTests();
	m_stepFuncs = script.getStepFuncs();
	m_props.remove("nextStep");
	openUrl(url);
}

void WebBrowser::populateJavaScriptWindowObject(){
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("yewtic", this);
}

void WebBrowser::evalJS(const QString &code){
	m_pWebView->page()->mainFrame()->evaluateJavaScript(code);
}

void WebBrowser::evalStepScript(const QString &stepName){
	/*
	QString s = QString(m_jsLib); 
	s.append(";eval(\"");
	s.append(m_stepFuncs);
	s.append("\");");
	*/
	m_pWebView->page()->mainFrame()->evaluateJavaScript(m_jsLib);

	if(stepName.startsWith("SYS_")){
		if(stepName.compare("SYS_END") == 0){
			yDEBUG("SYS_END");
			return;
		}
	} else {
		QString script = m_steps.value(stepName);
		if(!script.isEmpty()){
			yINFO(QString::fromLocal8Bit("´¦Àí²½Öè£º%1").arg(stepName).toLocal8Bit().data());
			m_pWebView->page()->mainFrame()->evaluateJavaScript(script);
		}
	}
}

void WebBrowser::setProperty(const QString &name, const QString &value)
{
	m_props.insert(name, value);
}

QString WebBrowser::getProperty(const QString &name)
{
	return m_props.value(name);
}

void WebBrowser::procPostLists(const QString &jsonStr)
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
			//m_pApp->getDbMgr().insertRecord(rec, "btdl_post");
			static_cast<PostModel*>( m_pApp->getPostView()->model() )->insertRecord(rec, 0);
		} else if(c == 1){
			m_pApp->getDbMgr().updateRecord(rec, QString("url='%1'").arg(url).toLatin1().data() ,"btdl_post");
		} else {
			yERROR(QString::fromLocal8Bit("Duplicate record! key:%1, table:btdl_post")
				.arg(url).toLocal8Bit().data());
		}
	}
}

void WebBrowser::finishLoading(bool)
{
	QString cur = curStep();
	if( m_props.value("_cur_running").compare(cur) == 0 ){
		return;
	}

	m_props.remove("_cur_running");
	yDEBUG(QString("Finish loading and execuate step '%1'").arg(cur).toLatin1().data());
	evalStepScript(cur);
}

void WebBrowser::adjustLocation()
{
	m_pAddrBar->setText(m_pWebView->url().toString());
}

void WebBrowser::setProgress(int p)
{
	QLabel *statusBarField = this->m_pApp->getWebProgress();
	if(p <= 0 || p >= 100){
		statusBarField->setText("Done");
	} else {
		statusBarField->setText(QString("%1%").arg(p));

		if( m_props.contains("_cur_running") ){
			yDEBUG(QString("Step '%1' is running").arg(m_props.value("_cur_running")).toLatin1().data());
			return;
		}

		QString _curStep = curStep();
		m_props.insert("_test_hit", "FALSE");
		QString testCode = m_stepTests.value(_curStep);
		//yDEBUG(QString("TCode:%1").arg(testCode).toLatin1().data());
		if( !testCode.isEmpty() ){
			m_pWebView->page()->mainFrame()->evaluateJavaScript(m_jsLib);
			m_pWebView->page()->mainFrame()->evaluateJavaScript(testCode);
			QString hit = m_props.value("_test_hit");
			if( 0 == hit.compare("TRUE") ){
				m_props.insert("_cur_running", _curStep);
				yDEBUG( QString("set _cur_running to '%1' and eval step.").arg(_curStep).toLatin1().data() );
				evalStepScript(_curStep);
			}
		}
		m_props.insert("_test_hit", "FALSE");
	}
}

QString WebBrowser::curStep(){
	QString nextStep;
	if( m_props.contains("nextStep") ){
		nextStep = m_props.value("nextStep");
	} else {
		nextStep = m_stepSeq.at(0);
	}
	return nextStep;
}

void WebBrowser::logInfo(const QString &msg)
{
	yINFO(msg.toLocal8Bit().data());
}
void WebBrowser::logDebug(const QString &msg)
{
	yDEBUG(msg.toLocal8Bit().data());
}