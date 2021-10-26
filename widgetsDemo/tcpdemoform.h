#ifndef TCPDEMOFORM_H
#define TCPDEMOFORM_H

#include <QWidget>

#include "client.h"
#include "server.h"

namespace Ui {
class TcpDemoForm;
}

class TcpDemoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TcpDemoForm(QWidget *parent = nullptr);
    ~TcpDemoForm();

private slots:
    void on_client_clicked();

    void on_server_clicked();

private:
    Ui::TcpDemoForm *ui;
    Client * widget_client;
    Server * widget_server;
};

#endif // TCPDEMOFORM_H
