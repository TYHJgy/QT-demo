#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wmic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() <<"csUUID:"<< WMIC::csUUID();
}

MainWindow::~MainWindow()
{
    delete ui;
}

