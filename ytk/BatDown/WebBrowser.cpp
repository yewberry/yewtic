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
	QFile file;
	file.setFileName(":/BatDown/jquery.min.js");
	file.open(QIODevice::ReadOnly);
	m_jsLib = file.readAll();
	file.close();

	m_pWebView = new QWebView;
	m_pAddrBar = new QLineEdit;

	QVBoxLayout *lay = new QVBoxLayout;
	//lay->addLayout(btns);
	//lay->addWidget(m_pAddrBar);
	lay->addWidget(m_pWebView);

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
	m_stepSeq = script.getStepSeq();
	//QString s = m_stepSeq.join(",");
	m_steps = script.getSteps();
	openUrl(url);
}

void WebBrowser::populateJavaScriptWindowObject(){
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("yewticObject", this);
}

void WebBrowser::evalJS(const QString &code){
	//QString code = "var a = $('.lst')[0]; a.value = 'xixi';yewticObject.setValues(a.value+'_abc')";
	m_pWebView->page()->mainFrame()->evaluateJavaScript(code);
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
	m_pWebView->page()->mainFrame()->evaluateJavaScript(m_jsLib);

	for(int i=0, len=m_stepSeq.count(); i<len; ++i){
		QString n = m_stepSeq.at(i);
		QString s = m_steps.value(n);
		if(!s.isEmpty()){
			yINFO(QString::fromLocal8Bit("´¦Àí²½Öè£º%1").arg(n).toLocal8Bit().data());
			m_pWebView->page()->mainFrame()->evaluateJavaScript(s);
		}
	}
	QString s = m_props.value("isLogin");
}
