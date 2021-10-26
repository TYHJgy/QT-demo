#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tcpdemoform.h"


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

private:
    Ui::MainWindow *ui;
    TcpDemoForm * widget_tcp_demo;
};
#endif // MAINWINDOW_H
