/*
 * TopHeader.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include "TopHeader.h"

#include <QtGui>

TopHeader::TopHeader(QWidget *p) :
	QWidget(p) {
	setFixedHeight(130);
}

void TopHeader::paintEvent(QPaintEvent * /*event*/) {
	QPainter p(this);
	p.fillRect(rect(), QBrush(qApp->palette().window()));

	QLinearGradient headerBackgroundGrd(0, 0, 0, 100);

	headerBackgroundGrd.setColorAt(0, QColor(115, 115, 115));
	headerBackgroundGrd.setColorAt(1, QColor(65, 65, 65));

	p.fillRect(QRect(0, 0, width(), 130), QBrush(headerBackgroundGrd));
	p.drawPixmap(0, 0, QPixmap(":/images/logo.png"));
}
