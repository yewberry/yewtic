/*
 * StepModel.h
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#ifndef STEPMODEL_H_
#define STEPMODEL_H_

#include "XModel.h"

class StepModel : public XModel
{
	Q_OBJECT
public:
	enum { ID = 0, SVR_ID = 1, NAME = 2, DESC = 3, CMD = 4, SCRIPT = 5, CMD_RESULT = 6, SEQ = 7 };
	StepModel(QObject *parent = 0);

	void setModelBySvrId(QString svrId);
	QString getSvrId(QString id);
};

#endif /* STEPMODEL_H_ */
