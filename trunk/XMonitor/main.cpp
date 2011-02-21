#include "XMonitor.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XMonitor w;
    w.show();
    return a.exec();
}
