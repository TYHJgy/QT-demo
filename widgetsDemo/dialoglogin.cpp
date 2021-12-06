#include "dialoglogin.h"
#include "ui_dialoglogin.h"

#include "databaseOperation.h"
#include <QMessageBox>
#include <QDebug>


DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);

    this->setWindowTitle("用户登录");
    //连接数据库
    if(!DatabaseOperation::connectDatabase()){
        QMessageBox::warning(this,"警告","数据库连接失败",QMessageBox::Yes);
    }else{
        QMessageBox::warning(this,"警告","数据库连接成功",QMessageBox::Yes);
    }
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_button_login_clicked()
{
    DatabaseOperation databaseOperation;
    QString username = ui->lineEdit_account->text().trimmed();
    QString pwd = ui->lineEdit_pwd->text().trimmed();
    if(username.length() == 0){
        qDebug() << "请输入账号";
        return;
    }
    if(pwd.length() == 0){
        qDebug() << "请输入密码";
        return;
    }

    // 判断用户名和密码是否正确，
    User * user = databaseOperation.selectUser(username);
    // 如果错误则弹出警告对话框
    if(pwd == user->getPassword())
    {
        qDebug() << "password correct";
        accept();
    } else {
        qDebug() << "password error";
        QMessageBox::warning(this,"警告","账号或密码错误",QMessageBox::Yes);
    }
}
