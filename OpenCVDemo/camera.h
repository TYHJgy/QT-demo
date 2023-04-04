#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QTimer>
#include <QPixmap>

#include <opencv2/opencv.hpp>
using namespace cv;

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = nullptr);

    void openCamera();      // 打开相机
    void closeCamera();     // 关闭相机

private:
    VideoCapture *cap;     // 相机
    QTimer *capTimer;       // 采集图像定时器
    bool cameraIsOpened = false;        // 相机打开标志位

signals:
    void cameraShowImage(QPixmap);      // 发送图像信号
    void cameraIsOpen(bool);            // 相机打开信号
};

#endif // CAMERA_H

