#include "worker.h"

Worker::Worker(QSerialPort * serial)
{
//    this->serial = serial;
//    this->serial = new QSerialPort();
//    this->serial->setPortName("COM8");

//    if (!this->serial->open(QIODevice::ReadWrite)) {
//        qDebug() << "0串口打开错误";
//        return;
//    }
}

void Worker::run()
{
    sleep(1);

    QSerialPort * serial;
    serial = new QSerialPort();
    serial->setPortName("COM11");

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "COM9串口打开错误";
        return;
    }

    qDebug() << "COM9串口打开成功";
    //发送数据
        QString currentRequest = "123456";

        qDebug() << "发:" << currentRequest;
        const QByteArray requestData = currentRequest.toUtf8();
        serial->write(requestData);
    while(true){
        sleep(1);
        //这个函数会阻塞，直到有新的数据可以读取
        if (serial->waitForReadyRead(1000)) {
            QByteArray responseData = serial->readAll();
            while (serial->waitForReadyRead(50))
                responseData += serial->readAll();
            const QString response = QString::fromUtf8(responseData);
            qDebug()<< "收:"  << response;
            emit resultReady(response);
        } else {
            qDebug() << "false == waitForReadyRead";
            QByteArray responseData = serial->readAll();
            const QString response = QString::fromUtf8(responseData);
            qDebug()<< "收:"  << response;
            emit resultReady(response);
        }
    }
//    exec();
}
