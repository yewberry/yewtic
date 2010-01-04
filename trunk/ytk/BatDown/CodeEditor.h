#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QTextEdit>

class CodeEditor : public QTextEdit
{
	Q_OBJECT

public:
	CodeEditor(QWidget *parent = 0);
	~CodeEditor();

private:
	
};

#endif // CODEEDITOR_H
