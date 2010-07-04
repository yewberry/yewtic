#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <iostream>
#include "log.hpp"
#include <FL/Fl_Tree.H>

class MainWindow
{
public:
	MainWindow(void);
	~MainWindow(void);

	void init();
	void buildTree(Fl_Tree *tree);

	//Menu callback
	void log_switch_cb();
	void test_cb();

	//Getter and Setter
	Log* getLogWindow();
	void setLogWindow(Log *log);
private:
	Log		*m_pLog;
};

#endif // _MAIN_WINDOW_H