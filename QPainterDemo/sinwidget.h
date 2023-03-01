#ifndef SINWIDGET_H
#define SINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QPoint>
#include <QPaintEvent>

class SinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SinWidget(QWidget *parent = 0);
public:
    void Adjust(int period, int grain, int radius);
    QPoint origin();            // 坐标原点位置
    QPoint toCoord(QPoint p);   // 将GUI窗口的点(x,y)转换成坐标系统里的点
    QPoint fromCoord(QPoint p); // 将坐标系内的(x,y)转成GUI的坐标

signals:

public slots:

private:
    virtual void paintEvent(QPaintEvent *event );
    int m_period, m_grain, m_radius;
};

#endif // SINWIDGET_H
