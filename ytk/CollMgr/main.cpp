#include <FL/Fl.H>
#include "MainWindow.h"

int main(int argc, char **argv) {
	MainWindow *wnd = new MainWindow(600, 400, "Collection Manager");
	wnd->init();
	wnd->show();

	return Fl::run();
}