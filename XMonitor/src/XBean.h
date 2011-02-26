/*
 * XBean.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef XBEAN_H_
#define XBEAN_H_

#include <QObject>

class XBean : public QObject {

public:
	XBean();
	virtual ~XBean();

	virtual void del();
	virtual void load() = 0;
	virtual void save() = 0;

protected:
	QString m_tbl;
};

#endif /* XBEAN_H_ */
