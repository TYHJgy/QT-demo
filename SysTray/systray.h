#pragma once

#include <QSystemTrayIcon>
#include <QSystemTrayIcon>
#include <QDebug>

class SysTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    SysTray(QWidget *parent = nullptr);
    ~SysTray();
public slots:
    void onIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onShowNormal(bool state);
private:
    void initSystemTray();   //初始化
    void addSystemTrayMenu();//创建菜单
private:
    QWidget * m_parent;//用于保存父类窗口，到时候通过点击托盘时展示的窗口就作为父窗口
};

