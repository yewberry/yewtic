#ifndef FAVORITESMODEL_H
#define FAVORITESMODEL_H

#include <QtCore/QAbstractItemModel>
#include "BatDown.h"

class TreeNode;

class FavoritesModel : public QAbstractItemModel, public BatDownBase
{
	Q_OBJECT

public:
	FavoritesModel(BatDown* app, QObject *parent = 0);
	~FavoritesModel();

	virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
	virtual QModelIndex parent(const QModelIndex &index) const;

	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	virtual int rowCount(const QModelIndex &parent) const;
	virtual int columnCount(const QModelIndex &parent) const;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	void setupModelData();

private:
	TreeNode	*rootNode;
	recList_t	records;

};

#endif // FAVORITESMODEL_H
