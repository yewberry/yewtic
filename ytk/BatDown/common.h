#ifndef COMMON_H
#define COMMON_H

#include <iostream> 

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/qtwidgetappender.h>
using namespace log4cplus;
using namespace log4cplus::helpers;
#define yDEBUG(msg) LOG4CPLUS_DEBUG(logger, msg)
#define yINFO(msg)	LOG4CPLUS_INFO(logger, msg)
#define yWARN(msg)	LOG4CPLUS_WARN(logger, msg)
#define yERROR(msg) LOG4CPLUS_ERROR(logger, msg)

#include "exception.h"
#endif // COMMON_H