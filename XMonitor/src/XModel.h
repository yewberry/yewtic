/*
 * XModel.h
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#ifndef XMODEL_H_
#define XMODEL_H_

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QVector>

class XModel : public QSqlRelationalTableModel{
	Q_OBJECT

public:
	XModel(QString tbl, QObject * parent = 0);

	void submitAll();
	QVector<QSqlRecord> getRecords();
	QSqlRecord getRecordById(QString id);
	void deleteRecordById(QString id);
	void editRecordById(QString id, QSqlRecord rec);

protected:
	QString m_tbl;
};

#endif /* XMODEL_H_ */
