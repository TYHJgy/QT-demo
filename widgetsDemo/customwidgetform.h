#ifndef CUSTOMWIDGETFORM_H
#define CUSTOMWIDGETFORM_H

#include <QWidget>

namespace Ui {
class CustomWidgetForm;
}

class CustomWidgetForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidgetForm(QWidget *parent = nullptr);
    ~CustomWidgetForm();

private:
    Ui::CustomWidgetForm *ui;
};

#endif // CUSTOMWIDGETFORM_H
