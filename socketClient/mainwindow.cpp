#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tcpSocket(new QTcpSocket(this))
    , timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    getHostName();

    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    connect(tcpSocket, &QIODevice::readyRead, this, &MainWindow::readData);
    connect(tcpSocket, &QAbstractSocket::connected, this, &MainWindow::connected);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
    this->setWindowTitle("客户端");
    SysTray * sysTray = new SysTray(this);
    sysTray->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取主机名
void MainWindow::getHostName()
{
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        ui->hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        ui->hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }
}

//连接服务器主机
void MainWindow::connectServer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostCombo->currentText(),
                             ui->portLineEdit->text().toInt());
    qDebug() << tcpSocket->state();
}


void MainWindow::on_connectBtn_clicked()
{
    if(ui->connectBtn->text() == "连接"){
        connectServer();
    }else{
        tcpSocket->abort();
        ui->connectBtn->setText("连接");
        ui->sendData->setEnabled(false);
        ui->sendData->setText("发送数据");
        timer->stop();
    }
}

void MainWindow::readData()
{
    qDebug()<<"in readData";

    in.startTransaction();

    QString rxData;
    in >> rxData;

    if (!in.commitTransaction()){
        qDebug()<<"false == in.commitTransaction()";
        return;
    }
     qDebug()<<rxData;
     ui->rxDataTextEdit->appendPlainText(rxData);
     if(rxData == "关机"){
        systemShutDown();
     }
}
bool MainWindow::systemShutDown()
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    //获取进程标志
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        return false;
    }
    //获取关机特权的LUID
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    //获取这个进程的关机特权
    AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
    if (GetLastError() != ERROR_SUCCESS) {
        return false;
    }
    // 强制关闭计算机
    if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0)) {
        return false;
    }
    return true;
    /*
        // 强制重启计算机
         if ( !ExitWindowsEx(EWX_REBOOT| EWX_FORCE, 0))
               return false;
         return true;
    */
}
void MainWindow::on_sendData_clicked()
{
    if(ui->sendData->text() == "发送数据"){
        timer->start(1000);
        ui->sendData->setText("停止发送");
    }else{
        timer->stop();
        ui->sendData->setText("发送数据");
    }
}

void MainWindow::timeout()
{
    qDebug() << "in timeout";
    sendData();

}

void MainWindow::connected()
{
    qDebug() << "in connected";
    ui->connectBtn->setText("断开");
    ui->sendData->setEnabled(true);

}
void MainWindow::sendData()
{
    qDebug() << "in sendData";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    //随机取出字符串
    QString str = ui->txDataTextEdit->document()->toPlainText();
    out << str;

    tcpSocket->write(block);
}
