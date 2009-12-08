#include "testvsqt.h"
#include "common.h"
#include "testlog.h"
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>

TestVSQt::TestVSQt(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

	QPushButton *testLogBtn = new QPushButton(tr("Test Log"));
	connect( testLogBtn, SIGNAL(clicked()), this, SLOT(testLogClicked()) );

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(testLogBtn, 0, 0);

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