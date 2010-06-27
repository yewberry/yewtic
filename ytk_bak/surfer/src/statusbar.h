#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class ZoomSlider;

class StatusBar
        : public QToolBar
{
    Q_OBJECT

public:
    StatusBar(QWidget * parent = 0);
    QSlider * slider();
    QProgressBar * progressBar();

private:
    QLabel * m_label;
    QAction * m_zoomOutAction;
    ZoomSlider * m_slider;
    QAction * m_zoomInAction;
    QAction * m_zoomOriginalAction;
    QProgressBar * m_progressBar;

public slots:
    void showMessage(const QString & message);
};

#endif // STATUSBAR_H
