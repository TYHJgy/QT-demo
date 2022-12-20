#ifndef WMIC_H
#define WMIC_H

#include <QString>

/**
 * @brief The WMIC class 通过 wnic 命令获取电脑的一些基本信息
 */
class WMIC
{
public:
    static QString cpuName();
    static QString cpuId();
    static QString csUUID();
    static QString baseboardSN();
    static QString biosSN();
    static QString diskSN(int n);// n 是硬盘序号，从 0 开始

private:
    WMIC() = delete;
    static QString result(QString cmd);
};

#endif // WMIC_H
