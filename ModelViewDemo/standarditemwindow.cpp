#include "standarditemwindow.h"
#include "ui_standarditemwindow.h"

StandardItemWindow::StandardItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StandardItemWindow)
{
    ui->setupUi(this);
}

StandardItemWindow::~StandardItemWindow()
{
    delete ui;
}
