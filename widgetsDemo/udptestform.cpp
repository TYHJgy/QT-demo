#include "udptestform.h"
#include "ui_udptestform.h"
#include <QTextEdit>
#include <QUdpSocket>

UDPTestForm::UDPTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UDPTestForm)
{
    ui->setupUi(this);
    TimerLabel=new QLabel(this);
    TimerLabel->setText(QStringLiteral("发送计次："));
    TextLineEdit=new QLineEdit(this);
    StartButton=new QPushButton(this);
    StartButton->setText(QString("开始"));
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartButton);
    this->setWindowTitle(QStringLiteral("udp server"));
    connect(StartButton,&QPushButton::clicked,this,&UDPTestForm::StartButtonClicked);
    port=5555;//设置udp的端口号参数
    isStarted=false;
    udpsocket=new QUdpSocket(this);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerout()));//定时发送广播信息
}

UDPTestForm::~UDPTestForm()
{
    delete ui;
}

void UDPTestForm::StartButtonClicked()
{
    if(!isStarted)
    {
        StartButton->setText(QStringLiteral("停止"));
        timer->start(1000);//开启定时器
        isStarted=true;
    }
    else {
        StartButton->setText(QStringLiteral("开始"));
        isStarted=false;
        timer->stop();
    }
}

void UDPTestForm::timerout()
{
    QString msg=TextLineEdit->text();//获得我们想发送的文字
    int length=0;
    if(msg==" ")
    {
        return;
    }
    if((length=udpsocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=
      msg.length())
    return;
    //QHostAddress::Broadcast指定向广播地址发送
}


