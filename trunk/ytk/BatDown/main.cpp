#include "BatDown.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	BatDown w;
	w.show();
	return app.exec();
}
