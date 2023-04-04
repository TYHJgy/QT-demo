#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtNetwork>
#include <QTcpSocket>

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
    void sendData(QTcpSocket *tcpSocket);

private slots:
    void on_listenBtn_clicked();
    void newConnection();
    void readData();
    void on_txDataBtn_clicked();
    void timeout();

private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer = nullptr;
    QList<QTcpSocket*> tcpSocketList;
    QDataStream in;
    QTcpSocket * tcpSocket = nullptr;;
    QNetworkSession *networkSession = nullptr;
    QVector<QString> fortunes;
    QTimer * timer;
};
#endif // MAINWINDOW_H
