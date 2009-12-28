#ifndef DOWNLOADITEMDELEGATE_H
#define DOWNLOADITEMDELEGATE_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class DownloadItemDelegate
        : public QStyledItemDelegate
{
    Q_OBJECT

public:
    DownloadItemDelegate(QObject * parent = 0);
    void paint(QPainter * painter, const QStyleOptionViewItem & option,
               const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

#endif // DOWNLOADITEMDELEGATE_H
