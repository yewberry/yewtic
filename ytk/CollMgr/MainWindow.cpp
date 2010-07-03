#include "MainWindow.h"

MainWindow::MainWindow(int w, int h, const char* t) : Fl_Double_Window(w, h, t)
{
}

MainWindow::~MainWindow(void)
{
}

void
MainWindow::init(Fl_Menu_Item menuItems[])
{
	this->begin();

	Fl_Menu_Bar* m = new Fl_Menu_Bar(0, 0, 660, 30);
	m->copy(menuItems, this);

	this->end();
}