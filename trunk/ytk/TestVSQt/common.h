#ifndef COMMON_H
#define COMMON_H

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
using namespace log4cplus;
using namespace log4cplus::helpers;

#include <QtGui/QTextEdit>

namespace yewtic {
	extern QHash<QString, QTextEdit*> appenders;
}
#endif // COMMON_H