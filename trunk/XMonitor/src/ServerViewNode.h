/*
 * ServerViewNode.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef SERVERVIEWNODE_H_
#define SERVERVIEWNODE_H_

#include <QApplication>
#include <QSet>
#include <QColor>
#include <QMenu>
#include "ServerViewItem.h"

class ServerView;
class ServerViewLink;

class ServerViewNode: public ServerViewItem {

public:
	enum NodeType { GeneralServer };

	ServerViewNode(QString id, NodeType t = GeneralServer, QMenu *ctxMenu = 0,
			ServerView *servView = 0);
	~ServerViewNode();
	void editItem();
	void deleteItem();

	void addLink(ServerViewLink *link);
	void removeLink(ServerViewLink *link);

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void saveNodePos();

	QString text() const;
	QPointF storedPosition() const;

protected:
	void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
	void timerEvent(QTimerEvent *event);

private:
	QRectF outlineRect() const;
	int roundness(double size) const;
	bool isActive();
	bool isWarning();

	QSet<ServerViewLink *> m_links;

	QString m_text;
	QPointF	m_storedPosition;

	QColor 	m_txtColor;
	QColor 	m_bgColor;
	QColor 	m_outlineColor;

	int		m_blinkTimer;

	QMenu* 		m_pContextMenu;
	ServerView* m_pServerView;
};

#endif /* SERVERVIEWNODE_H_ */
