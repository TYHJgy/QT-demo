#include "sysmanageform.h"
#include "ui_sysmanageform.h"


#include <QSplitter>
#include <QPushButton>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QGridLayout>
#include <QList>
#include <QDebug>

SysManageForm::SysManageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysManageForm)
{
    ui->setupUi(this);
    this->setWindowTitle("系统管理");
}

SysManageForm::~SysManageForm()
{
    delete ui;
}


