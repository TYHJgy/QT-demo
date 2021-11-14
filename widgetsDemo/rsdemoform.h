#ifndef RSDEMOFORM_H
#define RSDEMOFORM_H

#include <QWidget>
#include <QDebug>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTime>


namespace Ui {
class RSDemoForm;
}

class RSDemoForm : public QWidget
{
    Q_OBJECT

public:
    explicit RSDemoForm(QWidget *parent = nullptr);
    ~RSDemoForm();

private slots:
    void on_pushButton_clicked();

    void on_openSerial_stateChanged(int arg1);

    void on_sendData_clicked();

private:
    Ui::RSDemoForm *ui;
    QSerialPort serial;
    void scanPortNum();
};

#endif // RSDEMOFORM_H
