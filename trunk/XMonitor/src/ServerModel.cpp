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

bool ServerModel::isActive(QString id){
	QSqlRecord rec = getRecordById(id);
	return rec.value(ServerModel::ACTIVE).toBool();
}

bool ServerModel::isWarning(QString id){
	QSqlRecord rec = getRecordById(id);
	return rec.value(ServerModel::STATUS).toBool();
}

QString ServerModel::stepStatus(QString id){
	QSqlRecord rec = getRecordById(id);
	return rec.value(ServerModel::STEP_STATUS).toString();
}

QPointF ServerModel::getUiScenePos(QString id){
	QSqlRecord rec = getRecordById(id);
	QString s;
	if(!rec.isEmpty()){
		s = rec.value(UI_SCENE_POS).toString();
	}

	if( s.isEmpty() ){
		s = "0.0,0.0";
	}

	QStringList ls = s.split(",");
	return QPoint( ls[0].toFloat(), ls[1].toFloat() );
}

void ServerModel::uiScenePos(QString id, QPointF pos){
	QSqlRecord rec = getRecordById(id);
	rec.setValue( UI_SCENE_POS, QString("%1,%2").arg(pos.x()).arg(pos.y()) );
	editRecordById(id, rec);
}
