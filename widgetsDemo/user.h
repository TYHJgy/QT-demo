#ifndef USER_H
#define USER_H

#include <QString>
class User
{
private:
    QString userName;
    qint8 age;
    QString password;
public:
    User();
    QString getUserName() const;
    void setUserName(const QString &value);
    qint8 getAge() const;
    void setAge(const qint8 &value);
    QString getPassword() const;
    void setPassword(const QString &value);
};

#endif // USER_H
