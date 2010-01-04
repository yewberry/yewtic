#ifndef SCRIPTDIALOG_H
#define SCRIPTDIALOG_H

#include <QDialog>
#include <QMap>

class QLineEdit;
class QComboBox;
class CodeEditor;

class ScriptDialog : public QDialog
{
	Q_OBJECT

public:
	ScriptDialog(const QString &filename = QString());

	~ScriptDialog();
	void setScript(const QString &filename);

private slots:
	void onStepChanged(const QString &text);

private:
	QLineEdit *m_pSeqEdit;
	QComboBox *m_pStepsEdit;
	CodeEditor *m_pEditor;

	QString m_title;
	QString m_url;
	QStringList	m_stepSeq;
	QMap<QString, QString> m_steps;
	
};

#endif // SCRIPTDIALOG_H
