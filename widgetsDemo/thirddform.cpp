#include "thirddform.h"
#include "ui_thirddform.h"

ThirdDForm::ThirdDForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThirdDForm)
{
    ui->setupUi(this);
}

ThirdDForm::~ThirdDForm()
{
    delete ui;
}

void ThirdDForm::on_pushButton_clicked()
{

}
