/*
 * StepModel.cpp
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#include "StepModel.h"
#include "Comm.h"

StepModel::StepModel(QObject *parent)
	: XModel("step", parent)
{
    //setRelation(SVR_ID, QSqlRelation("server", "id", "name"));
    select();
}

void StepModel::setModelBySvrId(QString svrId){
	setFilter(QString("%1.svr_id = '%2'").arg(m_tbl).arg(svrId));
}

QString StepModel::getSvrId(QString id){
	setFilter(QString("%1.id = '%2'").arg(m_tbl).arg(id));
	QString r;
	if (rowCount() == 1) {
		r = record(0).value(StepModel::SVR_ID).toString();
	} else {
		yERROR(QString("Can't find %1.").arg(id));
	}
	return r;
}
