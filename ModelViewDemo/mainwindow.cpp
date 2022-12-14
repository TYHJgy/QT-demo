#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initFileSystemModelView();
    initStringListModelView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initFileSystemModelView()
{
    QFileSystemModel * model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    //信号与槽关联，treeView单击时，其目录设置为listView和tableView的根节点
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
         ui->listView,SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
         ui->tableView,SLOT(setRootIndex(QModelIndex)));
    fileSystemModel = model;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
   QFileSystemModel * model = fileSystemModel;
   ui->chkIsDir->setChecked(model->isDir(index)); //是否是目录
   ui->LabPath->setText(model->filePath(index));
   ui->LabType->setText(model->type(index));
   ui->LabFileName->setText(model->fileName(index));
   int sz=model->size(index)/1024;
   if (sz<1024)
      ui->LabFileSize->setText(QString("%1 KB").arg(sz));
   else
      ui->LabFileSize->setText(QString::asprintf("%.1f MB",sz/1024.0));
}



void MainWindow::initStringListModelView()
{
    QStringList strList;
    strList<<"北京"<<"上海"<<"天津"<<"河北"<<"山东"<<"四川"<<"重庆";
    QStringListModel * model=new QStringListModel(this);
    model->setStringList(strList); //导入strList的内容
    ui->listView_2->setModel(model); //设置数据模型
    ui->listView_2->setEditTriggers(QAbstractItemView::DoubleClicked |
              QAbstractItemView::SelectedClicked);
#if 1
    //设置QListView的条目是否可以编辑，以及如何进入编辑状态【可编辑】
    ui->listView_2->setEditTriggers(QAbstractItemView::DoubleClicked |
                     QAbstractItemView::SelectedClicked);
#else
    //设置QListView的条目是否可以编辑，以及如何进入编辑状态【不可编辑】
    ui->listView_2->setEditTriggers(QAbstractItemView:: NoEditTriggers);
#endif

    stringListModel = model;
}


void MainWindow::on_btnListAppend_clicked()
{
    //添加一行
    QStringListModel * model = stringListModel;
    model->insertRow(model->rowCount()); //在尾部插入一空行
    QModelIndex index=model->index(model->rowCount()-1,0);
    model->setData(index,"new item",Qt::DisplayRole);
    ui->listView_2->setCurrentIndex(index); //设置当前选中的行
}

void MainWindow::on_btnListInsert_clicked()
{
    //插入一行
    QStringListModel * model = stringListModel;
    QModelIndex  index=ui->listView_2->currentIndex();
    model->insertRow(index.row());
    model->setData(index,"inserted item",Qt::DisplayRole);
    ui->listView_2->setCurrentIndex(index);
}

void MainWindow::on_btnListDelete_clicked()
{
    //删除当前行
    QModelIndex index=ui->listView_2->currentIndex();
    stringListModel->removeRow(index.row());
}

void MainWindow::on_btnListClear_clicked()
{
    //清除所有项
    stringListModel->removeRows(0,stringListModel->rowCount());
}

void MainWindow::on_btnTextImport_clicked()
{
    //显示数据模型的StringList
    QStringList  tmpList=stringListModel->stringList();
    ui->plainTextEdit->clear();
    for (int i=0; i<tmpList.count();i++)
        ui->plainTextEdit->appendPlainText(tmpList.at(i));
}

void MainWindow::on_listView_2_clicked(const QModelIndex &index)
{
    //显示QModelIndex的行、列号
    ui->LabInfo->setText(QString::asprintf("当前条目:row=%d, column=%d",
              index.row(),index.column()));
}

void MainWindow::on_btnOpenStdWin_clicked()
{
    StandardItemWindow * w = new StandardItemWindow(this);
    //设置子窗口属性，在子窗口关闭之后，释放子窗口的资源(释放指针)
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->setWindowModality(Qt::ApplicationModal);
    w->setWindowTitle("标准数据模型");
    w->show();
}

void MainWindow::on_btnConSQL_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"选择数据库文件","",
                                                   "SQLite数据库(*.db *.db3)");
    qDebug() << file;
    if(file.isEmpty())
        return;
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(file);
    if(!m_db.open())
    {
        qDebug()<<"打开失败";
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT NAME, SALARY FROM COMPANY");
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    ui->tableView_2->setModel(model);
}
