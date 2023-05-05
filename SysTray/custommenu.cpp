#include "custommenu.h"
#include "commonutils.h"
CustomMenu::CustomMenu(QWidget *parent)
    : QMenu(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);//设置透明
    CommonUtils::loadStyleSheet(this, "Menu"); //加载样式表
}

CustomMenu::~CustomMenu()
{
}

void CustomMenu::addCustomMenu(const QString & text, const QString & icon,const QString&name)
{	/*要结合下面这个例子来理解
    customMenu->addCustomMenu("onShow", ":/Resources/MainWindow/app/logo.ico", QStringLiteral("显示"));
    customMenu->addCustomMenu("onQuit", ":/Resources/MainWindow/app/page_close_btn_hover.png", QStringLiteral("退出"));
    //如果是"onshow"对象触发到了点击信号则执行onShowNormal槽方法
    connect(customMenu->getAction("onShow"), SIGNAL(triggered(bool)), m_parent, SLOT(onShowNormal(bool)));//如果点击到显示则把要显示的窗口显示出来
    connect(customMenu->getAction("onQuit"), SIGNAL(triggered(bool)), m_parent, SLOT(onShowQuit(bool)));//如果点击到退出则退出应用
    */

    QAction*pAction = addAction(QIcon(icon), name);
    m_menuActionMap.insert(text, pAction);
}

QAction * CustomMenu::getAction(const QString & text)
{

    return m_menuActionMap[text];
}

