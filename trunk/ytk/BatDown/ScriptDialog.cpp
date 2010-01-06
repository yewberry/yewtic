#include "ScriptDialog.h"
#include <QtGui>
#include "BatDownUtils.h"
#include "CodeEditor.h"
#include "json.h"

ScriptDialog::ScriptDialog(const QString &fn, QWidget *parent)
: QDialog(parent)
{
	m_fn = fn;
	QPushButton *okButton = new QPushButton(tr("OK"));
	QPushButton *applyButton = new QPushButton(tr("Apply"));
	QPushButton *cancelButton = new QPushButton(tr("Cancel"));
	cancelButton->setDefault(true);
	connect(okButton, SIGNAL(clicked()), this, SLOT(saveScript()));
	connect(applyButton, SIGNAL(clicked()), this, SLOT(applyScript()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(okButton);
	buttonsLayout->addWidget(applyButton);
	buttonsLayout->addWidget(cancelButton);

	m_pSeqEdit = new QLineEdit;
	m_pStepsEdit = new QComboBox;
	connect( m_pSeqEdit, SIGNAL(editingFinished()),
		this, SLOT(onSeqChanged()) );
	connect( m_pStepsEdit, SIGNAL(currentIndexChanged(const QString &)),
		this, SLOT(onStepChanged(const QString &)) );

	QHBoxLayout *hbLayout = new QHBoxLayout;
	hbLayout->addWidget(m_pSeqEdit);
	hbLayout->addWidget(m_pStepsEdit);

	m_pEditor = new CodeEditor;
	m_pEditor->setTabStopWidth(40);
	m_pCondEditor = new CodeEditor;
	m_pCondEditor->setTabStopWidth(40);
	QHBoxLayout *editorLayout = new QHBoxLayout;
	editorLayout->addWidget(m_pEditor, 2);
	editorLayout->addWidget(m_pCondEditor, 1);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(hbLayout);
	mainLayout->addLayout(editorLayout, 1);
	mainLayout->addStretch();
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Script Dialog"));
	if(!m_fn.isEmpty()){
		setScript(m_fn);
	}
	resize(1024, 600);
}

ScriptDialog::~ScriptDialog()
{

}

void ScriptDialog::setScript(const QString &filename)
{
	json_t *root = BatDownUtils::readJsonFromFile(filename);
	json_t *idNode = json_find_first_label(root, "id");
	json_t *titleNode = json_find_first_label(root, "title");
	json_t *urlNode = json_find_first_label(root, "url");
	json_t *stepsNode = json_find_first_label(root, "steps");
	json_t *seqNode = json_find_first_label(stepsNode->child, "seq");

	m_id = QString(idNode->child->text);
	m_title = QString::fromLocal8Bit(titleNode->child->text);
	m_url = QString::fromLocal8Bit(urlNode->child->text);

	json_t *item = item=seqNode->child->child;
	m_stepSeq.clear();
	while( item ){
		m_stepSeq.append(item->text);
		item = item->next;
	}

	item = seqNode->next;
	m_steps.clear();
	while( item ){
		json_t *testNode	= item->child->child;
		json_t *scriptNode	= testNode->next;
		char *t = json_unescape(testNode->child->text);
		char *c = json_unescape(scriptNode->child->text);
		m_steps.insert( item->text, QString::fromLocal8Bit(c) );
		m_stepTests.insert( item->text, QString::fromLocal8Bit(t) );
		m_stepFuncs.append( 
			QString::fromLocal8Bit("Yew.%1=function(){%2};")
			.arg(item->text)
			.arg( QString::fromLocal8Bit(item->child->text) )
		);
		item = item->next;
	}

	json_free_value(&root);

	m_pSeqEdit->setText(m_stepSeq.join(","));
	m_pStepsEdit->addItems(m_stepSeq);
	setWindowTitle(m_title);
}

void ScriptDialog::onStepChanged(const QString &text)
{
	saveDirty();
	QString script = m_steps.value(text);
	QString test = m_stepTests.value(text);
	m_pEditor->setCode(text, script);
	m_pCondEditor->setCode(text, test);
}

void ScriptDialog::onSeqChanged()
{
	QString s = m_pSeqEdit->text();
	m_stepSeq = s.split(",");
	m_pStepsEdit->clear();
	m_pStepsEdit->addItems(m_stepSeq);
}

void ScriptDialog::saveScript()
{
	applyScript();
	close();
}

void ScriptDialog::applyScript()
{
	saveDirty();
	saveJson();
}

void ScriptDialog::saveDirty(){
	QString oldName = m_pEditor->getName();
	if(!oldName.isEmpty()){
		QString oldCode = m_pEditor->getCode();
		QString oldTestCode = m_pCondEditor->getCode();
		m_steps.insert( oldName, oldCode );
		m_stepTests.insert( oldName, oldTestCode );
	}
}

void ScriptDialog::saveJson()
{
	json_t *root = json_new_object();
	json_t *t;
	t = json_new_number((const char*)m_id.toLatin1());
	json_insert_pair_into_object(root, "id", t);

	t = json_new_string((const char*)m_title.toLocal8Bit());
	json_insert_pair_into_object(root, "title", t);

	t = json_new_string((const char*)m_url.toLocal8Bit());
	json_insert_pair_into_object(root, "url", t);

	json_t *seqNode = json_new_array();
	for(int i=0, len=m_stepSeq.size(); i<len; ++i){
		QString s = m_stepSeq.at(i);
		json_t *v = json_new_string((const char*)s.toLocal8Bit());
		json_insert_child(seqNode, v);
	}

	json_t *stepsNode = json_new_object();
	json_insert_pair_into_object(stepsNode, "seq", seqNode);
	QMapIterator<QString, QString> iter(m_steps);
	while(iter.hasNext()){
		iter.next();
		if(iter.value().isEmpty())continue;

		QByteArray ba_k = iter.key().toLocal8Bit();
		const char *k = (const char*)ba_k;
		QByteArray ba_v = iter.value().toLocal8Bit();
		char *v = ba_v.data();

		QByteArray ba_t = m_stepTests.value(iter.key()).toLocal8Bit();
		char *t = ba_t.data();
		
		v = json_escape(v);
		t = json_escape(t);
		json_t *vn = json_new_string( v );
		json_t *tn = json_new_string( t );

		json_t *step = json_new_object();
		json_insert_pair_into_object(step, "test", tn);
		json_insert_pair_into_object(step, "script", vn);
		json_insert_pair_into_object(stepsNode, k, step);
	}
	json_insert_pair_into_object(root, "steps", stepsNode);

	BatDownUtils::writeJsonToFile(root, m_fn);
}

QStringList& ScriptDialog::getStepSeq()
{
	return m_stepSeq;
}
QMap<QString, QString>& ScriptDialog::getSteps()
{
	return m_steps;
}
QMap<QString, QString>& ScriptDialog::getStepTests()
{
	return m_stepTests;
}
QString& ScriptDialog::getStepFuncs()
{
	return m_stepFuncs;
}