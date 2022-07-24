#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tcpdemoform.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>

QT_BEGIN_NAMESPACE
// 此处的MainWindow是命名空间Ui下的MainWindow，和当前文件定义的MainWindow不是同一个。
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sysManage_clicked();

    void on_dataAnalyze_clicked();

    void on_codeUi_clicked();

    void on_charDemo_clicked();

    void on_rs232Demo_clicked();

    void on_tcpDemo_clicked();

    void on_DialogDemo_clicked();

    void on_MainWindowDemo_clicked();

    void on_openGLDemo_clicked();

    void on_TableDemo_clicked();

    void on_ExcelDemo_clicked();

    void on_CustomButtonDemo_clicked();

    void on_CustomButtonDemo_2_clicked();

    void on_ExcelDemo_2_clicked();

    void on_rsDemo_clicked();

    void on_fileDemo_clicked();

    void on_mouse_right_event_clicked();

    void on_style_demo_clicked();

    void on_officeDemo_clicked();

    void on_pushButton_clicked();

    void on_multimedia_clicked();

    void on_audioRecorder_clicked();

    void on_videoPlayer_clicked();

    void on_pushButton_3D_clicked();


    void on_udpDemo_clicked();

private:
    Ui::MainWindow *ui;
    TcpDemoForm * widget_tcp_demo;
};
#endif // MAINWINDOW_H
