#include "CodeEditor.h"
#include "Highlighter.h"

CodeEditor::CodeEditor(QWidget *parent)
: QTextEdit(parent)
{
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);
	this->setFont(font);
	new Highlighter(this->document());
}

CodeEditor::~CodeEditor()
{

}
