#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , leftBarMode(0)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//去掉系统提供的窗口边框

    //初始化界面
    initForm();

    //为指定对象安装事件过滤器
    ui->widget->installEventFilter(this);
    ui->widget_2->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
//    for(int i=0;i<100;i++){
//        QPushButton btn;
//        btns.append(btn);
//    }
    btn.i=0;
    btns.append(btn);
    btn.i=1;
    qDebug() <<"btn"<< &btn;
    qDebug() <<"btns[0].i"<< &btns[0];
    TestClass btn2 = btns[0];
    qDebug() <<"btn2"<< &btn2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//关闭窗口事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(true){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag){
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ui->pushButton_3->click();
}

void MainWindow::initForm()
{
    //APP图标
    ui->label->setStyleSheet(appIconPath);

    //左侧按键
    leftBarBtnList << ui->pushButton_2
                   << ui->pushButton_3
                   << ui->pushButton_4
                   << ui->pushButton_5
                   << ui->pushButton_6
                   << ui->pushButton_7;

    foreach(QPushButton*e,leftBarBtnList){
        //设置文字
        e->setText(leftBarBtnName[leftBarBtnList.indexOf(e)]);
        //设置图标
        QIcon icon;
        icon.addFile(leftBarBtnIconPath.at(leftBarBtnList.indexOf(e)));
        e->setIcon(icon);
        //设置图标在左，文字右
        e->setLayoutDirection(Qt::LeftToRight);
    }

    //设置展开控件图标
    QIcon icon;
    leftBarSwitchBtnIconPathCurrent = leftBarSwitchBtnIconPath.at(0);
    icon.addFile(leftBarSwitchBtnIconPathCurrent);
    ui->pushButton->setIcon(icon);

    //设置光标
    ui->lineEdit_5->setFocus();
}


//初始化样式表。从QSS文件读取QSS样式（未使用此方法）
void MainWindow::initStyleSheet()
{
    QFile *styleFile;
    styleFile  = new QFile(":/style/style/style.qss", this); //获取资源文件的对象
    styleFile->open(QFile::ReadOnly);//只读模式
    QString styleSheet = QString(styleFile->readAll());//读出的数据转成字符串
    qApp->setStyleSheet(styleSheet);//qApp 程序的唯一全局指针 设置样式
    styleFile->close();//最后关闭这个文件
}

void MainWindow::maximizeForm()
{
    if(this->isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
//    qDebug() << "obj:" << obj->objectName();
    if(obj == ui->pushButton){

        if(ev->type() == QEvent::HoverEnter){
            qDebug() << "ev:" << ev->type();
            //切换icon
            QIcon icon;
            icon.addFile(QString::fromUtf8(":/icon/icon/exit2.png"), QSize(), QIcon::Normal, QIcon::Off);
            ui->pushButton->setIcon(icon);
        }
        if(ev->type() == QEvent::HoverLeave){
            qDebug() << "ev:" << ev->type();
            //切换icon
            QIcon icon;
            icon.addFile(QString::fromUtf8(":/icon/icon/enter2.png"), QSize(), QIcon::Normal, QIcon::Off);
            ui->pushButton->setIcon(icon);
        }
    }
    if(obj == ui->widget){
        if(ev->type() == QEvent::MouseButtonDblClick){
            qDebug() << "widget ev:" << ev->type();
            maximizeForm();
        }
    }
    if(obj == ui->widget_2){
        if(ev->type() == QEvent::Enter){
            QIcon icon;
            icon.addFile(leftBarSwitchBtnIconPathCurrent);
            ui->pushButton->setIcon(icon);
        }
        if(ev->type() == QEvent::Leave){
            QIcon icon;
            ui->pushButton->setIcon(icon);
        }
    }
    return false;
}


void MainWindow::on_pushButton_clicked()
{
    if(0==leftBarMode){
        leftBarMode = 1;
        foreach(QPushButton*e,leftBarBtnList)
            e->setText("");
    }else{
        leftBarMode = 0;
        foreach(QPushButton*e,leftBarBtnList)
            e->setText(leftBarBtnName[leftBarBtnList.indexOf(e)]);
    }
    //切换图标
    QIcon icon;
    leftBarSwitchBtnIconPathCurrent = leftBarSwitchBtnIconPath.at(leftBarMode);
    icon.addFile(leftBarSwitchBtnIconPathCurrent);
    ui->pushButton->setIcon(icon);
}

void MainWindow::on_pushButton_8_clicked()
{
#if 0
    //消息对话框
    QMessageBox::StandardButton btn = QMessageBox::question(this,tr("提示"),tr("确认退出？"),QMessageBox::Yes | QMessageBox::No);
    if(btn == QMessageBox::Yes)
        this->close();
#else
    //关闭APP
    this->close();
#endif
}

void MainWindow::on_pushButton_9_clicked()
{
    maximizeForm();
}

void MainWindow::on_pushButton_10_clicked()
{
    this->showMinimized();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
