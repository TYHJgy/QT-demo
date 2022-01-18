#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QDebug>

class Worker : public QThread
{
    Q_OBJECT

private:
//    QSerialPort * serial;
public:
    Worker(QSerialPort * serial);
    void run() override;

signals:
    void resultReady(const QString &s);
};

#endif // WORKER_H
