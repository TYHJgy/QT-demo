#include "mouserightdemoform.h"
#include "ui_mouserightdemoform.h"

#include <QMessageBox>
MouseRightDemoForm::MouseRightDemoForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MouseRightDemoForm)
{
    ui->setupUi(this);
}

MouseRightDemoForm::~MouseRightDemoForm()
{
    delete ui;
}


void MouseRightDemoForm::on_MouseRightDemoForm_customContextMenuRequested(const QPoint &/*pos*/)
{
    //创建菜单对象
    QMenu *pMenu = new QMenu(this);

    QAction *pNewTask = new QAction(tr("新建任务"), this);
    QAction *pEditTask = new QAction(tr("设置任务"), this);
    QAction *pDeleteTask = new QAction(tr("删除任务"), this);

    QAction *pToolRenName = new QAction(tr("改名工具"), this);
    QAction *pToolEdot = new QAction(tr("设置工具"), this);
    QAction *pToolDelete = new QAction(tr("删除工具"), this);

    //1:新建任务 2:设置任务 3:删除任务 4:改名工具 5:设置工具 6:删除工具
    pNewTask->setData(1);
    pEditTask->setData(2);
    pDeleteTask ->setData(3);
    pToolRenName->setData(4);
    pToolEdot->setData(5);
    pToolDelete ->setData(6);

    //把QAction对象添加到菜单上
    pMenu->addAction(pNewTask);
    pMenu->addAction(pEditTask);
    pMenu->addAction(pDeleteTask);
    pMenu->addAction(pToolRenName);
    pMenu->addAction(pToolEdot);
    pMenu->addAction(pToolDelete);

    //连接鼠标右键点击信号
    connect(pNewTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pEditTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pDeleteTask, SIGNAL(triggered()), SLOT(onTaskBoxContextMenuEvent()));
    connect(pToolRenName, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pToolEdot, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pToolDelete, SIGNAL(triggered()), SLOT(onTaskBoxContextMenuEvent()));

    //在鼠标右键点击的地方显示菜单
    pMenu->exec(cursor().pos());

    //释放内存
    QList<QAction*> list = pMenu->actions();
    foreach (QAction* pAction, list) delete pAction;
    delete pMenu;
}

void MouseRightDemoForm::onTaskBoxContextMenuEvent()
{
    QAction *pEven = qobject_cast<QAction *>(this->sender()); //this->sender()就是发信号者 QAction

    //获取发送信息类型 1:新建任务 2:设置任务 3:删除任务 4:改名工具 5:设置工具 6:删除工具
    int iType = pEven->data().toInt();

    switch (iType)
    {
    case 1:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    case 2:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    case 3:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    case 4:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    case 5:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    case 6:
        QMessageBox::about(this, "tip", pEven->text());
        break;
    default:
        break;
    }
}
