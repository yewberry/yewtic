#include "StepScriptDialog.h"
#include <QtGui>
#include <QtSql>
#include "Comm.h"
#include "StepForm.h"
#include "JsHighlighter.h"

StepScriptDialog::StepScriptDialog(QString svrId, QString curStepId, QWidget *parent)
	: QDialog(parent), m_svrId(svrId), m_initStepId(curStepId)
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
	m_pMapper->addMapping(ui.script, StepForm::SCRIPT);

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
	m_pHighlighter = new JsHighlighter(ui.script->document());

	QDialogButtonBox *buttonBox = ui.buttonBox;
	connect( buttonBox, SIGNAL(accepted()), this, SLOT(save()) );
	connect( buttonBox, SIGNAL(rejected()), this, SLOT(reject()) );
	connect( ui.runCmdBtn, SIGNAL(clicked()), this, SLOT(editScript()) );
}

void StepScriptDialog::save(){
	m_pMapper->submit();
	close();
}
