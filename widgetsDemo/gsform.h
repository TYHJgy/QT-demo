#ifndef GSFORM_H
#define GSFORM_H

#include <QWidget>

namespace Ui {
class GsForm;
}

class GsForm : public QWidget
{
    Q_OBJECT

public:
    explicit GsForm(QWidget *parent = nullptr);
    ~GsForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GsForm *ui;
};

#endif // GSFORM_H
