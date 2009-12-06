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
void TestVSQt::testLog()
{
    std::cout << "Entering main()..." << std::endl;
    LogLog::getLogLog()->setInternalDebugging(true);
    Logger root = Logger::getRoot();
    try 
    {
        ConfigureAndWatchThread configureThread(LOG4CPLUS_TEXT("log4cplus.properties"), 5 * 1000);
        LOG4CPLUS_WARN(root, "Testing....");

    }
    catch(...) {
        std::cout << "Exception..." << std::endl;
		LOG4CPLUS_FATAL(root, "Exception occured...");
    }

    std::cout << "Exiting main()..." << std::endl;
	LOG4CPLUS_DEBUG(root, "Exiting main()"<<213);
	std::cin.get();
}