/*
 * ServerModel.cpp
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#include "ServerModel.h"
#include <QtCore>

ServerModel::ServerModel(QObject *parent)
	: XModel("server", parent)
{
    select();
}

ServerModel::ServerModel(QString id, QObject *parent)
	: XModel("server", parent)
{
	getRecordById(id);
    select();
}

bool ServerModel::isActive(){
	QSqlRecord rec = record();
	return rec.value(ServerModel::ACTIVE).toBool();
}

QPointF ServerModel::getUiScenePos(){
	QSqlRecord rec = record();
	QString s;
	if(!rec.isEmpty()){
		s = rec.value(UI_SCENE_POS).toString();
	} else {
		s = "0.0,0.0";
	}
	QStringList ls = s.split(",");
	return QPoint( ls[0].toFloat(), ls[1].toFloat() );
}

void ServerModel::uiScenePos(QPointF pos){
	QSqlRecord rec = record();
	QString id = rec.value(ID).toString();
	rec.setValue( UI_SCENE_POS, QString("%1,%2").arg(pos.x()).arg(pos.y()) );
	editRecordById(id, rec);
}
