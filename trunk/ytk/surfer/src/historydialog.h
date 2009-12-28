#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryView;
class HistoryManager;
class HistoryFilterModel;
class SettingsManager;

class HistoryDialog
        : public QDialog
{
    Q_OBJECT

public:
    HistoryDialog();

protected:
    void resizeEvent(QResizeEvent * event);
    void moveEvent(QMoveEvent * event);

private:
    HistoryView * m_view;
    QLineEdit * m_lineEdit;
    QPushButton * m_clearButton;

private slots:
    void clear();
};

#endif // HISTORYDIALOG_H
