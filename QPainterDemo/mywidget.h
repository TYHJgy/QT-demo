#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QTime>
#include <QDebug>
#include <QEvent>


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;
signals:

private:
    //画钟表
    void render(QPainter *p);

};

#endif // MYWIDGET_H
