#include "wmic.h"
#include <QProcess>
#include <QDebug>

QString WMIC::result(QString cmd)
{
    QProcess wmic;
    wmic.start(cmd);
    wmic.waitForFinished();
    wmic.readLine();
    QString ret = wmic.readLine().simplified();
    return ret;
}

QString WMIC::cpuName()
{
    QString cmd = "wmic CPU get name";
    return result(cmd);
}

QString WMIC::cpuId()
{
    QString cmd = "wmic CPU get processorid";
    return result(cmd);
}

QString WMIC::csUUID()
{
    QString cmd = "wmic CSPRODUCT get uuid";
    return result(cmd);
}

QString WMIC::baseboardSN()
{
    QString cmd = "wmic BASEBOARD get serialnumber";
    return result(cmd);
}

QString WMIC::biosSN()
{
    QString cmd = "wmic BIOS get serialnumber";
    return result(cmd);
}

QString WMIC::diskSN(int n)
{
    QString cmd = QString("wmic DISKDRIVE where index=%1 get serialnumber").arg(n);
    return result(cmd);
}
