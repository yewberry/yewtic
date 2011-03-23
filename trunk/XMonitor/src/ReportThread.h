/*
 * ServerThread.h
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#ifndef REPORTTHREAD_H_
#define REPORTTHREAD_H_

#include "XThread.h"
#include <QVariantMap>
#include <QSqlRecord>

class SSH2Utils;

class ReportThread : public XThread
{
    Q_OBJECT

public:
    ReportThread(QObject *parent = 0, int inter = 300);

protected:
    void run();
};

#endif /* REPORTTHREAD_H_ */
