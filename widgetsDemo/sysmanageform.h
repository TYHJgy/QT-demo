#ifndef SYSMANAGEFORM_H
#define SYSMANAGEFORM_H

#include <QWidget>

namespace Ui {
class SysManageForm;
}

class SysManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit SysManageForm(QWidget *parent = nullptr);
    ~SysManageForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SysManageForm *ui;
};

#endif // SYSMANAGEFORM_H
