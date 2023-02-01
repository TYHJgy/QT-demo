#include "customwidgetform.h"
#include "ui_customwidgetform.h"

CustomWidgetForm::CustomWidgetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomWidgetForm)
{
    ui->setupUi(this);
}

CustomWidgetForm::~CustomWidgetForm()
{
    delete ui;
}
