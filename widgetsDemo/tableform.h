#ifndef TABLEFORM_H
#define TABLEFORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class TableForm;
}

class TableForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableForm(QWidget *parent = nullptr);
    ~TableForm();

private slots:

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_checkBox_stateChanged();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_12_clicked();

    void on_checkBox_5_stateChanged();

    void on_checkBox_4_stateChanged();

    void on_lineEdit_editingFinished();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_editingFinished();

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_pushButton_13_clicked();

private:
    Ui::TableForm *ui;
    void createTableView();
};

#endif // TABLEFORM_H
