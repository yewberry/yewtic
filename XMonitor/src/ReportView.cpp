/*
 * ReportView.cpp
 *
 *  Created on: 2011-3-13
 *      Author: Administrator
 */

#include "ReportView.h"

ReportView::ReportView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	drawUi();
}

void ReportView::drawUi() {
	m_pRptList = new ReportListWidget(this);
	ui.horizontalLayout->insertWidget(0, m_pRptList, 1);
	ui.horizontalLayout->setStretch(1, 5);
}

