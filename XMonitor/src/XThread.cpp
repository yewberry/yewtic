/*
 * XThread.cpp
 *
 *  Created on: 2011-3-7
 *      Author: Yewberry
 */

#include "XThread.h"

XThread::XThread(QObject *parent, int inter)
	: QThread(parent), m_threadInter(inter), m_stopped(false)
{
}

void XThread::stop()
{
	m_stopped = true;
}
