#ifndef COMMON_H
#define COMMON_H

#include <iostream> 
using namespace std;

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/qtwidgetappender.h>
using namespace log4cplus;
using namespace log4cplus::helpers;
#define yDEBUG(msg) LOG4CPLUS_DEBUG(rootLogger, msg)
#define yINFO(msg)	LOG4CPLUS_INFO(rootLogger, msg)
#define yWARN(msg)	LOG4CPLUS_WARN(rootLogger, msg)
#define yERROR(msg) LOG4CPLUS_ERROR(rootLogger, msg)

extern Logger rootLogger;

#include "exception.h"
#endif // COMMON_H