/*
 * ReportView.h
 *
 *  Created on: 2011-3-13
 *      Author: Administrator
 */

#ifndef REPORTVIEW_H_
#define REPORTVIEW_H_

#include <QWidget>
#include <QListWidget>
#include <QMenu>
#include "../ui_ReportView.h"

class ReportListWidget;

class ReportView  : public QWidget
{
	Q_OBJECT
public:
	ReportView(QWidget *parent = 0);

private:
	void drawUi();

private:
	Ui::ReportViewClass ui;
	ReportListWidget* 	m_pRptList;
};

class ReportListWidget: public QListWidget
{
	Q_OBJECT

public:
	ReportListWidget(QWidget *parent = 0)
		: QListWidget(parent)
	{
		m_pContainer = (ReportView*)parent;
	}

protected:
	void contextMenuEvent(QContextMenuEvent *event){
		m_pCtxMenu->exec(QCursor::pos());
	}

public:
	QMenu*	m_pCtxMenu;
	ReportView* m_pContainer;
};

#endif /* REPORTVIEW_H_ */
