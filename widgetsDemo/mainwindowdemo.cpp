#include "mainwindowdemo.h"
#include "ui_mainwindowdemo.h"
#include <QDebug>


MainWindowDemo::MainWindowDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowDemo)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);//窗口关闭之后，释放资源
}

MainWindowDemo::~MainWindowDemo()
{
    qDebug() << "this is ~MainWindowDemo()";
    delete ui;
}
