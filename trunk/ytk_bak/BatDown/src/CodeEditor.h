#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QTextEdit>

class CodeEditor : public QTextEdit
{
	Q_OBJECT

public:
	CodeEditor(QWidget *parent = 0);
	~CodeEditor();

	void setCode(const QString &name, const QString &code);
	QString getCode();

	void setName(const QString &name);
	QString getName();

private slots:
	void highlightCurrentLine();
private:
	QString name;
};

#endif // CODEEDITOR_H
