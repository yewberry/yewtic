#include "testlog.h"

#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTextEdit>
#include <QtGui/QPushButton>

TestLog::TestLog(QWidget *parent, Qt::WFlags flags) : QDialog(parent, flags)
{
	dbgBtn		= new QPushButton(tr("DEBUG"));
	infoBtn		= new QPushButton(tr("INFO"));
	warnBtn		= new QPushButton(tr("WARN"));
	errBtn		= new QPushButton(tr("ERRAR"));
	fatalBtn	= new QPushButton(tr("FATAL"));

	connect( dbgBtn,	SIGNAL(clicked()), this, SLOT(dbgBtnClicked()) );
	connect( infoBtn,	SIGNAL(clicked()), this, SLOT(infoBtnClicked()) );
	connect( warnBtn,	SIGNAL(clicked()), this, SLOT(warnBtnClicked()) );
	connect( errBtn,	SIGNAL(clicked()), this, SLOT(errBtnClicked()) );
	connect( fatalBtn,	SIGNAL(clicked()), this, SLOT(fatalBtnClicked()) );

	QHBoxLayout *btns = new QHBoxLayout;
	btns->addWidget(dbgBtn);
	btns->addWidget(infoBtn);
	btns->addWidget(warnBtn);
	btns->addWidget(errBtn);
	btns->addWidget(fatalBtn);

	text = new QTextEdit;
	text->setReadOnly(true);
	text->setWordWrapMode(QTextOption::NoWrap);
	yewtic::appenders.insert(QString("qtwidgetlog"), text);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(btns);
	layout->addWidget(text);

	setLayout(layout);
	setWindowTitle(tr("Test Log"));
	resize(600, 300);

	initLogger();
}

TestLog::~TestLog()
{
}

void TestLog::initLogger()
{
	LogLog::getLogLog()->setInternalDebugging(true);
	logger = Logger::getRoot();
	
	try 
	{
		ConfigureAndWatchThread configureThread(LOG4CPLUS_TEXT("log4cplus.properties"), 3*1000);
		LOG4CPLUS_DEBUG(logger, "logger conf done.");
		LOG4CPLUS_WARN(logger, "a我的天");
		LOG4CPLUS_WARN(logger, "b你的天");
		LOG4CPLUS_WARN(logger, "cde");
	}
	catch(...) {
		std::cout << "Exception..." << std::endl;
		LOG4CPLUS_FATAL(logger, "Exception occured...");
	}
}
void TestLog::dbgBtnClicked()
{
	LOG4CPLUS_DEBUG(logger, "print debug 打印这DEBUG" );
}

void TestLog::infoBtnClicked()
{
    LOG4CPLUS_INFO(logger, "print info 打印INFO" );
}

void TestLog::warnBtnClicked()
{
    LOG4CPLUS_WARN(logger, "print warn 打印WARN" );
}

void TestLog::errBtnClicked()
{
    LOG4CPLUS_ERROR(logger, "print error 打印ERROR" );
}

void TestLog::fatalBtnClicked()
{}