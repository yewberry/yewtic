#ifndef POSTMODEL_H
#define POSTMODEL_H

#include <QtCore/QAbstractTableModel>
#include "BatDown.h"

class PostModel : public QAbstractTableModel, public BatDownBase
{
	Q_OBJECT

public:
	PostModel(BatDown* app, QObject *parent = 0);
	~PostModel(void);

	virtual QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
	virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
	virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
	virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
	
	void insertRecord(record_t &rec, int position = 0);
	//void updateReocrd(record_t &rec, int position);

private:
	QString		m_table;
	recs_t		m_entries;
	QStringList	m_dbFields;
	QStringList m_headers;
};

#endif //POSTMODEL_H