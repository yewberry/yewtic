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

class ServerViewLink;

class ServerViewNode: public ServerViewItem {

public:
	bool	m_isServerActive;
	enum NodeType { GeneralServer };

	ServerViewNode(QString id, NodeType t = GeneralServer, QMenu *ctxMenu = 0);
	~ServerViewNode();

	void addLink(ServerViewLink *link);
	void removeLink(ServerViewLink *link);

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

	void startBlink();
	void stopBlink();
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

	QSet<ServerViewLink *> m_links;

	QString m_text;
	QPointF	m_storedPosition;

	QColor 	m_txtColor;
	QColor 	m_bgColor;

	QColor 	m_oldBgColor;
	int		m_blinkTimer;
	int		m_blinkCount;

	QColor 	m_outlineColor;

	QMenu* 	m_pContextMenu;
};

#endif /* SERVERVIEWNODE_H_ */
