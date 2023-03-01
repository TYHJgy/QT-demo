#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "MyWidget";
}
//画字-Text
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    //设置画笔
//    painter.setPen(Qt::blue);
//    painter.setFont(QFont("Arial", 30));
//    //写一个"Qt"
//    painter.drawText(rect(), Qt::AlignCenter, "Qt");
//}

//画弧线-Arc
void MyWidget::paintEvent(QPaintEvent *)
{
    QRectF rectangle(10.0, 10.0, 180.0, 80.0);
    int startAngle = 30 * 16;
    int spanAngle = 220 * 16;
    QPainter painter(this);
    painter.drawRect(rectangle);
    painter.drawArc(rectangle, startAngle, spanAngle);
}

//画和弦-Chord
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
//    int startAngle = 30 * 16;
//    int spanAngle = 120 * 16;

//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.drawChord(rectangle, startAngle, spanAngle);
//}


//画椭圆形
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);

//    QPainter painter(this);
//    painter.drawEllipse(rectangle);
//}

//画Image图片
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF target(10.0, 20.0, 80.0, 60.0);
//    QRectF source(0.0, 0.0, 70.0, 40.0);
//    QImage image(":/image/myImage.png");

//    QPainter painter(this);
//    painter.drawImage(target, image, source);
//}

//画线条
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QLineF line(10.0, 80.0, 90.0, 20.0);

//    QPainter painter(this);
//    painter.drawLine(line);
//}

//画路径
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QPainterPath path;
//    path.moveTo(20, 80);
//    path.lineTo(20, 30);
//    path.cubicTo(80, 0, 50, 50, 80, 80);

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
//    painter.drawPath(path);
//}

//画Picture图片
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QPicture picture;
//    picture.load(":/image/myImage.png");

//    QPainter painter(this);
//    painter.drawPicture(0, 0, picture);
//}


//画饼图
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
//    int startAngle = 30 * 16;
//    int spanAngle = 120 * 16;

//    QPainter painter(this);
//    painter.drawPie(rectangle, startAngle, spanAngle);
//}


//画凸多边形
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    static const QPointF points[4] = {
//        QPointF(10.0, 80.0),
//        QPointF(20.0, 10.0),
//        QPointF(80.0, 30.0),
//        QPointF(90.0, 70.0)
//    };

//    QPainter painter(this);
//    painter.drawConvexPolygon(points, 4);
//}


//画多边形
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    static const QPointF points[4] = {
//        QPointF(10.0, 80.0),
//        QPointF(20.0, 10.0),
//        QPointF(80.0, 30.0),
//        QPointF(90.0, 70.0)
//    };

//    QPainter painter(this);
//    painter.setBrush(Qt::cyan);
//    painter.setPen(Qt::darkCyan);
//    painter.drawPolygon(points, 4);
//}


//画多线/折线
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    static const QPointF points[3] = {
//        QPointF(10.0, 80.0),
//        QPointF(20.0, 10.0),
//        QPointF(80.0, 30.0),
//    };

//    QPainter painter(this);
//    painter.drawPolyline(points, 3);
//}

//画矩形
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);

//    QPainter painter(this);
//    painter.drawRect(rectangle);
//}


//画圆角矩形
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 20.0, 80.0, 30.0);

//    QPainter painter(this);
//    painter.drawRoundedRect(rectangle, 20.0, 15.0);
//}

//画圆角矩形(抗锯齿)
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QRectF rectangle(10.0, 10.0, 100.0, 100.0);

//    QPainter painter(this);
//    QPen pen;  // creates a default pen

//    pen.setStyle(Qt::SolidLine);
//    pen.setWidth(5);
//    pen.setBrush(Qt::green);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setJoinStyle(Qt::RoundJoin);

//    painter.setPen(pen);
//    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
//    painter.drawRoundedRect(rectangle, 20.0, 20.0);
//}

//画组合图形(两个正方形)
//void MyWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);

//    painter.setBrush(Qt::cyan);
//    painter.setPen(Qt::darkCyan);
//    painter.drawRect(0, 0, 100,100);

//    painter.setBrush(Qt::NoBrush);
//    painter.setPen(Qt::darkGreen);
//    painter.drawRect(40, 40, 100, 100);
//}





















