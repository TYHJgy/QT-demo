#include "meiliform.h"
#include "ui_meiliform.h"

MeiliForm::MeiliForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeiliForm)
{
    ui->setupUi(this);
    //隐藏右上角最小化、最大化和关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //创建窗口名称


}

MeiliForm::~MeiliForm()
{
    delete ui;
}

void MeiliForm::on_MeiliForm_customContextMenuRequested(const QPoint &pos)
{

}
