#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
//#include "CollMgrMainUI.h"

int
main(int argc, char **argv) {
	//CollMgrMainUI *mainUi=new CollMgrMainUI;

	//Initial global objects.
	/*
	Fl::visual(FL_DOUBLE|FL_INDEX);

	mainUi->show(argc, argv);
	return Fl::run();
	*/
  Fl_Window *window = new Fl_Window(300,180);
  Fl_Box *box = new Fl_Box(FL_UP_BOX,20,40,260,100,"Hello, World!");
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}