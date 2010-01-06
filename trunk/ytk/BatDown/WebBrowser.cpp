#include "WebBrowser.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui>

#include "BatDownUtils.h"
#include "ScriptDialog.h"

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
	QString s = QString(m_jsLib); 
	s.append(";eval(\"");
	s.append(m_stepFuncs);
	s.append("\");");
	m_pWebView->page()->mainFrame()->evaluateJavaScript(s);

	if(stepName.startsWith("SYS_")){
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

void WebBrowser::finishLoading(bool)
{
	yDEBUG("finish loading");
	QString curStep = curStep();
	evalStepScript(curStep);
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
		m_props.insert("_test_hit", "FALSE");
		QString curStep = curStep();
		m_stepTests.value(curStep);
		QString hit = m_props.value("_test_hit");
		if( 0 == hit.compare("TRUE") ){
			yDEBUG("get it");
		} else {
			yDEBUG("loading...");
		}
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