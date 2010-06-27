#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include "BaseTableModel.h"

class MusicModel : public BaseTableModel
{
	Q_OBJECT

public:
	MusicModel(BatDown* app, QObject *parent = 0);
	virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

};

#endif //MUSICMODEL_H