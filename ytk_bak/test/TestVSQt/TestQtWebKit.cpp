#include "TestQtWebKit.h"

#include <QtCore/QFile>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>

TestQtWebKit::TestQtWebKit(QWidget *parent, Qt::WFlags flags) : QDialog(parent, flags)
{
	QFile file;
	file.setFileName(":/jquery.min.js");
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
	lay->addLayout(btns);
	lay->addWidget(locationEdit);
	lay->addWidget(view);

	connect(view->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));
	setLayout(lay);
	setWindowTitle(tr("Test WebKit"));
}

TestQtWebKit::~TestQtWebKit(void)
{
}

void TestQtWebKit::populateJavaScriptWindowObject(){
	view->page()->mainFrame()->addToJavaScriptWindowObject("testQtWebKit", this);
}

void TestQtWebKit::evalJS(){
	QString code = "var a = $('.lst')[0]; a.value = 'xixi';testQtWebKit.setValues(a.value+'_abc')";
	view->page()->mainFrame()->evaluateJavaScript(code);
}

void TestQtWebKit::setValues(const QString &value)
{
	locationEdit->setText(value);
}

void TestQtWebKit::finishLoading(bool)
{
	view->page()->mainFrame()->evaluateJavaScript(extjs);
}
