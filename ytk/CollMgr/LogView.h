#ifndef _LOG_VIEW_H
#define _LOG_VIEW_H

#include "log.hpp"

class LogView: public Log
{
public:
	LogView(int x, int y, int w, int h, const char *title="", char bg=FL_GRAY);
	~LogView(void);
};

#endif