#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>

class MainWindow : public Fl_Double_Window
{
public:
	MainWindow(int w, int h, const char* t);
	~MainWindow(void);

	void init(void);

private:
};

#endif // _MAIN_WINDOW_H