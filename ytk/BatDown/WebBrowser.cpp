#include "WebBrowser.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui>

WebBrowser::WebBrowser(QWidget *parent, Qt::WFlags flags) : QWidget(parent, flags)
{
	QFile file;
	file.setFileName(":/BatDown/jquery.min.js");
	file.open(QIODevice::ReadOnly);
	extjs = file.readAll();
	file.close();

	gooBtn = new QPushButton(tr("Google Key Value"));
	connect( gooBtn, SIGNAL(clicked()), this, SLOT(evalJS()) );

	QHBoxLayout *btns = new QHBoxLayout;
	btns->addWidget(gooBtn);

	view = new QWebView;
	view->load(QUrl("http://www.google.com/ncr"));
	connect(view, SIGNAL(loadFinished(bool)), this, SLOT(finishLoading(bool)));
	
	locationEdit = new QLineEdit;

	QVBoxLayout *lay = new QVBoxLayout;
	//lay->addLayout(btns);
	//lay->addWidget(locationEdit);
	lay->addWidget(view);

	connect(view->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));
	setLayout(lay);
	setWindowTitle(tr("Test WebKit"));
}

WebBrowser::~WebBrowser(void)
{
}

void WebBrowser::populateJavaScriptWindowObject(){
	view->page()->mainFrame()->addToJavaScriptWindowObject("testQtWebKit", this);
}

void WebBrowser::evalJS(){
	QString code = "var a = $('.lst')[0]; a.value = 'xixi';testQtWebKit.setValues(a.value+'_abc')";
	view->page()->mainFrame()->evaluateJavaScript(code);
}

void WebBrowser::setValues(const QString &value)
{
	locationEdit->setText(value);
}

void WebBrowser::finishLoading(bool)
{
	view->page()->mainFrame()->evaluateJavaScript(extjs);
}
