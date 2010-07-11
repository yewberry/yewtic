#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <iostream>
#include "log.hpp"
#include "CollMgr.h"

class MainWindowUI;

class MainWindow
{
public:
	MainWindow(void);
	~MainWindow(void);

	void show(int argc, char **argv);

	//Menu callback
	void log_switch_cb();
	void test_cb();

	//Getter and Setter
	Log* getLogWindow();
	void setLogWindow(Log *log);
private:
	Log				*m_pLog;
	MainWindowUI	*ui;
};

#endif // _MAIN_WINDOW_H