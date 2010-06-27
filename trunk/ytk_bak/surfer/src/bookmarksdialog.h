#ifndef BOOKMARKSDIALOG_H
#define BOOKMARKSDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksView;
class SettingsManager;

class BookmarksDialog
        : public QDialog
{
    Q_OBJECT

public:
    BookmarksDialog();

protected:
    void resizeEvent(QResizeEvent * event);
    void moveEvent(QMoveEvent * event);

private:
    BookmarksView * m_view;
};

#endif // BOOKMARKSDIALOG_H
