#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setSource(QUrl("qrc:/html/testHTML.html"));
    ui->textBrowser->setSource(QUrl("qrc:/html/testHTML.html"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

