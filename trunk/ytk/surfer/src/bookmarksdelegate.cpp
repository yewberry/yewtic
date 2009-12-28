#include "bookmarksdelegate.h"

BookmarksDelegate::BookmarksDelegate(QObject * parent)
        : QStyledItemDelegate(parent)
{
}

void BookmarksDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
    QString text = index.data(Qt::DisplayRole).toString();
    QLineEdit * lineEdit = qobject_cast<QLineEdit *>(editor);
    if(lineEdit)
    {
        lineEdit->setText(text);
        lineEdit->selectAll();
    }
}

void BookmarksDelegate::setModelData(QWidget * editor, QAbstractItemModel * model,
                                     const QModelIndex & index) const
{
    QLineEdit * lineEdit = qobject_cast<QLineEdit *>(editor);
    if(lineEdit)
    {
        model->setData(index, lineEdit->text(), Qt::DisplayRole);
    }
}

void BookmarksDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option,
                                             const QModelIndex & /*index*/) const
{
    editor->setGeometry(option.rect);
}
