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
    QString ip = tcpSocket->peerAddress().toString();
    qint16 port = tcpSocket->peerPort();
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    sendData(tcpSocket);
    QString temp = QString(tr("client:[%1:%2]")).arg(ip).arg(port);
    qDebug() << temp;
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
    tcpServer->close();
    QHostAddress address;
    address.setAddress(ui->hostCombo->currentText());
    quint32 port = ui->portLineEdit->text().toInt();
    if (!tcpServer->listen(address,port)) {
        QMessageBox::critical(this, tr("Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        return;
    }

    fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You've got to think about tomorrow.")
             << tr("You will be surprised by a loud noise.")
             << tr("You will feel hungry again in another hour.")
             << tr("You might have mail.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("hello gy.")
             << tr("Computers are not intelligent. They only think they are.");


    ui->statusLabel->setText(tr("IP: %1 port: %2")
                             .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
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
