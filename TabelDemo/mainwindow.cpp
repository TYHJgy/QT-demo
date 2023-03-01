#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTableWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTableWidget()
{
    QTableWidget * table = ui->tableWidget;
    table->setColumnCount(1000);
    table->setRowCount(0);
    //列宽自适应table
//    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//列宽根据内容自动调整会导致更新表格数据时耗时加剧
    table->horizontalHeader()->setSectionResizeMode(9,QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(10,QHeaderView::Stretch);
}



void MainWindow::on_btnInsertRow_clicked()
{
    QTime time = QTime::currentTime();
    //当插入新的item时候，旧的item会自动delete。一个item只能插入一个单元格
    QTableWidgetItem * item;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    for(int i=0;i<ui->tableWidget->columnCount();i++){
        item = new QTableWidgetItem(tr("%1").arg(100.105+i+ui->tableWidget->rowCount()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i,item);
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}


void MainWindow::on_btnDeleteRow_clicked()
{
    QTableWidgetItem * item = ui->tableWidget->item(1,1);
    qDebug() << item;
    delete item;
}

void MainWindow::on_btnUpdateRow_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int c=0;c<ui->tableWidget->columnCount();c++){
        item = ui->tableWidget->item(ui->tableWidget->rowCount()-1,c);
        item->setText("123456");
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnRowCenter_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0xFFF0)|Qt::AlignHCenter);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnColumnCenter_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0x000F)|Qt::AlignVCenter);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnRowLeft_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0xFFF0)|Qt::AlignLeft);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnColumnTop_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0x000F)|Qt::AlignTop);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnColumnBottom_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0x000F)|Qt::AlignBottom);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}

void MainWindow::on_btnRowRight_clicked()
{
    QTime time = QTime::currentTime();
    QTableWidgetItem * item;
    for(int r=0;r<ui->tableWidget->rowCount();r++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            item = ui->tableWidget->item(r,c);
            item->setTextAlignment((item->textAlignment()&0xFFF0)|Qt::AlignRight);
        }
    }
    qDebug() << time.msecsTo(QTime::currentTime());
}
