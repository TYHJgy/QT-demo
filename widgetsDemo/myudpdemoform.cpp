#include "myudpdemoform.h"
#include "ui_myudpdemoform.h"

#include "udpclientform.h"
#include "udptestform.h"

#include <QApplication>
MyUdpDemoForm::MyUdpDemoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyUdpDemoForm)
{
    ui->setupUi(this);
}

MyUdpDemoForm::~MyUdpDemoForm()
{
    delete ui;
}

void MyUdpDemoForm::on_udpclient_clicked()
{
    UDPClientForm * w = new UDPClientForm();
    //w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("UDPClientForm");
    w->show();
}

void MyUdpDemoForm::on_udpDemo_clicked()
{
    UDPTestForm * w = new UDPTestForm();
    //w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("UDPTestForm");
    w->show();
}
