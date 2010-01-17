#ifndef MUSICVIEW_H
#define MUSICVIEW_H

#include <QTableView>
#include "BatDown.h"
#include "MusicModel.h"

class MusicView : public QTableView, public BatDownBase
{
	Q_OBJECT

public:
	MusicView(BatDown* app, QWidget *parent = 0);
	~MusicView();

private slots:
	void onDblClick(const QModelIndex &idx);

private:
	MusicModel *m_pModel;
};

#endif // MUSICVIEW_H
