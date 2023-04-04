#include "radardemo.h"

RadarDemo::RadarDemo(QWidget *parent) : QWidget(parent)
{
    angle = 0;
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(processOneThing()));
    myTimer->start(100);

}

void RadarDemo::paintEvent(QPaintEvent *event)
{
    qDebug() << "event:" << event;
    QPainter p(this);
    int w = this->width();
    int h = this->height();

    QRect rect(0,0,w,h);
    QRect rect0(w/4,h/4,w*2/4,h*2/4);

    //画笔
    QPen pen;
    pen.setWidth(2);                //画笔宽度
    pen.setColor(Qt::green);        //画笔颜色
    pen.setStyle(Qt::DashDotLine);  //点划线
    p.setPen(pen);

    //锥形画刷
    QConicalGradient coniGrad(w/2,h/2,360-angle);  //起始角度
    coniGrad.setColorAt(0,QColor(0,200,0,200));  //rgba，起始颜色
    coniGrad.setColorAt(0.1,QColor(0,0,0,200));  //结束颜色
    coniGrad.setSpread(QGradient::ReflectSpread);  //渐变填充外部区域
    p.setBrush(coniGrad);  //设置为画刷

    p.drawEllipse(rect);    //外圆
    p.drawEllipse(rect0);   //内圆
    p.drawLine(0,h/2,w,h/2);  //横线
    p.drawLine(w/2,0,w/2,h);  //竖线
}

void RadarDemo::processOneThing()
{
    qDebug() << "in processOneThing:";
    angle+=2;
    if(angle>360)
        angle = 0;
    update();
}
