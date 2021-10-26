#include "dataanalyzeform.h"
#include "ui_dataanalyzeform.h"

#include <QPushButton>

DataAnalyzeForm::DataAnalyzeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataAnalyzeForm)
{
    ui->setupUi(this);
}

DataAnalyzeForm::~DataAnalyzeForm()
{
    delete ui;
}
