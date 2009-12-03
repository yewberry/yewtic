#include "QApplication"
#include "QPushButton"
#include "QTextCodec"
#include "QTranslator"

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

void testLog(){
    cout << "Entering main()..." << endl;
    LogLog::getLogLog()->setInternalDebugging(true);
    Logger root = Logger::getRoot();
    try 
    {
        ConfigureAndWatchThread configureThread(LOG4CPLUS_TEXT("log4cplus.properties"), 5 * 1000);
        LOG4CPLUS_WARN(root, "Testing....");

    }
    catch(...) {
        cout << "Exception..." << endl;
		LOG4CPLUS_FATAL(root, "Exception occured...");
    }

    cout << "Exiting main()..." << endl;
	LOG4CPLUS_DEBUG(root, "Exiting main()"<<213);
	cin.get();
}

int main(int argc, char *argv[])
{
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QApplication app(argc, argv);

	QTranslator appTranslator;
	appTranslator.load("testQt_cn", ".");
    app.installTranslator(&appTranslator);

	QPushButton hello(QObject::tr("abc"));
	hello.resize(100, 30);

	hello.show();
	testLog();
	return app.exec();
}