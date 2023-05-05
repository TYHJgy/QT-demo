#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QtNetwork>
#include "Windows.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getHostName();
    void connectServer();    
    void sendData();
    bool systemShutDown();
private slots:
    void on_connectBtn_clicked();
    void readData();
    void on_sendData_clicked();
    void timeout();
    void connected();

private:
    Ui::MainWindow *ui;
    QDataStream in;
    QTcpSocket *tcpSocket = nullptr;
    QString currentData;
    QTimer *timer;
};
#endif // MAINWINDOW_H
