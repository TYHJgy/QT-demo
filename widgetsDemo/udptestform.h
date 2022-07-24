#ifndef UDPTESTFORM_H
#define UDPTESTFORM_H

#include <QWidget>
#include <QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QLabel>
#include<QtNetwork/QUdpSocket>
#include<QTimer>

namespace Ui {
class UDPTestForm;
}

class UDPTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit UDPTestForm(QWidget *parent = nullptr);
    ~UDPTestForm();
    void initServerSokcet();
    void readPendingDatagrams();

private:
    Ui::UDPTestForm *ui;

private:
    QLabel *TimerLabel;
    QPushButton *StartButton;
    QLineEdit *TextLineEdit;
    QVBoxLayout * mainLayout;

public slots:
    void StartButtonClicked();
    void timerout();

private slots:

private:
    int port;//端口号
    bool isStarted;
    QUdpSocket *udpsocket;
    QTimer *timer;
};

#endif // UDPTESTFORM_H
