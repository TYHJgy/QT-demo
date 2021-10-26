#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H

#include "user.h"
#include <QSqlDatabase>
#include <QMessageBox>

class DatabaseOperation
{
public:
    DatabaseOperation();
    /**
     * @brief 连接数据库(QODBC)
     */
    static bool connectDatabase();
    /**
     * @brief 查询用户信息
     * @param userName 用户名
     * @return 用户信息
     */
    User * selectUser(QString userName);
};

#endif // DATABASECONFIG_H
