#ifndef _LOG4CPLUS_QT_WIDGET_APPENDER_HEADER_
#define _LOG4CPLUS_QT_WIDGET_APPENDER_HEADER_

#include <log4cplus/appender.h>
#include <log4cplus/helpers/property.h>

namespace log4cplus {

    /**
     * Appends log events to a file. 
     */
    class LOG4CPLUS_EXPORT QtWidgetAppender
        : public Appender
    {
    public:
      // Ctors
        QtWidgetAppender();
        QtWidgetAppender(const log4cplus::helpers::Properties& properties);

      // Dtor
        virtual ~QtWidgetAppender();

      // Methods
        virtual void close();

    protected:
        virtual void append(const log4cplus::spi::InternalLoggingEvent& event);

    private:
      // Disallow copying of instances of this class
        QtWidgetAppender(const QtWidgetAppender&);
        QtWidgetAppender& operator=(const QtWidgetAppender&);
    };

} // end namespace log4cplus

#endif // _LOG4CPLUS_QT_WIDGET_APPENDER_HEADER_

