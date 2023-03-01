#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QTime>
#include <QDebug>
#include <QEvent>

class SwitchButton : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *) override;
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    //画开关按钮
    void renderSwitch(QPainter &p,bool state);
    bool switchState;

};

#endif // SWITCHBUTTON_H
