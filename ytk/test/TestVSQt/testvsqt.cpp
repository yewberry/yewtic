#include "testvsqt.h"
#include "common.h"
#include "testlog.h"
#include "TestQtWebKit.h"
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>

TestVSQt::TestVSQt(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

	QPushButton *testLogBtn = new QPushButton(tr("log4cplus"));
	connect( testLogBtn, SIGNAL(clicked()), this, SLOT(testLogClicked()) );

	QPushButton *testWebBtn = new QPushButton(tr("WebKit"));
	connect( testWebBtn, SIGNAL(clicked()), this, SLOT(testWebKitClicked()) );
	
	QPushButton *testDbusBtn = new QPushButton(tr("D-Bus"));
	connect( testDbusBtn, SIGNAL(clicked()), this, SLOT(testDbusClicked()) );

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(testLogBtn, 0, 0);
	layout->addWidget(testWebBtn, 0, 1);
	layout->addWidget(testDbusBtn, 0, 2);

	setLayout(layout);
	setWindowTitle(tr("Test Dialog"));
}

TestVSQt::~TestVSQt()
{

}

void TestVSQt::testLogClicked()
{
	TestLog *t = new TestLog(this);
	t->show();
}
void TestVSQt::testWebKitClicked(){
	TestQtWebKit *t = new TestQtWebKit(this);
	t->show();
}
void TestVSQt::testDbusClicked()
{
}