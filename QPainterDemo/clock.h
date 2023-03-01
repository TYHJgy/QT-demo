#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QEvent>

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);

private:
    QTimer * timer;
    //画钟表
    void render();
    //://image/clock.jpeg
    void renderByImage();

signals:

private slots:
    void timeout();

protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // CLOCK_H
