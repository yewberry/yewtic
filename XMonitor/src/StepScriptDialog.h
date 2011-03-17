#ifndef STEPSCRIPTDIALOG_H
#define STEPSCRIPTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QMenu>
#include "../ui_StepScriptDialog.h"

class StepModel;

class QDataWidgetMapper;
class CodeEditor;
class StepListWidget;

class StepScriptDialog: public QDialog {
	Q_OBJECT

public:
	enum OpType{EDIT_STEP, EDIT_SVR_STEPS};
	StepScriptDialog(OpType type = EDIT_SVR_STEPS, QString id = "", QWidget *parent = 0);

	QString getCmd();
	QString getCmdResult();
	QString getScript();
	QString getSvrId();
	void cmd(QString s);
	void cmdResult(QString s);
	void script(QString s);
	void svrId(QString s);

signals:
	void stepOrderChanged();

public slots:
	void onStepOrderChanged();

private slots:
	void save();
	void runCmd();
	void onStepListClicked(QListWidgetItem *item);
	void onStepListDoubleClicked(QListWidgetItem *item);

	void onAddStep();
	void onDelStep();


private:
	void drawUi();
	void mapping();
	void setCurStep(QString stepId);
	void setStepListData();
	void createActions();
	void createMenus();

	void runScript();

private:
	Ui::StepScriptDialogClass ui;
	//designer plugin needed
	StepListWidget*		m_pStepList;
	CodeEditor*			m_pCmdEditor;
	CodeEditor*			m_pCmdResultViewer;
	CodeEditor*			m_pScriptEditor;

	StepModel*			m_pModel;
	QDataWidgetMapper*	m_pMapper;

	OpType 				m_opType;
	QString				m_svrId;

	QMenu*				m_pStepListCtxMenu;
    QAction* 			m_pAddStepAct;
	QAction*			m_pDelStepAct;
};

class StepListWidget: public QListWidget
{
	Q_OBJECT

public:
	StepListWidget(QWidget *parent = 0)
		: QListWidget(parent)
	{
		m_pStepScriptDialog = (StepScriptDialog*)parent;
	}

protected:
	void contextMenuEvent(QContextMenuEvent *event){
		m_pCtxMenu->exec(QCursor::pos());
	}
	void dropEvent(QDropEvent *event){
		QListWidget::dropEvent(event);
		m_pStepScriptDialog->onStepOrderChanged();
	}

public:
	QMenu*	m_pCtxMenu;
	StepScriptDialog* m_pStepScriptDialog;
};

#endif // STEPSCRIPTDIALOG_H
