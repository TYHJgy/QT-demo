#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if(ui->lineEdit->text().trimmed() == tr("gaoyang") &&
            ui->lineEdit_2->text() == tr("123456"))
    {
        accept();
    } else {
        QMessageBox::warning(this, tr("警告"),
                             tr("账号或密码错误!"),
                             QMessageBox::Yes);
    }
}
