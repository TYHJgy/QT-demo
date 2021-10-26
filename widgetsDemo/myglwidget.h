#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QGLWidget *parent = nullptr);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

signals:

};

#endif // MYGLWIDGET_H
