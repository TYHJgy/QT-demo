#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::FramelessWindowHint);//去掉系统提供的窗口边框
    int test1 = 0;
    int test2 = 1;
    testAdd(test1=0,test2=0);
    testAdd(++test1,++test2);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::testString()
{
    QString str = "123456789";
    qDebug() << "1:"<< str;
    qDebug() << "1:"<< &str;

    QString str1 = str;
    qDebug() << "1:"<< str1;
    qDebug() << "1:"<< &str1;

    return str;
}

void MainWindow::testAdd(const int i1, const int i2)
{
    qDebug() << "i1:"<< i1;
    qDebug() << "i2:"<< i2;
}

void MainWindow::initStyleSheet()
{

    QFile *styleFile;
    styleFile  = new QFile(":/style/style/style.qss", this); //获取资源文件的对象
    styleFile->open(QFile::ReadOnly);//只读模式
    QString styleSheet = QString(styleFile->readAll());//读出的数据转成字符串
    qApp->setStyleSheet(styleSheet);//qApp 程序的唯一全局指针 设置样式
    styleFile->close();//最后关闭这个文件
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->pushButton){
//        qDebug() << "obj:" << obj->objectName();
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
    if(obj == ui->pushButton_2){
        if(ev->type() == QEvent::HoverEnter){
            qDebug() << "ev:" << ev->type();
            //切换icon
            QIcon icon;
            icon.addFile(QString::fromUtf8(":/icon/icon/exit4.png"), QSize(), QIcon::Normal, QIcon::Off);
            ui->pushButton_2->setIcon(icon);
        }
        if(ev->type() == QEvent::HoverLeave){
            qDebug() << "ev:" << ev->type();
            //切换icon
            QIcon icon;
            ui->pushButton_2->setIcon(icon);
            return true;
        }
    }
    return false;
}

