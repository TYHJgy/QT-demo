#include "audiorecorderform.h"
#include "ui_audiorecorderform.h"

AudioRecorderForm::AudioRecorderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioRecorderForm)
{
    ui->setupUi(this);
}

AudioRecorderForm::~AudioRecorderForm()
{
    delete ui;
}
