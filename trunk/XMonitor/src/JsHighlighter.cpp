#include <QtGui>
#include "JsHighlighter.h"

JsHighlighter::JsHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkRed);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bbreak\\b" << "\\bfalse\\b" << "\\bin\\b"
                    << "\\bthis\\b" << "\\bvoid\\b" << "\\bcontinue\\b"
                    << "\\bfor\\b" << "\\bnew\\b" << "\\btrue\\b"
                    << "\\bwhile\\b" << "\\bdelete\\b" << "\\bfunction\\b"
                    << "\\bnull\\b" << "\\btypeof\\b" << "\\bwith\\b"
                    << "\\belse\\b" << "\\bif\\b" << "\\breturn\\b"
                    << "\\bvar\\b" << "\\bcase\\b" << "\\bdebugger\\b"
                    << "\\bexport\\b" << "\\bsuper\\b" << "\\bcatch\\b"
                    << "\\bdefault\\b" << "\\bextends\\b" << "\\bswitch\\b"
                    << "\\bclass\\b" << "\\bdo\\b"<< "\\bfinally\\b"
                    << "\\bthrow\\b" << "\\bconst\\b"<< "\\benum\\b"
                    << "\\bimport\\b" << "\\btry\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    /*
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);
    */

    singleLineCommentFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkGreen);
    quotationFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::black);
    functionFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void JsHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);


    while (startIndex >= 0) {

        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
