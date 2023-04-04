#include "camera.h"
#include <QDebug>
#include <QThread>

Camera::Camera(QObject *parent) : QObject(parent)
{

}

void Camera::openCamera()
{
    qDebug() << "子线程：" << QThread::currentThreadId();
    // 打开相机
    int cameraDevId = 0;
    this->cap = new VideoCapture;
    this->cap->open(cameraDevId, cv::CAP_DSHOW);     // 必须带上 CAP_DSHOW ，否则会报错 [ WARN:1] terminating async callback，然后再次打开就打不开了
    if(!this->cap->isOpened()){
        this->cap->release();		// 释放相机
        qDebug() << "相机打开失败！";
        return;
    }
    this->cameraIsOpened = true;
    emit this->cameraIsOpen(true);     // 相机打开

    qDebug() << QString("相机参数: (%1, %2), %3 FPS").arg(cap->get(3)).arg(cap->get(4)).arg(cap->get(5));

    this->capTimer = new QTimer;
    connect(this->capTimer, &QTimer::timeout, [=]() {
//        qDebug() << "子线程：" << QThread::currentThreadId();
        Mat frame;
        // 采集图像
        this->cap->read(frame);
        if(frame.empty()){
            qDebug() << "相机可能断开";
            this->closeCamera();        // 关闭相机
            return ;
        }
        // 将OpenCv的BGR图像转换成正常的RGB图像
        cvtColor(frame, frame, cv::COLOR_BGR2RGB);
        // 将OpenCv的图像转换成Qt的QImage
        QPixmap showImage = QPixmap::fromImage(QImage((const uchar*)(frame.data),
                                                      frame.cols,
                                                      frame.rows,
                                                      frame.step,
                                                      QImage::Format_RGB888));
        // 将QPixmap图像通过信号发送出去
        emit this->cameraShowImage(showImage);
    });
    // 采样时间可以根据相机的FPS修改
    this->capTimer->start(40);
}

void Camera::closeCamera()
{
    qDebug() << "子线程：" << QThread::currentThreadId();
    if(!this->cameraIsOpened) return;

    if(this->capTimer->isActive()){
        this->capTimer->stop();
        this->capTimer->deleteLater();

        this->cameraIsOpened = false;
        emit this->cameraIsOpen(false);     // 相机关闭

        this->cap->release();		// 释放相机
        cv::destroyAllWindows();	// 销毁OpenCv的窗口
    }
}

