#ifndef UDPCLIENTFORM_H
#define UDPCLIENTFORM_H

#include <QWidget>

#include<QDialog>
#include<QVBoxLayout>
#include<QPushButton>
#include<QTextEdit>
#include<QtNetwork/QUdpSocket>
#include<QMessageBox>
#include<QHostAddress>


namespace Ui {
class UDPClientForm;
}

class UDPClientForm : public QWidget
{
    Q_OBJECT

public:
    explicit UDPClientForm(QWidget *parent = nullptr);
    ~UDPClientForm();

private:
    Ui::UDPClientForm *ui;

private:
    QVBoxLayout *mainLayout;
    QPushButton *CloseButton;
    QTextEdit *textedit;
public slots:
    void dataReceived();
private:
    int port;
    QUdpSocket *udpsocket;
};



#endif // UDPCLIENTFORM_H
