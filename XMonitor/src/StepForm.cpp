#include "StepForm.h"
#include <QtGui>
#include "Comm.h"

#include "StepScriptDialog.h"

StepForm::StepForm(QString id, OpType op, QWidget *parent)
	: QDialog(parent), m_id(id), m_opType(op)
{
	ui.setupUi(this);
	drawUi();
	mapping();
}

void StepForm::mapping() {
	m_pModel = new QSqlRelationalTableModel(this);
	m_pModel->setTable("step");
	m_pModel->setRelation(SVR_ID, QSqlRelation("server", "id", "name"));
	m_pModel->setSort(SEQ, Qt::AscendingOrder);
	m_pModel->select();

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(ui.id, ID);
	m_pMapper->addMapping(ui.svrId, SVR_ID);
	m_pMapper->addMapping(ui.name, NAME);
	m_pMapper->addMapping(ui.cmd, CMD);
	m_pMapper->addMapping(ui.cmdResult, CMD_RESULT);
	m_pMapper->addMapping(ui.script, SCRIPT);
	m_pMapper->addMapping(ui.seq, SEQ);

	if(m_opType == ADD){
        int row = m_pModel->rowCount();
        m_pModel->insertRow(row);
        m_pMapper->setCurrentIndex(row);
        ui.id->setText( QString::fromStdString(Comm::uuid()) );

    } else if( !m_id.isEmpty() ) {
        for (int row = 0; row < m_pModel->rowCount(); ++row) {
            QSqlRecord record = m_pModel->record(row);
            if (record.value(ID).toString() == m_id) {
                m_pMapper->setCurrentIndex(row);
                break;
            }
        }
    } else {
    	m_pMapper->toFirst();
    }
}

void StepForm::drawUi() {
	ui.cmd->hide();
	ui.cmdResult->hide();
	ui.script->hide();

	QDialogButtonBox *buttonBox = ui.buttonBox;
	connect( buttonBox, SIGNAL(accepted()), this, SLOT(save()) );
	connect( buttonBox, SIGNAL(rejected()), this, SLOT(reject()) );
	connect( ui.scriptBtn, SIGNAL(clicked()), this, SLOT(editScript()) );

	switch (m_opType) {
	case ADD:
		setWindowTitle(tr("Add Step"));
		break;
	case EDIT:
		setWindowTitle(tr("Edit Step"));
		break;
	default:
		setWindowTitle(tr("Step Infomation"));
	}

}

void StepForm::save(){
	m_pMapper->submit();
	this->close();
}

void StepForm::editScript(){
	StepScriptDialog dlg( svrId(), id(), this);
	dlg.exec();
}

QSqlTableModel* StepForm::model(){
	return m_pModel;
}

QString StepForm::id(){
	return ui.id->text();
}

QString StepForm::svrId(){
	return ui.svrId->text();
}

void StepForm::svrId(QString sId){
	ui.svrId->setText(sId);
}

QString StepForm::name(){
	return ui.name->text();
}

QString StepForm::desc(){
	return ui.desc->toPlainText();
}
