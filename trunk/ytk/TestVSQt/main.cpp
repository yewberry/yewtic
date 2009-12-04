#include "testvsqt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestVSQt w;
	w.show();
	return a.exec();
}
