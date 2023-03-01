#include "sinwidget.h"

SinWidget::SinWidget(QWidget *parent) :
    QWidget(parent)
{
    m_period = 50;  //周期
    m_grain = 1;    //粒度
    m_radius = 50; // 振幅
}

void SinWidget::Adjust(int period, int grain, int radius)
{
    m_period = period;
    m_grain = grain;
    m_radius = radius;
    update(); // 更新重绘
}

QPoint SinWidget::origin()
{
    QRect r = this->rect();
    return r.center();
}
// 将GUI窗口的点(x,y)转换成数学坐标系统里的点
QPoint SinWidget::toCoord(QPoint p)
{
    // 圆心
    QPoint o = this->origin();
    QPoint result =  p - o;
    result.setY(0 - result.y()); // y坐标反转
    return result;
}
// 将数学坐标系内的(x,y)转成GUI的坐标
QPoint SinWidget::fromCoord(QPoint p)
{
    // 圆心
    QPoint o = this->origin();
    p.setY(0 - p.y()); // y坐标反转
    return p + o;

}

void SinWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int width = this->width();
    int height = this->height();
    QRect rect(0,0, width, height);

    // 设置背景为黑色
    painter.setBrush(QBrush(QColor(0x00,0x00, 0x00)));
    painter.drawRect(rect);

    painter.setPen(QPen(QColor(0, 255, 0))); // 设置线条为绿色

    QPoint o = origin();
    painter.drawLine(QPoint(0, o.y()), QPoint(width, o.y())); // x轴
    painter.drawLine(QPoint(o.x(), 0), QPoint(o.x(), height));// y轴


    // 正弦曲线: 从坐标原点，向左、向右伸展
    QPoint p1(0,0);
    for(int x=0; x<width/2; x+=m_grain)
    {
        // y=sin(x)
        double angle = (double) x / m_period * 2 * 3.1415926;
        double y = m_radius * sin(angle);
        QPoint p2(x, y);

        // 右侧
        painter.drawLine(fromCoord(p1), fromCoord(p2));

        // 左侧
        QPoint base(0,0);
        painter.drawLine(fromCoord(base-p1), fromCoord(base-p2));

        p1 = p2;
    }
}
