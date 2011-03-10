#include "StepScriptDialog.h"
#include <QtGui>
#include <QtSql>
#include "Comm.h"
#include "StepForm.h"
#include "CodeEditor.h"
#include "JsHighlighter.h"
#include "SSH2Utils.h"
#include "ServerForm.h"
#include <iostream>

StepScriptDialog::StepScriptDialog(OpType type, QString svrId, QString curStepId, QWidget *parent)
	: QDialog(parent), m_opType(type), m_svrId(svrId), m_initStepId(curStepId)
{
	ui.setupUi(this);
	drawUi();
	mapping();
}

void StepScriptDialog::mapping() {
	m_pModel = new QSqlRelationalTableModel(this);
	m_pModel->setTable("step");
	m_pModel->setRelation(StepForm::SVR_ID, QSqlRelation("server", "id", "name"));
	m_pModel->setSort(StepForm::SEQ, Qt::AscendingOrder);
	m_pModel->select();

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(ui.cmd, StepForm::CMD);
	m_pMapper->addMapping(ui.cmdResult, StepForm::CMD_RESULT);
	m_pMapper->addMapping(m_pScriptEditor, StepForm::SCRIPT);

	if( !m_initStepId.isEmpty() ) {
        for (int row = 0; row < m_pModel->rowCount(); ++row) {
            QSqlRecord record = m_pModel->record(row);
            if (record.value(StepForm::ID).toString() == m_initStepId) {
                m_pMapper->setCurrentIndex(row);
                break;
            }
        }
    } else {
    	m_pMapper->toFirst();
    }

	ui.steplist->setModel(m_pModel);
}

void StepScriptDialog::drawUi() {
	switch(m_opType){
	case EDIT_STEP :
		ui.steplist->hide();
		break;
	case MOD_EDIT_SVR_STEPS:
		ui.steplist->show();
		break;
	default:
		break;
	}
	m_pScriptEditor = new CodeEditor(this);
	m_pHighlighter = new JsHighlighter(m_pScriptEditor->document());
	ui.editorLayout->addWidget(m_pScriptEditor);

	QDialogButtonBox *buttonBox = ui.buttonBox;
	connect( buttonBox, SIGNAL(accepted()), this, SLOT(accept()) );
	connect( buttonBox, SIGNAL(rejected()), this, SLOT(reject()) );
	connect( ui.runCmdBtn, SIGNAL(clicked()), this, SLOT(runCmd()) );
}

void StepScriptDialog::runCmd(){
	ServerForm svr(m_svrId, ServerForm::INQ);
	SSH2Utils ssh2;
	ssh2.init();
	int rc = 0;
	const char *ip  = svr.getIp().toStdString().c_str();
	const char *usr = svr.getUser().toStdString().c_str();
	const char *pwd = svr.getPwd().toStdString().c_str();
	rc = ssh2.connect(ip, usr, pwd);

	if(rc == 0){
		char *t = "ls -l";
		rc = ssh2.exec(t);
		std::string str = ssh2.execResultStr();
		std::cout << "CMD RESULT:\n" << str << std::endl;
	}
}

void StepScriptDialog::cmd(QString s){
	ui.cmd->setPlainText(s);
}

void StepScriptDialog::cmdResult(QString s){
	ui.cmdResult->setPlainText(s);
}

void StepScriptDialog::script(QString s){
	m_pScriptEditor->setPlainText(s);
}

QString StepScriptDialog::getCmd(){
	return ui.cmd->toPlainText();
}

QString StepScriptDialog::getCmdResult(){
	return ui.cmdResult->toPlainText();
}

QString StepScriptDialog::getScript(){
	return m_pScriptEditor->toPlainText();
}
