#include "LogView.h"

LogView::LogView(int x, int y, int w, int h, const char *title, char bg)
: Log(x, y, w, h, title, bg)
{
	LogInit(x, y, w, h, title, bg, true);
	/*
	if(!LogIsInitialised()){
		LogInit(x, y, w, h, title, bg, true);
	}

	if(!LogIsInitialised()){
		fprintf(stderr,"Cannot initialise Log!");
	} else {
		LogInfo(("OK, Log is initialised"));
	}
	*/
}

LogView::~LogView(void)
{
}
