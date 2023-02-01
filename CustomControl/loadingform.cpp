#include "loadingform.h"
#include "ui_loadingform.h"

LoadingForm::LoadingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingForm)
{
    ui->setupUi(this);
}

LoadingForm::~LoadingForm()
{
    delete ui;
}

void LoadingForm::on_pushButton_clicked()
{
    WaitDialog * waitDialog = new WaitDialog(this);
    waitDialog->setWindowModality(Qt::ApplicationModal);
    waitDialog->show();
}

void LoadingForm::on_pushButton_2_clicked()
{
    qDebug() << "测试控件背景设置";
}
