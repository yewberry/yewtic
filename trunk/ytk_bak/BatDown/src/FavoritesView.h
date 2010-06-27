#ifndef FAVORITESVIEW_H
#define FAVORITESVIEW_H

#include <QTreeView>
#include "BatDown.h"

class FavoritesView : public QTreeView, public BatDownBase
{
	Q_OBJECT

public:
	FavoritesView(BatDown* app, QWidget *parent = 0);
	~FavoritesView();

private slots:
	void onDblClick(const QModelIndex &idx);
};

#endif // FAVORITESVIEW_H
