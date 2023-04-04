//#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "主线程：" << QThread::currentThreadId();

    // 相机子线程
    this->camera = new Camera;
    this->cameraThread = new QThread;
    this->camera->moveToThread(this->cameraThread);
    connect(this->cameraThread, &QThread::finished, this->cameraThread, &QThread::deleteLater);
    connect(this->cameraThread, &QThread::finished, this->camera, &Camera::deleteLater);
    connect(this->camera, &Camera::cameraShowImage, ui->cameraWidget, &CameraWidget::setImage);		// 更新图像
    this->cameraThread->start();

    connect(ui->openCamera, &QPushButton::clicked, this->camera, &Camera::openCamera);      // 打开相机
    connect(ui->closeCamera, &QPushButton::clicked, this->camera, &Camera::closeCamera);    // 关闭相机

    connect(this->camera, &Camera::cameraIsOpen, ui->cameraWidget, &CameraWidget::showImage);
}

MainWindow::~MainWindow()
{
    if(this->cameraThread->isRunning()){
        this->cameraThread->quit();
        this->cameraThread->wait();
    }
    delete ui;
}





void MainWindow::on_captureImage_clicked()
{

}
