#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)    
    , timer(new QTimer(this))
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    getHostName();
    connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::newConnection);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
    this->setWindowTitle("服务端");
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

void MainWindow::newConnection()
{
    qDebug() << "in newConnection";
    //获取对方的IP和端口
    tcpSocket = tcpServer->nextPendingConnection();
    tcpSocketList.append(tcpSocket);
    connect(tcpSocket, &QIODevice::readyRead, this, &MainWindow::readData);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::disconnected);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    sendData(tcpSocket);
    QString itemText = QString(tr("client:[%1:%2]")).arg(tcpSocket->peerAddress().toString()).arg(tcpSocket->peerPort());
    qDebug() << itemText;
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(itemText);
    ui->clientIPList->insertItem(tcpSocketList.count()-1, newItem);
}

void MainWindow::readData()
{
    qDebug() << "in readData";
    in.startTransaction();
    QString rxData;
    in >> rxData;
    if (!in.commitTransaction()){
        qDebug()<<"false == in.commitTransaction()";
        return;
    }
    ui->rxDataTextEdit->appendPlainText(rxData);
}

void MainWindow::on_listenBtn_clicked()
{
    if(ui->listenBtn->text()=="监听"){
        QHostAddress address;
        address.setAddress(ui->hostCombo->currentText());
        quint32 port = ui->portLineEdit->text().toInt();
        if (!tcpServer->listen(address,port)) {
            QMessageBox::critical(this, tr("Server"),
                                  tr("Unable to start the server: %1.")
                                  .arg(tcpServer->errorString()));
            return;
        }

        ui->statusLabel->setText(tr("IP: %1 port: %2")
                                 .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));

        ui->listenBtn->setText("关闭");
    }else{
        ui->listenBtn->setText("监听");
        tcpServer->close();
    }
}

void MainWindow::sendData( QTcpSocket *tcpSocket)
{
    qDebug() << "in sendData";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    //随机取出字符串
//    QString str = fortunes[QRandomGenerator::global()->bounded(fortunes.size())];
    QString str = ui->txDataTextEdit->document()->toPlainText();
    out << str;
    tcpSocket->write(block);
}
void MainWindow::timeout()
{
    qDebug() << "in timeout";
    sendData(tcpSocket);

}

void MainWindow::disconnected()
{
    qDebug() << "in disconnected";
    QTcpSocket * socket = (QTcpSocket*)sender();
    QString itemText = QString(tr("client:[%1:%2]")).arg(socket->peerAddress().toString()).arg(socket->peerPort());
    qDebug() << itemText;
    QList<QListWidgetItem *> items = ui->clientIPList->findItems(itemText,Qt::MatchFlag::MatchContains);
    ui->clientIPList->removeItemWidget(items[0]);
    delete items[0];


}
void MainWindow::on_txDataBtn_clicked()
{
    if(ui->txDataBtn->text() == "发送数据"){
        timer->start(1000);
        ui->txDataBtn->setText("停止发送");
    }else{
        timer->stop();
        ui->txDataBtn->setText("发送数据");
    }
}
