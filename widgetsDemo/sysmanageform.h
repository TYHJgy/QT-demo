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

private:
    Ui::SysManageForm *ui;
};

#endif // SYSMANAGEFORM_H
