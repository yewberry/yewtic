#include <log4cplus/qtwidgetappender.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

namespace yewtic {
	QHash<QString, QTextEdit*> LOG4CPLUS_EXPORT appenders;
}

///////////////////////////////////////////////////////////////////////////////
// log4cplus::QtWidgetAppender ctors and dtor
///////////////////////////////////////////////////////////////////////////////

log4cplus::QtWidgetAppender::QtWidgetAppender()
{
}


log4cplus::QtWidgetAppender::QtWidgetAppender(
    const log4cplus::helpers::Properties& properties)
    : Appender(properties)
{
	widgetKey = properties.getProperty( LOG4CPLUS_TEXT("WidgetKey") );
}



log4cplus::QtWidgetAppender::~QtWidgetAppender()
{
    destructorImpl();
}



///////////////////////////////////////////////////////////////////////////////
// log4cplus::QtWidgetAppender public methods
///////////////////////////////////////////////////////////////////////////////

void
log4cplus::QtWidgetAppender::close()
{
    closed = true;
}



///////////////////////////////////////////////////////////////////////////////
// log4cplus::QtWidgetAppender protected methods
///////////////////////////////////////////////////////////////////////////////

// This method does not need to be locked since it is called by
// doAppend() which performs the locking
void
log4cplus::QtWidgetAppender::append(const spi::InternalLoggingEvent& event)
{
    tostringstream buf;
    layout->formatAndAppend(buf, event);
    tstring sz = buf.str();

	QString s = QString::fromWCharArray(sz.c_str());
	LogLevel lvl = event.getLogLevel();
	switch(lvl){
		case log4cplus::DEBUG_LOG_LEVEL:
			s.prepend("<font color=\"gray\">");
			s.append("</font>");
			break;
		case log4cplus::INFO_LOG_LEVEL:
			s.prepend("<font color=\"blue\">");
			s.append("</font>");
			break;
		case log4cplus::WARN_LOG_LEVEL:
			s.prepend("<b><font color=\"orange\">");
			s.append("</font></b>");
			break;
		case log4cplus::ERROR_LOG_LEVEL:
			s.prepend("<b><font color=\"red\">");
			s.append("</font></b>");
			break;
		case log4cplus::FATAL_LOG_LEVEL:
			s.prepend("<b><font color=\"red\">");
			s.append("</font></b>");
			break;
	}

	QTextEdit *text = yewtic::appenders.value(QString::fromWCharArray(widgetKey.c_str()));
	text->append( s );
}
