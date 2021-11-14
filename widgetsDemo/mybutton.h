#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QColor>

class MyButton : public QWidget
{
public:
    MyButton(QWidget *parent = 0);
    ~MyButton();

Q_OBJECT
private:
   QColor  mColorBack=Qt::white;    //背景颜色
   QColor  mColorBorder=Qt::black;  //电池边框颜色
   QColor  mColorPower=Qt::green;   //电量柱颜色
   QColor  mColorWarning=Qt::red;   //电量短缺时的颜色
   int  mPowerLevel=10;             //电量0-100
   int  mWarnLevel=20;              //电量低警示阈值

protected:
   void   paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public:
   void   setPowerLevel(int pow);   //设置当前电量
   int    powerLevel();
   void   setWarnLevel(int warn);   //设置电量低阈值
   int    warnLevel();
//   QSize   sizeHint();              //缺省大小
signals:
   void   powerLevelChanged(int );
public slots:
};

#endif // MYBUTTON_H
