/*
 * ServerModel.h
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#ifndef SERVERMODEL_H_
#define SERVERMODEL_H_

#include "XModel.h"

class ServerModel : public XModel
{
	Q_OBJECT
public:
	enum { ID = 0, IP = 1, NAME = 2, DESC = 3, USR = 4, PWD = 5, ACTIVE = 6, UI_SCENE_POS = 7 };
	ServerModel(QObject *parent = 0);
	ServerModel(QString id, QObject *parent = 0);

	bool isActive();

	QPointF getUiScenePos();
	void uiScenePos(QPointF pos);
};

#endif /* SERVERMODEL_H_ */
