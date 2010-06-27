#include "EmuleManager.h"
#include <QtGui/QApplication>

Logger rootLogger = Logger::getRoot();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EmuleManager w;
	w.show();
	return a.exec();
}
