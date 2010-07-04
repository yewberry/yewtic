#include <FL/Fl.H>
#include "MainWindowUI.h"



int main(int argc, char **argv) {
	MainWindowUI *wnd = new MainWindowUI;
	Fl::scheme("gtk+");
	wnd->show(argc, argv);

	return Fl::run();
}