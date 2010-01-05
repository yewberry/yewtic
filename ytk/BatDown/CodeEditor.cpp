#include "CodeEditor.h"
#include "Highlighter.h"
#include "json.h"

CodeEditor::CodeEditor(QWidget *parent)
: QTextEdit(parent)
{
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);
	this->setFont(font);
	new Highlighter(this->document());

	connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
	highlightCurrentLine();
}

CodeEditor::~CodeEditor()
{

}

QString CodeEditor::getCode()
{
	QTextDocument *doc = this->document();
	int bc = doc->blockCount();
	QString str;
	for(int i=0; i<bc; ++i){
		QTextBlock block = doc->findBlockByNumber(i);
		QString s = block.text();
		str.append(s);
		if(!s.trimmed().isEmpty())
			str.append('\n');
	}

	return str;
}

void CodeEditor::setCode(const QString &name, const QString &code)
{
	this->name = name;
	setPlainText( code );
}

QString CodeEditor::getName()
{
	return name;
}

void CodeEditor::setName(const QString &name)
{
	this->name = name;
}

void CodeEditor::highlightCurrentLine()
{
	QList<QTextEdit::ExtraSelection> extraSelections;

	if (!isReadOnly()) {
		QTextEdit::ExtraSelection selection;

		QColor lineColor = QColor(Qt::yellow).lighter(160);

		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		selection.cursor = textCursor();
		selection.cursor.clearSelection();
		extraSelections.append(selection);
	}

	setExtraSelections(extraSelections);
}