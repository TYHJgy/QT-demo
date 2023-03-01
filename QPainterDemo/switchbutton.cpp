#include "switchbutton.h"

SwitchButton::SwitchButton(QWidget *parent) : QWidget(parent)
{
    switchState = false;
    this->installEventFilter(this);
}

void SwitchButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    renderSwitch(painter,true);
}

void SwitchButton::renderSwitch(QPainter &p,bool state)
{
    p.setRenderHint(QPainter::Antialiasing,true);//抗锯齿

    if(state){
        //画圆角矩形
        QRectF rectangle(0.0,0.0, 60.0, 30.0);
        p.setBrush(QColor(120, 120, 130, 255));
        p.setPen(QColor(120, 120, 130, 255));
        p.drawRoundedRect(rectangle, 15.0, 15.0);

        //画圆
        QRectF rectangle2(30.0, 0.0, 30.0, 30.0);
        p.setBrush(QColor(230, 230, 230, 255));
        p.drawEllipse(rectangle2);
    }else{
        //画圆角矩形
        QRectF rectangle(0.0,0.0, 60.0, 30.0);
        p.setBrush(QColor(220, 220, 220, 255));
        p.setPen(QColor(220, 220, 220, 255));
        p.drawRoundedRect(rectangle, 15.0, 15.0);
    //    p.fillRect(rectangle,QColor(220, 220, 220, 255));

        //画圆
        QRectF rectangle2(0.0, 0.0, 30.0, 30.0);
        p.setBrush(QColor(246, 246, 246, 255));
        p.drawEllipse(rectangle2);
    }

}

bool SwitchButton::eventFilter(QObject *obj, QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonRelease){
        qDebug() << "obj:"<< obj << "|ev:" << ev->type();
        switchState = !switchState;
        repaint();
    }
    return false;
}
