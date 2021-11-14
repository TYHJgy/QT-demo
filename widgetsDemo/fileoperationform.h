#ifndef FILEOPERATIONFORM_H
#define FILEOPERATIONFORM_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QFileDialog>


namespace Ui {
class FileOperationForm;
}

class FileOperationForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileOperationForm(QWidget *parent = nullptr);
    ~FileOperationForm();

private slots:
    void on_newFile_clicked();

    void on_readData_clicked();

    void on_removeFile_clicked();

private:
    Ui::FileOperationForm *ui;
};

#endif // FILEOPERATIONFORM_H
