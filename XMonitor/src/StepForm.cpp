#include "StepForm.h"
#include <QtGui>
#include "Comm.h"

StepForm::StepForm(QString id, OpType op, QWidget *parent)
	: QDialog(parent), m_id(id), m_opType(op)
{
	ui.setupUi(this);
	drawUi();
	mapping();
}

void StepForm::mapping() {
	m_pModel = new QSqlTableModel(this);
	m_pModel->setTable("step");
	m_pModel->select();

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(ui.id, ID);
	m_pMapper->addMapping(ui.ip, IP);
	m_pMapper->addMapping(ui.name, NAME);
	m_pMapper->addMapping(ui.desc, DESC);
	m_pMapper->addMapping(ui.usr, USR);
	m_pMapper->addMapping(ui.pwd, PWD);
	m_pMapper->addMapping(ui.isActive, ACTIVE);
	m_pMapper->addMapping(ui.itemPos, UI_SCENE_POS);

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

	QDialogButtonBox *buttonBox = ui.buttonBox;

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(save()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	switch (m_opType) {
	case ADD:
		setWindowTitle(tr("Add Server"));
		break;
	case EDIT:
		setWindowTitle(tr("Edit Server"));
		break;
	default:
		setWindowTitle(tr("Server Infomation"));
	}

}

void StepForm::save(){
	m_pMapper->submit();
	this->close();
}

QSqlTableModel* StepForm::model(){
	return m_pModel;
}

QString StepForm::id(){
	return ui.id->text();
}

QString StepForm::ip(){
	return ui.ip->text();
}

QString StepForm::name(){
	return ui.name->text();
}

QPointF StepForm::uiScenePos(){
	QString s = ui.itemPos->text();
	if(s.isEmpty()){
		s = "0.0,0.0";
	}
	QStringList ls = s.split(",");
	return QPoint( ls[0].toFloat(), ls[1].toFloat() );
}

void StepForm::uiScenePos(QPointF pos){
	ui.itemPos->setText( QString("%1,%2").arg(pos.x()).arg(pos.y()) );
	save();
}

bool StepForm::isServerActive(){
	return ui.isActive->isChecked();
}

void StepForm::setServerActive(bool c){
	ui.isActive->setChecked(c);
	save();
}
