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
	enum OpType{EDIT_STEP, MOD_EDIT_SVR_STEPS};
	StepScriptDialog(OpType type = MOD_EDIT_SVR_STEPS, QString svrId = "",
			QString curStepId = "", QWidget *parent = 0);

	QString getCmd();
	QString getCmdResult();
	QString getScript();
	void cmd(QString s);
	void cmdResult(QString s);
	void script(QString s);

private slots:
	void runCmd();

private:
	void drawUi();
	void mapping();

private:
	Ui::StepScriptDialogClass ui;

	QSqlRelationalTableModel*
						m_pModel;
	QDataWidgetMapper*	m_pMapper;
	JsHighlighter*		m_pHighlighter;

	OpType 				m_opType;
	QString 			m_svrId;
	QString				m_initStepId;
};

#endif // STEPSCRIPTDIALOG_H
