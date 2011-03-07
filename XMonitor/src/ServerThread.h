/*
 * ServerThread.h
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#ifndef SERVERTHREAD_H_
#define SERVERTHREAD_H_

#include "XThread.h"

class ServerThread : public XThread
{
    Q_OBJECT

public:
    ServerThread(QObject *parent = 0, int inter = 300);

protected:
    void run();
};

#endif /* SERVERTHREAD_H_ */
