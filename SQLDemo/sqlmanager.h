#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QDir>

class SqlManager : public QObject
{
    Q_OBJECT
public:
    SqlManager();
    ~SqlManager();

    enum DbType {
        SQLite,
        MySql
    };

    //连接数据库
    bool connectDb(const DbType &dbType);

    QString getFileSQLite() const;

private:
    QString fileSQLite;
};

#endif // SQLMANAGER_H
