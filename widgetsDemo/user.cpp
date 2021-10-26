#include "user.h"

QString User::getUserName() const
{
    return userName;
}

void User::setUserName(const QString &value)
{
    userName = value;
}

qint8 User::getAge() const
{
    return age;
}

void User::setAge(const qint8 &value)
{
    age = value;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &value)
{
    password = value;
}

User::User()
{

}
