#ifndef EXCELDEMOFORM_H
#define EXCELDEMOFORM_H

#include <QWidget>

namespace Ui {
class ExcelDemoForm;
}

class ExcelDemoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ExcelDemoForm(QWidget *parent = nullptr);
    ~ExcelDemoForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ExcelDemoForm *ui;
    QVector<QVector<QString>> loadExcel(QString strSheetName);
    void initHorizontalHeader(int column);
    void insertRow(QVector<QString> vecDataRow);
};

#endif // EXCELDEMOFORM_H
