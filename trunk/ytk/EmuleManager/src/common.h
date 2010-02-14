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
extern Logger rootLogger;
#define yDEBUG(msg) LOG4CPLUS_DEBUG(rootLogger, msg)
#define yINFO(msg)	LOG4CPLUS_INFO(rootLogger, msg)
#define yWARN(msg)	LOG4CPLUS_WARN(rootLogger, msg)
#define yERROR(msg) LOG4CPLUS_ERROR(rootLogger, msg)

#include <boost/date_time/posix_time/posix_time.hpp>
//using namespace boost;
using namespace boost::posix_time;
using namespace boost::gregorian;

#endif // COMMON_H