#ifndef ZOOMSLIDER_H
#define ZOOMSLIDER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class ZoomSlider
        : public QSlider
{
    Q_OBJECT

public:
    ZoomSlider(QWidget * parent = 0);

private slots:
    void setToolTip(int value);
    void increaseValue();
    void decreaseValue();
    void returnToOriginalValue();
};

#endif // ZOOMSLIDER_H
