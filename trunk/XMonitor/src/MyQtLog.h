#ifndef MYQTLOG_H
#define MYQTLOG_H

#include <QtGui>
#include "ui_MyQtLog.h"
#include <string>
#include <pthread.h>

#define yDEBUG(msg) (MyQtLog::log->d(msg,__FILE__,__LINE__))
#define yINFO(msg) (MyQtLog::log->i(msg,__FILE__,__LINE__))
#define yWARN(msg) (MyQtLog::log->w(msg,__FILE__,__LINE__))
#define yERROR(msg) (MyQtLog::log->e(msg,__FILE__,__LINE__))
#define yFATAL(msg) (MyQtLog::log->f(msg,__FILE__,__LINE__))

class MyQtLog : public QWidget
{
    Q_OBJECT

public:
    ~MyQtLog(void);
    static pthread_mutex_t m_mutex;
    static MyQtLog* init(QString path = QString(), QWidget *parent = 0);
    static MyQtLog	*log;
    QString			filename;
    QFile			*file;
    QTextBrowser	*brs;

public slots:
    void d(QString msg, char *file, int line);
    void i(QString msg, char *file, int line);
    void w(QString msg, char *file, int line);
    void e(QString msg, char *file, int line);
    void f(QString msg, char *file, int line);

    void write(QString msg);

private:
    MyQtLog(QWidget *parent = 0);
    Ui::MyQtLogClass ui;
};

#endif // MYQTLOG_H