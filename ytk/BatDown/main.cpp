#include "BatDown.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	try {
	BatDown w;
	w.show();
	} catch(ytk::Exception e) {
		std::string s = e.what();
		std::cerr<<s;
	}
	return app.exec();
}
