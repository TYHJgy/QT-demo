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



void SysManageForm::on_pushButton_2_clicked()
{
    qDebug() << "on_pushButton_2_clicked()";
    qDebug() << "sizeHint:" << ui->pushButton_2->sizeHint();
    qDebug() << "sizeHint.isValid:" << ui->pushButton_2->sizeHint().isValid();
    qDebug() << "minimumSizeHint:" << ui->pushButton_2->minimumSizeHint();
    qDebug() << "size:" << ui->pushButton_2->size();
    qDebug() << "minimumSize:" << ui->pushButton_2->minimumSize();
    qDebug() << "maximumSize:" << ui->pushButton_2->maximumSize();
    qDebug() << "sizePolicy :" << ui->pushButton_2->sizePolicy();
    qDebug() << "==============================";

}

void SysManageForm::on_pushButton_3_clicked()
{
    QPushButton * pushButton = ui->pushButton_3;
    qDebug() << "on_pushButton_3_clicked()";
    qDebug() << "sizeHint:" << pushButton->sizeHint();
    qDebug() << "sizeHint.isValid:" << pushButton->sizeHint().isValid();
    qDebug() << "minimumSizeHint:" << pushButton->minimumSizeHint();
    qDebug() << "size:" << pushButton->size();
    qDebug() << "minimumSize:" << pushButton->minimumSize();
    qDebug() << "maximumSize:" << pushButton->maximumSize();
    qDebug() << "sizePolicy :" << pushButton->sizePolicy();
    qDebug() << "==============================";
}
