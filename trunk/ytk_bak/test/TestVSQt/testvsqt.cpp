#include "testvsqt.h"
#include "common.h"
#include "testlog.h"
#include "TestQtWebKit.h"
#include "TestDataView.h"
#include "TestLayout.h"
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
	
	QPushButton *testDataViewBtn = new QPushButton(tr("Data View"));
	connect( testDataViewBtn, SIGNAL(clicked()), this, SLOT(testDataViewClicked()) );

	QPushButton *testLayoutBtn = new QPushButton(tr("Layout"));
	connect( testLayoutBtn, SIGNAL(clicked()), this, SLOT(testLayoutClicked()) );

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(testLogBtn, 0, 0);
	layout->addWidget(testWebBtn, 0, 1);
	layout->addWidget(testDbusBtn, 0, 2);
	layout->addWidget(testDataViewBtn, 1, 0);
	layout->addWidget(testLayoutBtn, 1, 1);

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
void TestVSQt::testWebKitClicked()
{
	TestQtWebKit *t = new TestQtWebKit(this);
	t->show();
}
void TestVSQt::testDbusClicked()
{
}
void TestVSQt::testDataViewClicked()
{
	TestDataView *t = new TestDataView(this);
	t->show();
}
void TestVSQt::testLayoutClicked()
{
	TestLayout *t = new TestLayout(this);
	t->show();
}