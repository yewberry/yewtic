/*
 * XThread.h
 *
 *  Created on: 2011-3-7
 *      Author: Yewberry
 */

#ifndef XTHREAD_H_
#define XTHREAD_H_

#include <QThread>

#define yTDEBUG(msg) (emit sendDebugLog(msg,__FILE__,__LINE__))
#define yTINFO(msg) (emit sendInfoLog(msg,__FILE__,__LINE__))
#define yTWARN(msg) (emit sendWarnLog(msg,__FILE__,__LINE__))
#define yTERROR(msg) (emit sendErrorLog(msg,__FILE__,__LINE__))
#define yTFATAL(msg) (emit sendFatalLog(msg,__FILE__,__LINE__))


class XThread : public QThread
{
	Q_OBJECT

public:
	XThread(QObject *parent = 0, int inter = 300);
	void stop();

signals:
	void sendDebugLog(QString, char*, int);
	void sendInfoLog(QString, char*, int);
	void sendWarnLog(QString, char*, int);
	void sendErrorLog(QString, char*, int);
	void sendFatalLog(QString, char*, int);

protected:
    volatile bool m_stopped;
    int m_threadInter;

};

#endif /* XTHREAD_H_ */
