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
	ScriptDialog(const QString &filename = QString(), QWidget *parent = 0);

	~ScriptDialog();
	void setScript(const QString &filename);
	QStringList& getStepSeq();
	QMap<QString, QString>& getSteps();
	QString& getStepFuncs();

public slots:
	void saveScript();
	void applyScript();

private slots:
	void onStepChanged(const QString &text);
	void onSeqChanged();

private:
	void saveDirty();
	void saveJson();

private:
	QLineEdit *m_pSeqEdit;
	QComboBox *m_pStepsEdit;
	CodeEditor *m_pEditor;

	QString m_fn;
	QString m_id;
	QString m_title;
	QString m_url;
	QStringList	m_stepSeq;
	QMap<QString, QString> m_steps;
	QString m_stepFuncs;
	
};

#endif // SCRIPTDIALOG_H
