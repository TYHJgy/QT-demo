#ifndef STYLEDEMOFORM_H
#define STYLEDEMOFORM_H

#include <QWidget>

namespace Ui {
class StyleDemoForm;
}

class StyleDemoForm : public QWidget
{
    Q_OBJECT

public:
    explicit StyleDemoForm(QWidget *parent = nullptr);
    ~StyleDemoForm();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::StyleDemoForm *ui;
};

#endif // STYLEDEMOFORM_H
