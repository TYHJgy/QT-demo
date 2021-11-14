#include "rsdemoform.h"
#include "ui_rsdemoform.h"




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
    qDebug() << "串口打开成功:" << serial.portName();
    qDebug() << "波特率:" << serial.baudRate();
    qDebug() << "数据位:" << serial.dataBits();;
    qDebug() << "停止位:" << serial.stopBits();;
    qDebug() << "奇偶校验位:" << serial.parity();;
}

//发送数据
void RSDemoForm::on_sendData_clicked()
{
    //发送数据
    QString currentRequest = "hello rs232";
    const QByteArray requestData = currentRequest.toUtf8();
    serial.write(requestData);

    int m_waitTimeout = 1000;//1s
    int currentWaitTimeout = 1000;//1s
    //这个函数会阻塞，直到至少一个字节被写入串口
    if (serial.waitForBytesWritten(m_waitTimeout)) {
        //这个函数会阻塞，直到有新的数据可以读取
        if (serial.waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = serial.readAll();
            while (serial.waitForReadyRead(10))
                responseData += serial.readAll();

            const QString response = QString::fromUtf8(responseData);
            qDebug() << response;
        } else {
            qDebug() << "waitForReadyRead";
        }
    } else {
        qDebug() << "waitForBytesWritten";
    }

    qDebug() << "jieshu";
}
