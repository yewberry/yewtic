#include "XMonitor.h"

#include <QtGui>
#include <QApplication>

#include "Comm.h"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(res);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    QApplication app(argc, argv);
    app.setStyle("plastique");

    XMonitor w;
    w.setStyleSheet(Comm::stringFromResource(":/style.qss"));
    w.show();
    return app.exec();
}
