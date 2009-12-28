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
#define yDEBUG(msg) LOG4CPLUS_DEBUG(g_logger, msg)
#define yINFO(msg)	LOG4CPLUS_INFO(g_logger, msg)
#define yWARN(msg)	LOG4CPLUS_WARN(g_logger, msg)
#define yERROR(msg) LOG4CPLUS_ERROR(g_logger, msg)
extern Logger g_logger;

#include "exception.h"
#endif // COMMON_H