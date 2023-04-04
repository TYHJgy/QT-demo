#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QDebug>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QUrl>

namespace Ui {
class VideoForm;
}

class VideoForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoForm(QWidget *parent = nullptr);
    ~VideoForm();

private slots:
    void on_start_clicked();

    void on_close_clicked();

    void on_stillInamge_clicked();

    void on_movieStart_clicked();

    void on_movieStop_clicked();

private:
    Ui::VideoForm *ui;
    QCamera * camera;
    QCameraViewfinder * viewfinder;
    QCameraImageCapture * imageCapture;
    QMediaRecorder * recorder;
};

#endif // VIDEOFORM_H
