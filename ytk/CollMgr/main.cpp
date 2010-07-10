#include <FL/Fl.H>
#include "MainWindow.h"
#include "log.hpp"


int main(int argc, char **argv) {
	MainWindow *wnd = new MainWindow;
	Fl::scheme("gtk+");
	//Fl::scheme("plastic");
	wnd->show(argc, argv);

	return Fl::run();
}