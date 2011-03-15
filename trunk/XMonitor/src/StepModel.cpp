/*
 * StepModel.cpp
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#include "StepModel.h"

StepModel::StepModel()
	: XModel("step")
{
    setRelation(SVR_ID, QSqlRelation("server", "id", "name"));
    select();
}

