#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count(0)
{
    ui->setupUi(this);
    sqlManager = new SqlManager();
    ui->lineEdit->setText(sqlManager->getFileSQLite());

    model = new QSqlQueryModel;
    ui->tableView->setModel(model);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sqlManager;
    delete model;
}


void MainWindow::on_btnConnect_clicked()
{
    if(ui->cBoxDbType->currentIndex() == 0)
        sqlManager->connectDb(SqlManager::SQLite);
    else if(ui->cBoxDbType->currentIndex() == 1)
        sqlManager->connectDb(SqlManager::MySql);
    else
        qDebug() << "数据库类型错误";
    on_btnUpdateTable_clicked();
}

void MainWindow::on_btnUpdateTable_clicked()
{
    model->setQuery("SELECT NAME, SALARY FROM COMPANY");
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    while(model->canFetchMore())
    {
        model->fetchMore();
    }
    qDebug() << "model->rowCount():" << model->rowCount();
    QModelIndex index=model->index(model->rowCount()-1,0);
    ui->tableView->setCurrentIndex(index);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    qDebug() << arg1;
    if(arg1 == 0){
        timer->stop();
        qDebug() <<"1-stop time[" << QTime::currentTime().toString("hh:mm:ss.zzz") <<"]";

    }else{
        model->setQuery("DELETE FROM COMPANY");
        timer->start(5);
        qDebug() <<"1-start time[" << QTime::currentTime().toString("hh:mm:ss.zzz") <<"]";
    }
}

void MainWindow::timeOut()
{
    on_ptnAdd_clicked();
}

void MainWindow::on_ptnAdd_clicked()
{
    qDebug() <<"2-start time[" << QTime::currentTime().toString("hh:mm:ss.zzz") <<"]";
    count++;
    QString sql = "INSERT INTO COMPANY VALUES ("+ QString::number(count) +", 'James', 24, 'Houston', 10000.00 );";
    model->setQuery(sql);
//    on_btnUpdateTable_clicked();
    qDebug() <<"2-stop time[" << QTime::currentTime().toString("hh:mm:ss.zzz") <<"]";
}

void MainWindow::on_pushButton_8_clicked()
{
    model->setQuery("DELETE FROM COMPANY");
    model->setQuery("VACUUM");

    on_btnUpdateTable_clicked();
}
