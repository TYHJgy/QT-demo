#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scanPortNum();
    serial = new QSerialPort();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//扫描端口号
void MainWindow::scanPortNum(){
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        ui->comboBox->addItem(info.portName());
    }

}

void MainWindow::handleResults(const QString &s)
{
    ui->textEdit_2->setPlainText(s);
}
//打开串口
void MainWindow::on_pushButton_clicked()
{

    //设置端口号
    serial->setPortName(ui->comboBox->currentText());

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "串口打开错误";
        return;
    }
//    connect(serial, &QSerialPort::readyRead, this, &MainWindow::testreadyRead2);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::testreadyRead);
    qDebug() << "串口打开成功:" << serial->portName();
    qDebug() << "波特率:" << serial->baudRate();
    qDebug() << "数据位:" << serial->dataBits();
    qDebug() << "停止位:" << serial->stopBits();
    qDebug() << "奇偶校验位:" << serial->parity();
}

void MainWindow::on_pushButton_2_clicked()
{
    //发送数据
    QString currentRequest = ui->textEdit->toPlainText();

    qDebug() << "发:" << currentRequest;
    const QByteArray requestData = currentRequest.toUtf8();
    serial->write(requestData);
    qDebug()<<"bytesToWrite"<<serial->bytesToWrite();
    int m_waitTimeout = 3000;//1s
    int currentWaitTimeout = 1000;//1s
    //这个函数会阻塞，直到至少一个字节被写入串口
    if (serial->waitForBytesWritten(m_waitTimeout)) {
        //这个函数会阻塞，直到有新的数据可以读取
        if (serial->waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = serial->readAll();
            while (serial->waitForReadyRead(50))
                responseData += serial->readAll();

            const QString response = QString::fromUtf8(responseData);
            qDebug()<< "收:"  << response;
            ui->textEdit_2->setPlainText(response);
        } else {
            qDebug() << "false = waitForReadyRead";
            qDebug()<<"bytesToWrite-2"<<serial->bytesToWrite();
            QByteArray responseData = serial->readAll();
            const QString response = QString::fromUtf8(responseData);
            qDebug()<< "收:"  << response;
            qDebug()<< serial->error();
        }
    } else {
        qDebug() << "waitForBytesWritten";
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //发送数据
    QString currentRequest = ui->textEdit->toPlainText();

    qDebug() << "发:" << currentRequest;
    const QByteArray requestData = currentRequest.toUtf8();
    serial->write(requestData);
}

void MainWindow::on_pushButton_4_clicked()
{

    workerThread = new Worker(serial);
    connect(workerThread, &Worker::resultReady, this, &MainWindow::handleResults);
    workerThread->start();
}

void MainWindow::testreadyRead()
{
    qDebug() << "我是:" << "testreadyRead";
    QByteArray responseData;
    QByteArray temp = serial->readAll();
    responseData += temp;
    while (temp.count() != 0){
        temp = serial->readAll();
        responseData += temp;
    }

    qDebug()<< serial->error();
    const QString response = QString::fromUtf8(responseData);
    qDebug()<< "testreadyRead收:"  << response;
    ui->textEdit_2->setPlainText(response);
     qDebug()<< serial->readBufferSize();
}

void MainWindow::testreadyRead2()
{
    qDebug() << "我是:" << "testreadyRead2";
}
