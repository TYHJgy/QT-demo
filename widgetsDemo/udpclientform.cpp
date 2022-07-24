#include "udpclientform.h"
#include "ui_udpclientform.h"

UDPClientForm::UDPClientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UDPClientForm)
{
    ui->setupUi(this);
    CloseButton=new QPushButton(this);
    CloseButton->setText(tr("close"));
    textedit=new QTextEdit(this);
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(textedit);
    mainLayout->addWidget(CloseButton);
    this->setWindowTitle(tr("udp clicent"));
    port=5555;//设置udp端口。在此上监听数据
    udpsocket=new QUdpSocket(this);
    connect(CloseButton,&QPushButton::clicked,this,&UDPClientForm::close);
    connect(udpsocket,&QUdpSocket::readyRead,this,&UDPClientForm::dataReceived);
    //当有数据被读取时，发送信号
    bool result=udpsocket->bind(port);//确定是否绑定到指定的端口上
    if(!result)
    {
        QMessageBox::information(this,tr("error"),tr("udp socket creat error"));
        return;
    }
}

UDPClientForm::~UDPClientForm()
{
    delete ui;
}


void UDPClientForm::dataReceived()
{
    while(udpsocket->hasPendingDatagrams())//判断udpsocket中是否有数据报可读，在至少有一个数据报可读时返回true，否则返回false
    {
        QByteArray datagram;
        datagram.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        textedit->insertPlainText(msg);
    }
}
