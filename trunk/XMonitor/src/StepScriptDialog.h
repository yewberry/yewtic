#ifndef STEPSCRIPTDIALOG_H
#define STEPSCRIPTDIALOG_H

#include <QDialog>
#include "../ui_StepScriptDialog.h"

class QSqlRelationalTableModel;
class QDataWidgetMapper;
class JsHighlighter;

class StepScriptDialog: public QDialog {
	Q_OBJECT

public:
	StepScriptDialog(QString svrId, QString curStepId = "", QWidget *parent = 0);

public slots:
	void save();

private:
	void drawUi();
	void mapping();

private:
	Ui::StepScriptDialogClass ui;

	QSqlRelationalTableModel*
						m_pModel;
	QDataWidgetMapper*	m_pMapper;
	JsHighlighter*		m_pHighlighter;
	QString 			m_svrId;
	QString				m_initStepId;
};

#endif // STEPSCRIPTDIALOG_H
