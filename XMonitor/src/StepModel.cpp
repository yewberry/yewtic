/*
 * StepModel.cpp
 *
 *  Created on: 2011-3-14
 *      Author: Yewberry
 */

#include "StepModel.h"

StepModel::StepModel() {
	m_tbl = "step";
    setTable(m_tbl);
    setRelation(SVR_ID, QSqlRelation("server", "id", "name"));
    select();
}

