#include "myqtlog.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyQtLog *log = MyQtLog::init("yew.html");
    log->show();
    yDEBUG("This is debug.");
    yINFO("This is info.");
    yWARN("This is warn.");
    yERROR("This is error.");
    yFATAL("This is fatal.");

    return a.exec();
}
