#include "XMonitor.h"

#include <QtGui>
#include <QApplication>

#include "Common.h"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(res);

    QApplication app(argc, argv);
    app.setStyle("plastique");

    XMonitor w;
    w.setStyleSheet(Common::stringFromResource(":/style.qss"));
    w.show();
    return app.exec();
}
