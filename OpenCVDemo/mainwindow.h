#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QPushButton>
#include <opencv2/opencv.hpp>

#include "camera.h"
#include "camerawidget.h"

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_captureImage_clicked();

private:
    Ui::MainWindow *ui;
    VideoCapture * cap;
    Camera * camera;
    QThread * cameraThread;
};
#endif // MAINWINDOW_H
