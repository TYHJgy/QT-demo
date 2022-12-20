#include "sqlmanager.h"

SqlManager::SqlManager()
{
    fileSQLite = QDir::currentPath() + "/test.db";
    qDebug() << "fileSQLite:" << fileSQLite;
}

SqlManager::~SqlManager()
{

}

bool SqlManager::connectDb(const SqlManager::DbType &dbType)
{
    bool rs = false;
    if(dbType == DbType::SQLite){
        QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(fileSQLite);
        if(!m_db.open())
        {
            qDebug()<<"打开失败";
            rs = false;
        }else{
            rs = true;
        }
    }else if(dbType == DbType::MySql){
        rs = true;
    }else{
        qDebug() << "未完";
        rs = false;
    }
    return rs;
}

QString SqlManager::getFileSQLite() const
{
    return fileSQLite;
}
