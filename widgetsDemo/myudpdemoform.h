#ifndef MYUDPDEMOFORM_H
#define MYUDPDEMOFORM_H

#include <QWidget>

namespace Ui {
class MyUdpDemoForm;
}

class MyUdpDemoForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyUdpDemoForm(QWidget *parent = nullptr);
    ~MyUdpDemoForm();

private slots:
    void on_udpclient_clicked();

    void on_udpDemo_clicked();

private:
    Ui::MyUdpDemoForm *ui;
};

#endif // MYUDPDEMOFORM_H
