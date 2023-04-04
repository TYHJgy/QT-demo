#include "videoform.h"
#include "ui_videoform.h"

VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm)
{
    ui->setupUi(this);

    qDebug() << "摄像机数量：" <<QCameraInfo::availableCameras().count();
    camera = new QCamera(QCamera::FrontFace);
    camera->setViewfinder(ui->widget);
}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::on_start_clicked()
{
    camera->start(); // to start the viewfinder
}

void VideoForm::on_close_clicked()
{
    camera->stop(); // to start the viewfinder
}

void VideoForm::on_stillInamge_clicked()
{
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->searchAndLock();
    imageCapture->capture("C://Users//gy//Desktop");//可以指定保存位置
    camera->unlock();
}



void VideoForm::on_movieStart_clicked()
{
    recorder = new QMediaRecorder(camera);
    camera->setCaptureMode(QCamera::CaptureVideo);
    qDebug() << recorder->isAvailable();//不支持录屏，可试试opencv或是ffmpeg
    QUrl url = QUrl::fromLocalFile("C:\\Users\\gy\\Desktop\\sad.mp4");
    qDebug() << recorder->setOutputLocation(url);
    qDebug() << url;

    recorder->record();

}

void VideoForm::on_movieStop_clicked()
{
    recorder->stop();
}
