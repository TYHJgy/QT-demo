#include "mybutton.h"

#include  <QPainter>
#include <QDebug>
MyButton::MyButton(QWidget *parent):
    QWidget(parent)
{

}

MyButton::~MyButton()
{

}
void MyButton::paintEvent(QPaintEvent *event)
{
    //界面组件的绘制
    Q_UNUSED(event);
    QPainter   painter(this);
    qDebug() << "width:" << width() <<"width:" << height();

    QRect rect(0,0,width(),height());
    painter.setViewport(rect);//设置Viewport
    painter.setWindow(0,0,120,50); // 设置窗口大小，逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //绘制电池边框
    QPen   pen;//设置画笔
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush  brush;//画刷

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(mColorBack);
    painter.setBrush(brush);
    rect.setRect(1,1,109,48);
    painter.drawRect(rect);//绘制电池边框

    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    rect.setRect(110,15,10,20);
    painter.drawRect(rect); //画电池正极头

    //画电池柱
    if (mPowerLevel>mWarnLevel)
    {  //正常颜色电量柱
      brush.setColor(mColorPower);
      pen.setColor(mColorPower);
    }
    else
    { //电量低电量柱
      brush.setColor(mColorWarning);
      pen.setColor(mColorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if (mPowerLevel>0)
    {
      rect.setRect(5,5,mPowerLevel,40);
      painter.drawRect(rect);//画电池柱
    }
    //绘制电量百分比文字
    QFontMetrics textSize(this->font());
    QString powStr=QString::asprintf("%d%%",mPowerLevel);
    QRect textRect=textSize.boundingRect(powStr);//得到字符串的rect
    painter.setFont(this->font());
    pen.setColor(mColorBorder);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2,23+textRect.height()/2,  powStr);
}

void MyButton::setPowerLevel(int pow)
{ //设置当前电量值
   mPowerLevel=pow;
   emit powerLevelChanged(pow); //发射信号
   repaint();
}

int MyButton::powerLevel()
{ //返回当前电量值
   return mPowerLevel;
}

void MyButton::setWarnLevel(int warn)
{//设置电量低阈值
   mWarnLevel=warn;
   repaint();
}

int MyButton::warnLevel()
{//返回电量低阈值
   return  mWarnLevel;
}
//QSize MyButton::sizeHint()
//{//缺省大小,调整比例
//   int H=this->height();
//   int W=H*12/5;
//   QSize   size(W,H);
//   return size;
//}
