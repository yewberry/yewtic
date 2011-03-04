/*
 * ServerThread.h
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#ifndef SERVERTHREAD_H_
#define SERVERTHREAD_H_

#define yTDEBUG(msg) (emit sendDebugLog(msg,__FILE__,__LINE__))

#include <QThread>
;
class ServerThread : public QThread
{
    Q_OBJECT

public:
    ServerThread(QObject * parent = 0, int inter = 300);
    void stop();

signals:
	void sendDebugLog(QString, char*, int);

protected:
    void run();

private:
    volatile bool m_stopped;
    int m_threadInter;
};

#endif /* SERVERTHREAD_H_ */
