#ifndef POSTMODEL_H
#define POSTMODEL_H

#include "BaseTableModel.h"

class PostModel : public BaseTableModel
{
	Q_OBJECT

public:
	PostModel(BatDown* app, QObject *parent = 0);
	virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

};

#endif //POSTMODEL_H