#ifndef BOOKMARKSDELEGATE_H
#define BOOKMARKSDELEGATE_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksDelegate
        : public QStyledItemDelegate
{
    Q_OBJECT

public:
    BookmarksDelegate(QObject * parent = 0);
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option,
                              const QModelIndex & index) const;
};

#endif // BOOKMARKSDELEGATE_H
