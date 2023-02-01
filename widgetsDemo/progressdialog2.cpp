#include "progressdialog2.h"

ProgressDialog2::ProgressDialog2(QWidget *parent) : QWidget(parent)
{
    resize(260, 129);
    setStyleSheet(QString::fromUtf8("QWidget{\n"
    "border-radius: 25px;\n"
    "\n"
    "background-color: rgb(120, 150, 210)\n"
    "}\n"
    "\n"
    "QProgressBar{\n"
    "	background:white;\n"
    "	border-radius: 6px;\n"
    "	border: 3px solid;\n"
    "	\n"
    "	border-color: rgb(255, 255, 255);\n"
    "}\n"
    "\n"
    "QProgressBar::chunk{\n"
    "	\n"
    "	background-color: rgb(98, 255, 190);\n"
    "	border-radius: 6px;\n"
    "}"));

    verticalLayout_2 = new QVBoxLayout(this);

    widget = new QWidget(this);
    verticalLayout = new QVBoxLayout(widget);

    progressBar = new QProgressBar(widget);
    progressBar->setValue(50);
    progressBar->setTextVisible(false);


    verticalLayout->addWidget(progressBar);
    verticalLayout_2->addWidget(widget);

//    QMetaObject::connectSlotsByName(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutProcess()));
    timer->start(10);

}

ProgressDialog2::~ProgressDialog2()
{

}

void ProgressDialog2::timeoutProcess()
{
    qDebug() << "value:"<< progressBar->value();
    int temp = progressBar->value()+1;
    qDebug() << "temp:" << temp;
    if(temp>=100){
        temp = 0;
    }
    progressBar->setValue(temp);
}

