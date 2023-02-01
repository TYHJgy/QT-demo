#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QDebug>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = nullptr);
    ~ProgressDialog();

private slots:
    void on_progressBar_valueChanged(int value);
    void timeoutProcess();
private:
    Ui::ProgressDialog *ui;
    QTimer * timer;
};

#endif // PROGRESSDIALOG_H
