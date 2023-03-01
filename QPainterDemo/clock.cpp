#include "clock.h"

Clock::Clock(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1000);
}

void Clock::paintEvent(QPaintEvent *)
{
    render();
//    renderByImage();
}



//画钟表
void Clock::render()
{
    QPainter painter(this);
    static const QPoint hourHand[3] = {
        QPoint(5, 8),
        QPoint(-5, 8),
        QPoint(0, -30)
    };
    static const QPoint minuteHand[3] = {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -40)
    };
    static const QPoint secondHand[3] = {
        QPoint(1, 8),
        QPoint(-1, 8),
        QPoint(0, -50)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
    painter.translate(width() / 2, height() / 2);//指定偏移量

    int side = qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);//用(sx, sy)缩放坐标系统。

    QTime time = QTime::currentTime();

    //画背景边框
//    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPoint(0,0),80,80);

    //画背景
//    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(0,0),75,75);


    //画时针
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.setBrush(Qt::cyan);
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    //画分针
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.setBrush(Qt::gray);
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    //画秒针
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.setBrush(Qt::gray);
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0){
            painter.setPen(minuteColor);
            painter.drawLine(65, 0, 70, 0);
        }else{
            painter.setPen(hourColor);
            painter.drawLine(65, 0, 72, 0);
            painter.setFont(QFont("Arial", 8));
            painter.drawText(QRect(-6,-62,12,12),Qt::AlignCenter,QString::number(j/5));
        }
        painter.rotate(6.0);
    }
}

void Clock::renderByImage()
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    QImage img("://image/clock.jpeg");
    img = img.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    //按照比例自动居中绘制
    int pixX = rect().center().x() - img.width() / 2;
    int pixY = rect().center().y() - img.height() / 2;
    QPoint point(pixX, pixY);
    painter.drawImage(point, img);
}

void Clock::timeout()
{
    qDebug()<<"timeout";
    this->repaint();
}
