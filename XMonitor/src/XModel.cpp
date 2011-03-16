/*
 * XModel.cpp
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#include "XModel.h"
#include "Comm.h"
#include <QSqlError>

XModel::XModel(QString tbl, QObject * parent)
	: QSqlRelationalTableModel(parent), m_tbl(tbl)
{
	setTable(m_tbl);
}

void XModel::submitAll(){
	bool b = QSqlRelationalTableModel::submitAll();
    if(b == false){
    	QSqlError err = lastError();
    	yERROR(err.text());
    }
}

QVector<QSqlRecord> XModel::getRecords(){
	setFilter("1 = 1");
	QVector<QSqlRecord> rtn;
    for (int i = 0; i < rowCount(); ++i) {
        QSqlRecord rec = record(i);
        rtn.append(rec);
    }
    return rtn;
}

QSqlRecord XModel::getRecordById(QString id){
	setFilter(QString("%1.id = '%2'").arg(m_tbl).arg(id));
	QSqlRecord r;
	if (rowCount() == 1) {
		r = record(0);

	} else {
		yERROR(QString("Can't find %1.").arg(id));
	}
	return r;
}

void XModel::deleteRecordById(QString id){
	setFilter(QString("%1.id = '%2'").arg(m_tbl).arg(id));
	if (rowCount() == 1) {
	    bool b = removeRows(0, 1);
	    if(b == false){
	    	QSqlError err = lastError();
	    	yERROR(err.text());
	    }
	    submit();
	} else {
		yERROR(QString("Can't find %1 to delete.").arg(id));
	}
}

void XModel::editRecordById(QString id, QSqlRecord rec){
	setFilter(QString("%1.id = '%2'").arg(m_tbl).arg(id));
	if (rowCount() == 1) {
		bool b = setRecord(0, rec);
	    if(b == false){
	    	QSqlError err = lastError();
	    	yERROR(err.text());
	    }
	    submit();
	} else {
		yERROR(QString("Can't find %1 to edit.").arg(id));
	}
}
