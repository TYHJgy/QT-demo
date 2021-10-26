#include "tcpdemoform.h"
#include "ui_tcpdemoform.h"

TcpDemoForm::TcpDemoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpDemoForm)
{
    ui->setupUi(this);

    widget_client = new Client();
    widget_server = new Server();

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
}

TcpDemoForm::~TcpDemoForm()
{
    delete ui;
    qDebug() << "this is ~TcpDemoForm()";
}


/**
 * @brief 打开客户端
 */
void TcpDemoForm::on_client_clicked()
{
//    widget_client->setWindowModality(Qt::ApplicationModal);
    widget_client->show();
}


/**
 * @brief 打开服务器
 */
void TcpDemoForm::on_server_clicked()
{
//    widget->setWindowModality(Qt::ApplicationModal);
    widget_server->show();
}
