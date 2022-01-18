#include "rsdemoform.h"
#include "ui_rsdemoform.h"

#include <QObject>


RSDemoForm::RSDemoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSDemoForm)
{
    ui->setupUi(this);
    scanPortNum();

}

RSDemoForm::~RSDemoForm()
{
    delete ui;
}

void RSDemoForm::on_pushButton_clicked()
{

}
//扫描端口号
void RSDemoForm::scanPortNum(){
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        ui->portComboBox->addItem(info.portName());
        qDebug() << info.portName();
        qDebug() << info.serialNumber();
        qDebug() << info.systemLocation();
        qDebug() << info.isNull();
        qDebug() << info.manufacturer();
    }

}
//打开端口
void RSDemoForm::on_openSerial_stateChanged(int arg1)
{
    qDebug() << arg1;
    //设置端口号
    serial.setPortName(ui->portComboBox->currentText());
    //设置波特率
    serial.setBaudRate(QSerialPort::Baud9600);
    //设置数据位
//    serial.setDataBits(QSerialPort::Data8);
    //设置奇偶校验位
//    serial.setParity(QSerialPort::NoParity);
    //设置停止位
//    serial.setStopBits(QSerialPort::OneStop);
    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << "串口打开错误";
        return;
    }

    QObject::connect(&serial, &QSerialPort::readyRead,this, &RSDemoForm::receiveData);

    qDebug() << "串口打开成功:" << serial.portName();
    qDebug() << "波特率:" << serial.baudRate();
    qDebug() << "数据位:" << serial.dataBits();
    qDebug() << "停止位:" << serial.stopBits();
    qDebug() << "奇偶校验位:" << serial.parity();
}

//发送数据
void RSDemoForm::on_sendData_clicked()
{
    qint16 num = 0x55AA;
    qDebug() << num;
    qDebug() << "16进制大写输出" << QString("%1").arg(num,8,16,QLatin1Char('0')).toUpper();//不足8位补0
    //发送数据
    QString currentRequest = ui->textEdit->toPlainText();

    qDebug() << "发送:" << currentRequest;
    const QByteArray requestData = currentRequest.toUtf8();
    serial.write(requestData);

    int m_waitTimeout = 1000;//1s
    int currentWaitTimeout = 1000;//1s
    //这个函数会阻塞，直到至少一个字节被写入串口
    if (serial.waitForBytesWritten(m_waitTimeout)) {
        //这个函数会阻塞，直到有新的数据可以读取
        if (serial.waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = serial.readAll();
            qDebug()<< "size:"  <<responseData.size();
            while (serial.waitForReadyRead(10)){
                responseData += serial.readAll();
                qDebug()<< "size:"  <<responseData.size();
            }
            const QString response = QString::fromUtf8(responseData);
            qDebug()<< "接收:"  << response;
            ui->textEdit_2->setPlainText(response);
        } else {
            qDebug() << "waitForReadyRead";
        }
    } else {
        qDebug() << "waitForBytesWritten";
    }
}

void RSDemoForm::receiveData()
{
    qDebug() << "receiveData";
    if (serial.waitForReadyRead(100)) {
        QByteArray responseData = serial.readAll();
        qDebug()<< "size:"  <<responseData.size();
        while (serial.waitForReadyRead(100)){
            responseData += serial.readAll();
            qDebug()<< "size2:"  <<responseData.size();
        }
        const QString response = QString::fromUtf8(responseData);
        qDebug()<< "接收:"  << response;
        ui->textEdit_2->setPlainText(response);
    } else {
        qDebug() << "waitForReadyRead";
    }
}
