#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_readBtn_clicked()
{
    ui->textEdit->clear();
    QFile file("test.xml");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray line = file.readAll();
    ui->textEdit->append(line);
    file.close();
}

void MainWindow::on_addBtn_clicked()
{

}

void MainWindow::on_createFile_clicked()
{

}

void MainWindow::on_deleteFile_clicked()
{

}

void MainWindow::on_updateElementBtn_clicked()
{

}
