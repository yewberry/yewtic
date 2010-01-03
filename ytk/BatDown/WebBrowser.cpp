#include "WebBrowser.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui>

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
	lay->addWidget(m_pAddrBar);
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

}

void WebBrowser::populateJavaScriptWindowObject(){
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("yewticObject", this);
}

void WebBrowser::evalJS(){
	QString code = "var a = $('.lst')[0]; a.value = 'xixi';testQtWebKit.setValues(a.value+'_abc')";
	m_pWebView->page()->mainFrame()->evaluateJavaScript(code);
}

void WebBrowser::setValues(const QString &value)
{
	m_pAddrBar->setText(value);
}

void WebBrowser::finishLoading(bool)
{
	m_pWebView->page()->mainFrame()->evaluateJavaScript(m_jsLib);
}
