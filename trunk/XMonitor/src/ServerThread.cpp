/*
 * ServerThread.cpp
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#include "ServerThread.h"
#include <QtSql>

#include "Comm.h"
#include "XMonitor.h"
#include "ServerView.h"
#include "ServerViewNode.h"
#include "ServerModel.h"

ServerThread::ServerThread(QObject *parent, int inter)
	: XThread(parent, inter)
{
}
void ServerThread::run()
{
    while (!m_stopped){
    	ServerModel model;
    	QVector<QSqlRecord> recs = model.getRecords();

		for (int row = 0; row < recs.count(); ++row) {
			QSqlRecord record = recs.at(row);
			bool act = record.value(ServerModel::ACTIVE).toBool();
			QString nm = record.value(ServerModel::NAME).toString();

			yTDEBUG(QString("Serv %1 is %2").arg(nm).arg(act));
			/*
			if(act){
				QString id = record.value(ServerModel::ID).toString();
				XMonitor *app = (XMonitor*)this->parent();
				ServerViewNode *item = dynamic_cast<ServerViewNode *>(app->serverView()->getItemById(id));
				if(item != 0){

				}
			}
			*/
		}


    	msleep(m_threadInter);
    }
    m_stopped = false;
}
