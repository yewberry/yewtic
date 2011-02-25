/*
 * TopHeader.h
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include <QWidget>

#ifndef TOPHEADER_H_
#define TOPHEADER_H_

class TopHeader: public QWidget {
public:
	TopHeader(QWidget *p = 0);
protected:
	void paintEvent(QPaintEvent * event);
};

#endif /* TOPHEADER_H_ */
