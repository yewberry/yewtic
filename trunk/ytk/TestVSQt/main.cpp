#include "testvsqt.h"
#include <QtGui/QApplication>

#include <QtCore/QHash>
#include <QtGui/QTextEdit>

namespace yewtic {
	QHash<QString, QTextEdit*> appenders;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestVSQt w;
	w.show();
	return a.exec();
}
