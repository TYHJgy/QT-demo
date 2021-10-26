#include "databaseOperation.h"
#include <QMessageBox>
#include <iostream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

//#pragma execution_character_set("utf-8")

DatabaseOperation::DatabaseOperation()
{

}

/**
 * @brief 连接数据库(QODBC)
 */
bool DatabaseOperation::connectDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("db_example");
    bool ok = db.open();
    if (ok){
//        qDebug() << QString::fromLocal8Bit("连接成功");
        qDebug() << "连接成功";
        return true;
    } else {
//        qDebug() << QString::fromLocal8Bit("连接失败");
        qDebug() << "连接失败";
        return false;
    }
}

User * DatabaseOperation::selectUser(QString userName)
{
    User * user = new User();
    QSqlQuery query;
    QString sql = "select * from user where USER_NAME='" + userName + "'";
    qDebug() << sql;
    query.exec(sql);
    //开始就先执行一次next()函数，那么query指向结果集的第一条记录
    if(query.next())
    {
        int num = query.record().indexOf("USER_NAME");
        QString name = query.value(num).toString();
        qDebug() << name;
        num = query.record().indexOf("PASSWORD");
        QString password = query.value(num).toString();
        qDebug() << password;
        user->setUserName(name);
        user->setPassword(password);
        return user;
    }
    return nullptr;
}

