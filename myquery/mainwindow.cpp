#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("db_example");
//    db.setHostName("127.0.0.1");
//    db.setPort(3306);
//    db.setUserName("root");
//    db.setPassword("123456");
    bool ok = db.open();

    if (ok){
//        QMessageBox::information(this, "infor", "success");
    }
    else {
        QMessageBox::information(this, "infor", "open failed");
//        qDebug()<<"error open database because"<<db.lastError().text();
    }
}


void MainWindow::on_insertData_clicked()
{
    QSqlQuery query;
    query.exec("insert into student(_name,_year) values('gy14',18)");
}

void MainWindow::on_deleteData_clicked()
{

}

void MainWindow::on_updateData_clicked()
{

}


void MainWindow::on_selectData_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM student");
    //列名别名
    model->setHeaderData(0, Qt::Horizontal, tr("A"));
    model->setHeaderData(1, Qt::Horizontal, tr("B"));
    model->setHeaderData(2, Qt::Horizontal, tr("C"));

//    QSqlTableModel *model = new QSqlTableModel;
//    model->setTable("student");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
//    //列名别名
//    model->setHeaderData(0, Qt::Horizontal, tr("A"));
//    model->setHeaderData(1, Qt::Horizontal, tr("B"));
//    model->setHeaderData(2, Qt::Horizontal, tr("C"));

    QTableView *view = ui->tableView;
    view->setShowGrid(true);
    view->setWordWrap(true);
    view->setAutoScroll(true);
    view->setModel(model);
    view->show();
}

