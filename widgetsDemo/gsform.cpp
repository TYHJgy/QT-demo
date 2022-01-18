#include "gsform.h"
#include "ui_gsform.h"
#include <QDebug>


GsForm::GsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GsForm)
{
    ui->setupUi(this);
}

GsForm::~GsForm()
{
    delete ui;
}

void GsForm::on_pushButton_clicked()
{
    float fgs = 0;
    float gs = ui->doubleSpinBox->value();
    qDebug() << gs;
    if(gs <= 36000){
        fgs = gs * 0.03;
    }else if(gs <= 144000){
        fgs = gs * 0.1 - 2520;
    }else if(gs <= 300000){
        fgs = gs * 0.2 - 16920;
    }else if(gs <= 420000){
        fgs = gs * 0.25 - 31920;
    }else if(gs <= 660000){
        fgs = gs * 0.3 - 52920;
    }else if(gs <= 960000){
        fgs = gs * 0.35 - 85920;
    }else{
        fgs = gs * 0.45 - 181920;
    }
    qDebug() << fgs;
    ui->doubleSpinBox_2->setValue(fgs);
    ui->doubleSpinBox_3->setValue(gs - fgs);
    ui->doubleSpinBox_4->setValue(fgs/gs);
}
