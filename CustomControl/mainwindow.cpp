#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTreeWidget();
    initStackWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initTreeWidget()
{
    //一级节点
    QStringList firstLevelItems;
    firstLevelItems << "基本控件" << "弹窗控件";

    //二级节点
    QStringList secondLevelItems;
    secondLevelItems << "LED灯-1" << "LED灯-2";
    secondLevelItemsList.append(secondLevelItems);
    secondLevelItems.clear();
    secondLevelItems << "加载等待-1" << "加载等待-2";
    secondLevelItemsList.append(secondLevelItems);
    secondLevelItems.clear();

    QTreeWidgetItem * firstLevelItem;
    QTreeWidgetItem * secondLevelItem;
    for(int i = 0;i < firstLevelItems.size();i++){
        firstLevelItem = new QTreeWidgetItem();
        firstLevelItem->setText(0,firstLevelItems.at(i));
        for(int j=0;j<secondLevelItemsList.at(i).size();j++){
            secondLevelItem = new QTreeWidgetItem();
            secondLevelItem->setText(0,secondLevelItemsList.at(i).at(j));
            firstLevelItem->addChild(secondLevelItem);
        }
        ui->treeWidget->addTopLevelItem(firstLevelItem);
    }
}

void MainWindow::initStackWidget()
{
    ui->stackedWidget->addWidget(new LoadingForm());
    ui->stackedWidget->addWidget(new LoadingForm());
    ui->stackedWidget->addWidget(new LoadingForm());
    ui->stackedWidget->addWidget(new LoadingForm());
    qDebug() << ui->stackedWidget->count();
}


void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    qDebug() << current->text(0);
    int preJ = 0;
    for(int i=0;i<secondLevelItemsList.size();i++){
        for(int j=0;j<secondLevelItemsList.at(i).size();j++){
            if(current->text(0) == secondLevelItemsList.at(i).at(j)){
//                qDebug() << "i:"<<i <<",j:" << j;
//                qDebug() << "i+j:" << i+j;
                qDebug() << "i*preJ+j:" << i*preJ+j;
                //切换stack widget
                ui->stackedWidget->setCurrentIndex(i*preJ+j);
            }
        }
        preJ = secondLevelItemsList.at(i).size();
    }

}

