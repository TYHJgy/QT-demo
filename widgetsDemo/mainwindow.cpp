#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysmanageform.h"
#include "dataanalyzeform.h"
#include "codeuiform.h"
#include "themewidget.h"
#include "dialogSerial.h"
#include "mainwindowdemo.h"
#include "tableform.h"
#include "exceldemoform.h"
#include "mybutton.h"
#include "customtabstyle.h"
#include "ledform.h"
#include "rsdemoform.h"
#include "fileoperationform.h"
#include "tabwidget.h"
#include "mouserightdemoform.h"
#include "styledemoform.h"


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
//    DataAnalyzeForm * form = new DataAnalyzeForm;
    TabWidget * form = new TabWidget();
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

/**
 * @brief 打开对话框Dialog窗口
 */
void MainWindow::on_DialogDemo_clicked()
{
//    QDialog *dlg = new QDialog(this);//基本对话框
//    QColorDialog *dlg = new QColorDialog(this);   //颜色选择对话框
//    QFileDialog *dlg = new QFileDialog(this);     //文件选择对话框
//    QFontDialog *dlg = new QFontDialog(this);     //字体选择对话框
//    QInputDialog *dlg = new QInputDialog(this);   //输入对话框
    QMessageBox *dlg = new QMessageBox(this);     //消息对话框
    dlg->setText("我是消息对话框");
    dlg->setWindowTitle("提示");
//    QProgressDialog *dlg = new QProgressDialog(this);     //进度条对话框
    dlg->setWindowModality(Qt::ApplicationModal);
    dlg->show();
    if (dlg->exec()){
//        qDebug() << dlg->selectedFiles();   //文件选择对话框
//        qDebug() << dlg->selectedFont();    //字体选择对话框
//        qDebug() << dlg->textValue();       //输入对话框
        qDebug() << "";
    }
    //文件选择对话框
//    qDebug() << QFileDialog::getOpenFileName(this,tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    //消息对话框
    QMessageBox::question(this,tr("弹窗标题"),tr("弹窗内容"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok);

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

/**
 * @brief MainWindow::on_TableDemo_clicked
 * 1.table view demo
 * 2.代码创建窗口
 */
void MainWindow::on_TableDemo_clicked()
{
    TableForm * w = new TableForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("表格示例");

    w->show();
}


//操作excel示例
void MainWindow::on_ExcelDemo_clicked()
{
    ExcelDemoForm * w = new ExcelDemoForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("Excel示例");



    w->show();
}

//自定义控件
void MainWindow::on_CustomButtonDemo_clicked()
{
    QWidget * w = new QWidget();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("自定义控件");
    w->resize(400, 300);
    MyButton *mybtn = new MyButton(w);

    w->show();
}


//自定义控件2
void MainWindow::on_CustomButtonDemo_2_clicked()
{
    QWidget * w = new QWidget();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("自定义控件");
    w->resize(900, 700);

    QTabWidget * tabWidget = new QTabWidget(w);
    tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->tabBar()->setStyle(new CustomTabStyle);
    tabWidget->setGeometry(QRect(0, 0, 500, 500));

    QWidget *tab = new QWidget();
    tab = new QWidget();
    tab->setObjectName("789");
    tabWidget->addTab(tab, QString());

    QWidget *tab_2 = new QWidget();
    tab_2 = new QWidget();
    tab_2->setObjectName("123");
    tabWidget->addTab(tab_2, QString());

    w->show();
}

//自定义LEDdemo
void MainWindow::on_ExcelDemo_2_clicked()
{
    LedForm * w = new LedForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("LedForm");

    w->show();
}


void MainWindow::on_rsDemo_clicked()
{
    RSDemoForm * w = new RSDemoForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("RSDemoForm");

    w->show();
}

//文件操作
void MainWindow::on_fileDemo_clicked()
{
    FileOperationForm * w = new FileOperationForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("RSDemoForm");

    w->show();
}

void MainWindow::on_mouse_right_event_clicked()
{
    MouseRightDemoForm * w = new MouseRightDemoForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("MouseRightDemoForm");

    w->show();
}

//样式demo
void MainWindow::on_style_demo_clicked()
{
    StyleDemoForm * w = new StyleDemoForm();
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("StyleDemoForm");
    w->show();
}
