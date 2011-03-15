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
	int a = rowCount();
    for (int row = 0; row < rowCount(); ++row) {
        QSqlRecord rec = record(row);
        rtn.append(rec);
    }
    return rtn;
}

QSqlRecord XModel::getRecordById(QString id){
	setFilter(QString("%1.id = '%2'").arg(m_tbl).arg(id));
	return record();
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
