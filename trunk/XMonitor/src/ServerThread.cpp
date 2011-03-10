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
#include "ServerForm.h"

ServerThread::ServerThread(QObject *parent, int inter)
	: XThread(parent, inter)
{
}
void ServerThread::run()
{
    while (!m_stopped){
		QSqlTableModel model;
		model.setTable("server");
		model.select();

		for (int row = 0; row < model.rowCount(); ++row) {
			QSqlRecord record = model.record(row);
			bool act = record.value(ServerForm::ACTIVE).toBool();
			QString nm = record.value(ServerForm::NAME).toString();

			//yTDEBUG(QString("Serv %1 is %2").arg(nm).arg(act));
			/*
			if(act){
				QString id = record.value(ServerForm::ID).toString();
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
