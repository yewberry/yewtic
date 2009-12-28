#ifndef BOOKMARKSFOLDERDIALOG_H
#define BOOKMARKSFOLDERDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksFolderView;

class BookmarksFolderDialog
        : public QDialog
{
    Q_OBJECT

public:
    BookmarksFolderDialog();
    QString title() const;
    void setTitle(const QString & title);
    QModelIndex parentIndex() const;

private:
    QLabel * m_titleLabel;
    QLineEdit * m_titleEdit;
    QLabel * m_folderLabel;
    BookmarksFolderView * m_view;
    QPushButton * m_createFolderButton;
    QPushButton * m_okButton;
    QPushButton * m_cancelButton;
};

#endif // BOOKMARKSFOLDERDIALOG_H
