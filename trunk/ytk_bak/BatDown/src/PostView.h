#ifndef POSTVIEW_H
#define POSTVIEW_H

#include <QTableView>
#include "BatDown.h"
#include "PostModel.h"

class PostModel;

class PostView : public QTableView, public BatDownBase
{
	Q_OBJECT

public:
	PostView(BatDown* app, QWidget *parent = 0);
	~PostView();

private slots:
	void onDblClick(const QModelIndex &idx);

private:
	PostModel *m_pModel;
};

#endif // POSTVIEW_H
