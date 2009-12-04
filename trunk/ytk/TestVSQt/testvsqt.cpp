#include "testvsqt.h"

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
using namespace log4cplus;
using namespace log4cplus::helpers;

TestVSQt::TestVSQt(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
}

TestVSQt::~TestVSQt()
{

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