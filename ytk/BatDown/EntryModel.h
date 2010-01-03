#ifndef ENTRYMODEL_H
#define ENTRYMODEL_H

#include <QtCore/QAbstractTableModel>
#include "BatDown.h"

class EntryModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	EntryModel(BatDown* app, QObject *parent = 0);
	~EntryModel(void);

	virtual QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
	virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
	virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	//virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
	//virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
	
private:
	BatDown		*m_pApp;
	recList_t	entries;
	QStringList headers;
};

#endif