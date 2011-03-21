/*
 * ServerThread.h
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#ifndef SERVERTHREAD_H_
#define SERVERTHREAD_H_

#include "XThread.h"
#include <QVariantMap>
#include <QSqlRecord>

class SSH2Utils;

class ServerThread : public XThread
{
    Q_OBJECT

public:
    ServerThread(QObject *parent = 0, int inter = 300);

protected:
    void run();
    SSH2Utils* getSsh(QString ip, QString usr, QString pwd);
    QVariantMap runStepScript(QSqlRecord stepRec, SSH2Utils* ssh, QVariantMap &stepCtx);
};

#endif /* SERVERTHREAD_H_ */
