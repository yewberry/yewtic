#include "ScriptDialog.h"
#include <QtGui>
#include "BatDownUtils.h"
#include "CodeEditor.h"
#include "json.h"

ScriptDialog::ScriptDialog(const QString &filename)
{
	QPushButton *closeButton = new QPushButton(tr("Close"));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(closeButton);

	m_pSeqEdit = new QLineEdit;
	m_pStepsEdit = new QComboBox;
	connect( m_pStepsEdit, SIGNAL(currentIndexChanged(const QString &)),
			this, SLOT( onStepChanged(const QString &)) );

	QHBoxLayout *hbLayout = new QHBoxLayout;
	hbLayout->addWidget(m_pSeqEdit);
	hbLayout->addWidget(m_pStepsEdit);

	m_pEditor = new CodeEditor;
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(hbLayout);
	mainLayout->addWidget(m_pEditor);
	mainLayout->addStretch(1);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

	setWindowTitle(tr("Script Dialog"));
	if(!filename.isEmpty()){
		setScript(filename);
	}
	resize(800, 300);
}

ScriptDialog::~ScriptDialog()
{

}

void ScriptDialog::setScript(const QString &filename)
{
	json_t *root = BatDownUtils::readJsonFromFile(filename);
	json_t *titleNode = json_find_first_label(root, "title");
	json_t *urlNode = json_find_first_label(root, "url");
	json_t *stepsNode = json_find_first_label(root, "steps");
	json_t *seqNode = json_find_first_label(stepsNode->child, "seq");
	
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
		m_steps.insert(item->text, item->child->text);
		item = item->next;
	}

	json_free_value(&root);
	
	m_pSeqEdit->setText(m_stepSeq.join(","));
	m_pStepsEdit->addItems(m_stepSeq);
	setWindowTitle(m_title);
}

void ScriptDialog::onStepChanged(const QString &text)
{
	QString str = m_steps.value(text);
	m_pEditor->setPlainText(str);
}