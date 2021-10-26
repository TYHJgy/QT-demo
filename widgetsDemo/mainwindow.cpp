#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysmanageform.h"
#include "dataanalyzeform.h"
#include "codeuiform.h"
#include "themewidget.h"
#include "dialogSerial.h"
#include "mainwindowdemo.h"
//#include "myglwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主窗口");

    widget_tcp_demo = new TcpDemoForm(this);
//    widget_tcp_demo->setWindowTitle("Tcp_Demo");
//    widget_tcp_demo->resize(900, 600);

    widget_tcp_demo->move(0,0);
//    widget_tcp_demo->show();
}

MainWindow::~MainWindow()
{
    qDebug() << "this is ~MainWindow()";
//    qDebug() << this->children();
    delete ui;
    delete widget_tcp_demo;
}

/**
 * @brief 打开系统管理窗口
 */
void MainWindow::on_sysManage_clicked()
{
    SysManageForm * sysManageForm = new SysManageForm();
    // 阻塞sysManageForm之外的窗口
    sysManageForm->setWindowModality(Qt::ApplicationModal);
    sysManageForm->show();
}

/**
 * @brief 打开数据分析窗口
 */
void MainWindow::on_dataAnalyze_clicked()
{
    DataAnalyzeForm * form = new DataAnalyzeForm;
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

/**
 * @brief 打开Dialog窗口
 */
void MainWindow::on_DialogDemo_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->setWindowModality(Qt::ApplicationModal);
    dlg->show();
}

/**
 * @brief 打开MainWindow窗口
 */
void MainWindow::on_MainWindowDemo_clicked()
{
    MainWindowDemo * mwd = new MainWindowDemo(this);
//    mwd->setWindowModality(Qt::ApplicationModal);
    mwd->show();
}
/**
 * @brief 打开代码实现UI
 */
void MainWindow::on_codeUi_clicked()
{
    CodeUiForm * form = new CodeUiForm();
//    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}



/**
 * @brief 打开chart_demo窗口
 */
void MainWindow::on_charDemo_clicked()
{
    ThemeWidget * widget = new ThemeWidget();
    widget->setWindowModality(Qt::ApplicationModal);
    widget->resize(900, 600);
    widget->show();
}

/**
 * @brief   打开串口demo
 */
void MainWindow::on_rs232Demo_clicked()
{
    DialogSerial * widget = new DialogSerial();
    widget->setWindowModality(Qt::ApplicationModal);
    widget->resize(900, 600);
    widget->show();
}

/**
 * @brief tcp demo
 */
void MainWindow::on_tcpDemo_clicked()
{
    widget_tcp_demo->show();
}




/**
 * @brief 3D绘图，openGL demo
 */
void MainWindow::on_openGLDemo_clicked()
{
//    MyGLWidget * w = new MyGLWidget();
//    w->setWindowModality(Qt::ApplicationModal);
//    w->resize(400, 300);
//    w->show();
}
