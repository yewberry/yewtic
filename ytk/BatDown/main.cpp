#include "BatDown.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BatDown w;
	w.show();
	return a.exec();
}
