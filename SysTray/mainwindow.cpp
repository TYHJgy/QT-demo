#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowState(Qt::WindowMinimized);
//    this->setWindowState(Qt::
//    this->setWindowFlag(Qt::Tool);//隐藏任务栏图标
    sw = new SysTray(this);
    sw->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "in closeEvent";
//    event->accept();
    this->hide();
    this->close();
}
