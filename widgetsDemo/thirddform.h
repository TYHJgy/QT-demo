#ifndef THIRDDFORM_H
#define THIRDDFORM_H

#include <QWidget>

namespace Ui {
class ThirdDForm;
}

class ThirdDForm : public QWidget
{
    Q_OBJECT

public:
    explicit ThirdDForm(QWidget *parent = nullptr);
    ~ThirdDForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ThirdDForm *ui;
};

#endif // THIRDDFORM_H
