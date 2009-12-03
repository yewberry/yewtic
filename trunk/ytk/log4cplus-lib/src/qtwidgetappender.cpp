#include <log4cplus/qtwidgetappender.h>


using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;



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
    const tchar * s = sz.c_str();

}
