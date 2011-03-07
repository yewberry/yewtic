/*
 * ServerViewItem.h
 *
 *  Created on: 2011-3-3
 *      Author: Yewberry
 */

#ifndef SERVERVIEWITEM_H_
#define SERVERVIEWITEM_H_

#include <QGraphicsItem>

class ServerViewItem : public QGraphicsObject {
public:
	ServerViewItem(QString id = "", QGraphicsItem *parent = 0);
	~ServerViewItem();

	QString id() const;

protected:
	QString m_id;
};

#endif /* SERVERVIEWITEM_H_ */
