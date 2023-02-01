#ifndef LOADINGFORM_H
#define LOADINGFORM_H

#include <QWidget>
#include <QDebug>

#include "waitdialog.h"

namespace Ui {
class LoadingForm;
}

class LoadingForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingForm(QWidget *parent = nullptr);
    ~LoadingForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoadingForm *ui;
};

#endif // LOADINGFORM_H
