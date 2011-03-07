/*
 * ServerViewItem.cpp
 *
 *  Created on: 2011-3-3
 *      Author: Yewberry
 */

#include "ServerViewItem.h"

ServerViewItem::ServerViewItem(QString id, QGraphicsItem *parent)
	: QGraphicsObject(parent), m_id(id)
{
}

ServerViewItem::~ServerViewItem() {
	// TODO Auto-generated destructor stub
}

QString ServerViewItem::id() const {
	return m_id;
}
