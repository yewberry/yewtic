#include "MainWindow.h"

Fl_Menu_Item m_menuItems[] = {
		{ "&File",              0, 0, 0, FL_SUBMENU },
		{ "&New File",        0, 0 },
		{ "&Open File...",    FL_CTRL + 'o', 0 },
		{ "&Insert File...",  FL_CTRL + 'i', 0, 0, FL_MENU_DIVIDER },
		{ "&Save File",       FL_CTRL + 's', 0 },
		{ "Save File &As...", FL_CTRL + FL_SHIFT + 's', 0, 0, FL_MENU_DIVIDER },
		//{ "&Close View", FL_CTRL + 'w', (Fl_Callback *)close_cb, 0, FL_MENU_DIVIDER },
		{ "E&xit", FL_CTRL + 'q', 0, 0 },
		{ 0 },

		{ "&Edit", 0, 0, 0, FL_SUBMENU },
		{ "Cu&t",        FL_CTRL + 'x', 0 },
		{ "&Copy",       FL_CTRL + 'c', 0 },
		{ "&Paste",      FL_CTRL + 'v', 0 },
		{ "&Delete",     0, 0 },
		{ 0 },

		{ 0 }
	};

MainWindow::MainWindow(int w, int h, const char* t) : Fl_Double_Window(w, h, t)
{
}

MainWindow::~MainWindow(void)
{
}

void
MainWindow::init(void)
{
	this->begin();

	Fl_Menu_Bar* m = new Fl_Menu_Bar(0, 0, 660, 30);
	m->copy(m_menuItems, this);

	this->end();
}