#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new MyClass(this);
    new TestClass(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "~MainWindow";
}

