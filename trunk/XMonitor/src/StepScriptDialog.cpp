#include "StepScriptDialog.h"
#include <QtGui>
#include <QtSql>
#include <QtScript>
#include "Comm.h"

#include "StepForm.h"
#include "StepModel.h"
#include "ServerModel.h"

#include "CodeEditor.h"
#include "JsHighlighter.h"
#include "SSH2Utils.h"

StepScriptDialog::StepScriptDialog(OpType type, QString id, QWidget *parent)
	: QDialog(parent), m_opType(type),m_svrId(id)
{
	ui.setupUi(this);
	drawUi();
	mapping();
	setStepListData();
	createActions();
	createMenus();
}

void StepScriptDialog::mapping() {
	m_pModel = new StepModel(this);

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(m_pCmdEditor, StepModel::CMD);
	m_pMapper->addMapping(m_pCmdResultViewer, StepModel::CMD_RESULT);
	m_pMapper->addMapping(m_pScriptEditor, StepModel::SCRIPT);

	m_pMapper->addMapping(ui.stepId, StepModel::ID);
	m_pMapper->addMapping(ui.svrId, StepModel::SVR_ID);

	if(m_opType == EDIT_STEP){
		QString stepId = m_svrId;
		m_svrId = m_pModel->getSvrId(m_svrId);
		m_pModel->setModelBySvrId(m_svrId);
		setCurStep(stepId);
	} else {
		m_pModel->setModelBySvrId(m_svrId);
	}
}

void StepScriptDialog::drawUi() {
	ui.stepId->hide();
	ui.svrId->hide();

	m_pStepList = new StepListWidget(this);
	m_pStepList->setDragEnabled(true);
	m_pStepList->setDragDropMode(QAbstractItemView::InternalMove);
	ui.mainLayout->insertWidget(0, m_pStepList);
	ui.mainLayout->setStretchFactor(m_pStepList, 1);
	connect( m_pStepList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onStepListClicked(QListWidgetItem*)) );
	connect( m_pStepList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onStepListDoubleClicked(QListWidgetItem*)) );
	connect( m_pStepList, SIGNAL(indexesMoved(const QModelIndexList&)), this, SLOT(onStepOrderChanged()) );

	m_pCmdEditor = new CodeEditor(this);
	m_pCmdEditor->setReadOnly(false);
	ui.CmdLayout->insertWidget(0, m_pCmdEditor);

	m_pCmdResultViewer = new CodeEditor(this);
	m_pCmdResultViewer->setReadOnly(true);
	ui.editorLayout->insertWidget(3, m_pCmdResultViewer);
	ui.editorLayout->setStretchFactor(m_pCmdResultViewer, 1);

	m_pScriptEditor = new CodeEditor(this);
	JsHighlighter *hightlighter = new JsHighlighter(m_pScriptEditor->document());
	ui.editorLayout->insertWidget(5, m_pScriptEditor);
	ui.editorLayout->setStretchFactor(m_pScriptEditor, 5);

	QDialogButtonBox *buttonBox = ui.buttonBox;
	connect( buttonBox, SIGNAL(accepted()), this, SLOT(save()) );
	connect( buttonBox, SIGNAL(rejected()), this, SLOT(reject()) );
	connect( ui.runCmdBtn, SIGNAL(clicked()), this, SLOT(runCmd()) );

	connect( this, SIGNAL(stepOrderChanged()), this, SLOT(onStepOrderChanged()) );

	switch(m_opType){
	case EDIT_STEP :
		m_pStepList->hide();
		setWindowTitle(tr("Edit Step Script"));
		break;
	case EDIT_SVR_STEPS:
		m_pStepList->show();
		setWindowTitle(tr("Browser Steps"));
		break;
	default:
		break;
	}
}

void StepScriptDialog::setStepListData() {
	for (int row = 0; row < m_pModel->rowCount(); ++row) {
		QSqlRecord record = m_pModel->record(row);
		QListWidgetItem *item = new QListWidgetItem(
				record.value(StepModel::NAME).toString(), m_pStepList);
		item->setData(Qt::ToolTipRole, QString(tr("Desc:\n%1")).arg(record.value(StepModel::DESC).toString()));
		item->setData(Qt::UserRole, record.value(StepModel::ID).toString());
	}
}

void StepScriptDialog::createActions(){
	m_pAddStepAct = new QAction(tr("Add &Step"), this);
	m_pAddStepAct->setIcon(QIcon(":/images/add_step.png"));
	m_pAddStepAct->setShortcut(tr("Ctrl+S"));
	connect(m_pAddStepAct, SIGNAL(triggered()), this, SLOT(onAddStep()));

	m_pDelStepAct = new QAction(tr("Delete"), this);
	m_pDelStepAct->setShortcut(Qt::Key_Delete);
	m_pDelStepAct->setIcon(QIcon(":/images/delete.png"));
	connect(m_pDelStepAct, SIGNAL(triggered()), this, SLOT(onDelStep()));
}

void StepScriptDialog::createMenus(){
	m_pStepListCtxMenu = new QMenu(this);
	m_pStepListCtxMenu->addAction(m_pAddStepAct);
	m_pStepListCtxMenu->addAction(m_pDelStepAct);

	m_pStepList->m_pCtxMenu = m_pStepListCtxMenu;
}

/**************************** slots START ************************************/
void StepScriptDialog::save(){
	m_pMapper->submit();
    accept();
}
void StepScriptDialog::runCmd(){
	if(ui.useResultCache->isChecked()){
		runScript();

	} else {
		ServerModel model;
		QSqlRecord rec = model.getRecordById(m_svrId);
		QString _ip = rec.value(ServerModel::IP).toString();
		QString _ur = rec.value(ServerModel::USR).toString();
		QString _pw = rec.value(ServerModel::PWD).toString();
		yDEBUG(QString("SvrId:%1, ip:%2, usr:%3, pwd:%4").arg(m_svrId).arg(_ip).arg(_ur).arg(_pw));

		SSH2Utils ssh2;
		if( ssh2.init() < 0 ){
			yERROR(ssh2.errMsg());
			return;
		}
		int rc = 0;
		std::string ip = _ip.toStdString();
		std::string usr = _ur.toStdString();
		std::string pwd = _pw.toStdString();
		yINFO(QString("Connect to %1@%2").arg(ip.c_str()).arg(usr.c_str()));
		rc = ssh2.connect(ip.c_str(), usr.c_str(), pwd.c_str());

		if(rc < 0){
			yERROR(ssh2.errMsg());
			return;
		}

		if(rc == 0){
			std::string cmdstr = m_pCmdEditor->toPlainText().toStdString();
			yINFO(QString("Execute command: %1").arg(cmdstr.c_str()));
			rc = ssh2.exec(cmdstr.c_str());
			std::string str = ssh2.execResultStr();
			m_pCmdResultViewer->clear();
			m_pCmdResultViewer->setPlainText( QString::fromStdString(str) );
		}
	}
}

void StepScriptDialog::onStepListClicked(QListWidgetItem *item){
	QString stepId = item->data(Qt::UserRole).toString();
	setCurStep(stepId);
}

void StepScriptDialog::setCurStep(QString stepId){
	m_pModel->select();
    for (int row = 0; row < m_pModel->rowCount(); ++row) {
        QSqlRecord record = m_pModel->record(row);
        if (record.value(StepForm::ID).toString() == stepId) {
            m_pMapper->setCurrentIndex(row);
            break;
        }
    }
}

void StepScriptDialog::onStepListDoubleClicked(QListWidgetItem *item){
	QString stepId = item->data(Qt::UserRole).toString();
	StepForm form(stepId, StepForm::EDIT, this);

	if( form.exec() == QDialog::Accepted ){
		item->setText(form.getName());
		item->setData(Qt::ToolTipRole, QString(tr("Desc:\n%1")).arg(form.getDesc()));
	}
}

void StepScriptDialog::onAddStep() {
	StepForm form(m_svrId, StepForm::ADD, this);
	if( form.exec() == QDialog::Accepted ){
		QListWidgetItem *item = new QListWidgetItem( form.getName(), m_pStepList);
		item->setData( Qt::ToolTipRole, QString(tr("Desc:\n%1")).arg(form.getDesc()) );
		item->setData( Qt::UserRole, form.id() );
		emit stepOrderChanged();
	}
}

void StepScriptDialog::onDelStep(){
	QList<QListWidgetItem*> items = m_pStepList->selectedItems();
	if (items.length() > 0) {
		QListWidgetItem *item = items.at(0);
		if (QMessageBox::question(this, tr("Confirm?"),
				tr("Confirm to delete \"%1\"?").arg(item->text()),
				QMessageBox::Yes | QMessageBox::Cancel) == QMessageBox::Yes) {

			//StepForm form(item->data(Qt::UserRole).toString(), StepForm::INQ);
			//form.delCurStep();
			QString stepId = item->data(Qt::UserRole).toString();
			QString stepNm = item->text();
			yDEBUG(QString("Delete... Step: %1(%2)").arg(stepNm).arg(stepId));
			StepModel model;
			model.deleteRecordById(stepId);
			int row = m_pStepList->row(item);
			m_pStepList->takeItem(row);
			emit stepOrderChanged();
		}
	}
}

void StepScriptDialog::onStepOrderChanged(){
	int count = m_pStepList->count();
	QHash<QString, int> hm;
	for(int i=0; i<count; ++i){
		QString _id = m_pStepList->item(i)->data(Qt::UserRole).toString();
		hm[_id] = i+1;
	}

	StepModel model;
	QVector<QSqlRecord> recs = model.getRecords();
	for(int i=0; i<recs.count(); ++i){
		QSqlRecord rec = recs.at(i);
		QString stepId = rec.value(StepModel::ID).toString();
		int seq = hm[stepId];
		rec.setValue(StepModel::SEQ, seq);
		//yDEBUG(QString("ROW %1, %2:%3").arg(i).arg(stepId).arg(rec.value(StepModel::SEQ).toInt()));
		model.setRecord(i, rec);
	}
    model.submitAll();

}
/**************************** slots END ************************************/

void StepScriptDialog::runScript() {
	QString result = m_pCmdResultViewer->toPlainText();
	QString script = m_pScriptEditor->toPlainText();
	QScriptEngine engine;

	engine.globalObject().setProperty("xIn", result);
    QScriptValue xLog = engine.newQObject(ui.scriptOutput);
	engine.globalObject().setProperty("xLog", xLog);

	QScriptValue res = engine.evaluate(script);
	if (engine.hasUncaughtException()) {
		yERROR(engine.uncaughtException().toString());
		yERROR(engine.uncaughtExceptionBacktrace().join("\n"));
	} else {
		ui.scriptOutput->appendPlainText( "[RESULT] "+res.toString() );
	}
}

void StepScriptDialog::cmd(QString s){
	m_pCmdEditor->setPlainText(s);
}

void StepScriptDialog::cmdResult(QString s){
	m_pCmdResultViewer->setPlainText(s);
}

void StepScriptDialog::script(QString s){
	m_pScriptEditor->setPlainText(s);
}

void StepScriptDialog::svrId(QString s){
	ui.svrId->setText(s);
}

QString StepScriptDialog::getCmd(){
	return m_pCmdEditor->toPlainText();
}

QString StepScriptDialog::getCmdResult(){
	return m_pCmdResultViewer->toPlainText();
}

QString StepScriptDialog::getScript(){
	return m_pScriptEditor->toPlainText();
}

QString StepScriptDialog::getSvrId(){
	return ui.svrId->text();
}
