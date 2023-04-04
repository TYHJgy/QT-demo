#ifndef RADARDEMO_H
#define RADARDEMO_H

#include <QWidget>
#include <QDebug>
#include <QPainter>  //画家
#include <QConicalGradient>  //锥形渐变,围绕一个中心点逆时针生成渐变颜色
#include <QTimer>  //定时器对象


class RadarDemo : public QWidget
{
    Q_OBJECT
public:
    explicit RadarDemo(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void processOneThing();

signals:

private:
    int angle;  //角度
    QTimer *myTimer;  //定时器对象

};

#endif // RADARDEMO_H
