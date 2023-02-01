#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::FramelessWindowHint);//去掉系统提供的窗口边框
    setAttribute(Qt::WA_TranslucentBackground);//串口透明化

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutProcess()));
    timer->start(10);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::on_progressBar_valueChanged(int value)
{

}

void ProgressDialog::timeoutProcess()
{
    qDebug() << "value:"<< ui->progressBar->value();
    int temp = ui->progressBar->value()+1;
    qDebug() << "temp:" << temp;
    if(temp>=100){
        temp = 0;
    }
    ui->progressBar->setValue(temp);
}
