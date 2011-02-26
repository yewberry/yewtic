/*
 * ServerViewLink.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#include "ServerViewLink.h"
#include "ServerViewNode.h"

ServerViewLink::ServerViewLink(ServerViewNode *fromNode, ServerViewNode *toNode) {
	m_fromNode = fromNode;
	m_toNode = toNode;

	m_fromNode->addLink(this);
	m_toNode->addLink(this);

	setFlags(QGraphicsItem::ItemIsSelectable);
	setZValue(-1);

	trackNodes();

}

ServerViewLink::~ServerViewLink() {
	m_fromNode->removeLink(this);
	m_toNode->removeLink(this);
}

ServerViewNode* ServerViewLink::fromNode() const
{
    return m_fromNode;
}

ServerViewNode* ServerViewLink::toNode() const
{
    return m_toNode;
}

void ServerViewLink::trackNodes()
{
    setLine(QLineF(m_fromNode->pos(), m_toNode->pos()));
}
