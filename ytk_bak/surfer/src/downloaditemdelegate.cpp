#include "downloaditemdelegate.h"

DownloadItemDelegate::DownloadItemDelegate(QObject * parent)
        : QStyledItemDelegate(parent)
{
}

void DownloadItemDelegate::paint(QPainter * /*painter*/, const QStyleOptionViewItem & /*option*/,
                                 const QModelIndex & /*index*/) const
{
}

QSize DownloadItemDelegate::sizeHint(const QStyleOptionViewItem & option,
                                     const QModelIndex & index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    size.rheight() *= 5.5;
    return size;
}
