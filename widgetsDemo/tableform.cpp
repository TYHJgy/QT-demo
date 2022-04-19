#include "tableform.h"
#include "ui_tableform.h"

#include "customtabstyle.h"

#include <QWidget>
#include <QtWidgets/QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QAxObject>


TableForm::TableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableForm)
{
    ui->setupUi(this);
    //createTableView();
    ui->tabWidget->setTabPosition(QTabWidget::West);

    //给tabWidget设置新样式
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
}

TableForm::~TableForm()
{
    delete ui;
}

/**
 * @brief TableForm::createTableView
 * 代码创建tableView
 */
void TableForm::createTableView(){
    //创建table
    QTableView * tableView = new QTableView(this);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setGeometry(QRect(0, 0, 500, 300));
    tableView->setGridStyle(Qt::PenStyle::SolidLine);
    tableView->horizontalHeader()->setHighlightSections(false);//点击表时不对表头行光亮（获取焦点）

    //表头字体加粗
    QFont font =  tableView->horizontalHeader()->font();
    font.setBold(true);
    tableView->horizontalHeader()->setFont(font);

    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}"); //skyblue设置表头背景色
    tableView->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    tableView->verticalHeader()->setHidden(true);//去掉默认行号
    //所有列都扩展自适应宽度，填充充满整个屏幕宽度
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置固定宽度
//    tableView->setColumnWidth(0, 20);


    //创建数据模型
    QStandardItemModel* model = new QStandardItemModel(this);

    /*设置列字段名*/
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal, "姓名");
    model->setHeaderData(1,Qt::Horizontal, "年龄");
    model->setHeaderData(2,Qt::Horizontal, "性别");

    /*设置行字段名*/
//    model->setRowCount(3);
//    model->setHeaderData(0,Qt::Vertical, "记录一");
//    model->setHeaderData(1,Qt::Vertical, "记录二");
//    model->setHeaderData(2,Qt::Vertical, "记录三");

    /*设置一条数据*/
    model->setItem(0, 0, new QStandardItem("张三"));
    model->setItem(0, 1, new QStandardItem("3"));
    model->setItem(0, 2, new QStandardItem(1));

    model->item(0,0)->setTextAlignment(Qt::AlignCenter);//居中
    tableView->setModel(model);

    //移除数据
//    model->removeRow(0);//移除第0行数据
//    model->removeColumn(0);//移除第0列数据

    //添加一行
    QList<QStandardItem*> list;
    list << new QStandardItem("王五") << new QStandardItem("22") << new QStandardItem("男");
    model->insertRow(0, list); //在第0行插入一条记录

    //添加一列
    model->insertColumn(0);

    //添加复选框-方法1
    QWidget *widget = new QWidget(tableView);
    QCheckBox *checkbox = new QCheckBox();
    QHBoxLayout *hLayout = new QHBoxLayout();

    hLayout->addWidget(checkbox);
    hLayout->setMargin(0);                              // 必须添加, 否则CheckBox不能正常显示
    hLayout->setAlignment(checkbox, Qt::AlignCenter);   // 居中显示复选框
    widget->setLayout(hLayout);
    tableView->setIndexWidget(model->index(0 , 3), widget);

    //添加复选框-方法2
//    QStandardItem *item = new QStandardItem();
//    item->setCheckable(true);
//    item->setCheckState(Qt::Unchecked);
//    item->setEditable(false);//item 不可编辑
//    model->setItem(0, 0, item);
//    qDebug() << model->item(0,0)->checkState();

//    //指定列都扩展自适应宽度，填充充满整个屏幕宽度
//    qDebug() << tableView->horizontalHeader()->count();
//    tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);


}
//获取单元格widget
void getCheckState(QTableView * tableView)
{
     QStandardItemModel* model = (QStandardItemModel*)tableView->model();
     qDebug() << model->item(0,1)->text();
     auto * widget = tableView->indexWidget(model->index(0 , 0));
     auto * hLayout = widget->layout();
     QCheckBox * checkbox = (QCheckBox *)hLayout->itemAt(0)->widget();
     qDebug() << checkbox -> checkState();
}



/**
 * @brief TableForm::on_pushButton_6_clicked
 *   修改列表头样式
 */
void TableForm::on_pushButton_6_clicked()
{
    auto * table = ui->tableWidget;
    //打印行数（数据行+1表头）
    qDebug() << table->rowCount();

    //设置表头背景色
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}");

    //设置选中背景色
    table->setStyleSheet("selection-background-color:lightblue;");

    //表头字体加粗
    QFont font =  table->horizontalHeader()->font();
    font.setBold(true);
    table->horizontalHeader()->setFont(font);

    //修改表头名字
    QTableWidgetItem *item1 = new QTableWidgetItem("第1列");
    QTableWidgetItem *item2 = new QTableWidgetItem("第2列");
    QTableWidgetItem *item3 = new QTableWidgetItem("第3列");
    QTableWidgetItem *item4 = new QTableWidgetItem("第4列");
    table->setHorizontalHeaderItem(0,item1);
    table->setHorizontalHeaderItem(1,item2);
    table->setHorizontalHeaderItem(2,item3);
    table->setHorizontalHeaderItem(3,item4);
    qDebug() << table->horizontalHeaderItem(0)->text();
    qDebug() << table->horizontalHeaderItem(1)->text();
    qDebug() << table->horizontalHeaderItem(2)->text();
    qDebug() << table->horizontalHeaderItem(3)->text();

    //列宽自适应table
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

/**
 * @brief TableForm::on_pushButton_11_clicked
 *   修改行表头样式
 */
void TableForm::on_pushButton_11_clicked()
{
    auto * table = ui->tableWidget;

    //设置表头背景色
    table->verticalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}");

    //表头字体加粗
    QFont font =  table->horizontalHeader()->font();
    font.setBold(true);
    table->verticalHeader()->setFont(font);

    //表头item修改
    QTableWidgetItem *item = new QTableWidgetItem("第一行");
    table->setVerticalHeaderItem(0,item);
    qDebug() << table->verticalHeaderItem(0)->text();


}

/**
 * @brief TableForm::on_pushButton_7_clicked
 * 新增一行数据
 */
void TableForm::on_pushButton_7_clicked()
{
    auto * table = ui->tableWidget;

    //新增一行（空行）
    table->insertRow(table->rowCount());
    int rowIdx = table->rowCount() - 1;

    //添加数据
    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(1));
    QTableWidgetItem *item1 = new QTableWidgetItem("username");
    QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg((10)));
    QTableWidgetItem *item3 = new QTableWidgetItem("username2");
    item1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    table->setItem(rowIdx,0,item0);
    table->setItem(rowIdx,1,item1);
    table->setItem(rowIdx,2,item2);
    table->setItem(rowIdx,3,item3);

    //添加控件
#if 1
    //方法1
    QWidget *widget = new QWidget(this);
    QCheckBox *checkbox = new QCheckBox();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(checkbox);
    hLayout->setMargin(0);                              // 必须添加, 否则CheckBox不能正常显示
    hLayout->setAlignment(checkbox, Qt::AlignCenter);   // 居中显示复选框
    table->setCellWidget(rowIdx, 4, widget);

    //读取checkState
    auto * layout = table->cellWidget(rowIdx, 4)->layout();
    qDebug() << layout;
    QCheckBox * checkbox2 = (QCheckBox*)layout->itemAt(0)->widget();
    qDebug() << checkbox2;
    qDebug() << checkbox2->checkState();

#else
    //方法2
    QTableWidgetItem *checkbox = new QTableWidgetItem();
    checkbox->setTextAlignment(Qt::AlignVCenter);
    checkbox->setCheckState(Qt::Checked);
    table->setItem(rowIdx,4,checkbox);
#endif
}
/**
 * @brief TableForm::on_pushButton_9_clicked
 * 新增一列数据
 */
void TableForm::on_pushButton_9_clicked()
{
    auto * table = ui->tableWidget;

    //新增一（空列）
    table->insertColumn(table->columnCount());
    int colIdx = table->columnCount() - 1;
    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(1));
    QTableWidgetItem *item1 = new QTableWidgetItem("username");
    QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg((10)));
    table->setItem(0,colIdx,item0);
    table->setItem(1,colIdx,item1);
    table->setItem(2,colIdx,item2);


}


/**
 * @brief TableForm::on_pushButton_8_clicked
 *   删除一行数据
 */
void TableForm::on_pushButton_8_clicked()
{
    auto * table = ui->tableWidget;
    table->removeRow(table->rowCount()-1);
}

/**
 * @brief TableForm::on_pushButton_8_clicked
 *   删除一列数据
 */
void TableForm::on_pushButton_10_clicked()
{
    auto * table = ui->tableWidget;
    table->removeColumn(table->columnCount()-1);

}

/**
 * @brief 表格是否可以编译
 * @param arg1
 */
void TableForm::on_checkBox_stateChanged()
{
    auto * table = ui->tableWidget;
    auto * checkBox = ui->checkBox;
    qDebug() << checkBox->checkState();
    if(checkBox->checkState() == Qt::Checked){
        qDebug() << table->editTriggers();
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        qDebug() << QAbstractItemView::NoEditTriggers;
    }else{
        qDebug() << table->editTriggers();
        table->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
}

/**
 * @brief 靠左显示
 */
void TableForm::on_radioButton_clicked()
{
    qDebug() << ui->radioButton->text();
    qDebug() << ui->radioButton->isChecked();
    qDebug() << ui->radioButton_2->text();
    for(int i=0;i<ui->tableWidget->columnCount();i++){
        for(int j=0;j<ui->tableWidget->rowCount();j++){
            ui->tableWidget->item(j,i)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        }
    }
}

/**
 * @brief 居中显示
 */
void TableForm::on_radioButton_3_clicked()
{
    qDebug() << ui->radioButton_3->text();
    qDebug() << ui->radioButton_2->text();
    for(int i=0;i<ui->tableWidget->columnCount();i++){
        for(int j=0;j<ui->tableWidget->rowCount();j++){
            ui->tableWidget->item(j,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }
}

/**
 * @brief 靠右显示
 */
void TableForm::on_radioButton_2_clicked()
{
    qDebug() << ui->radioButton_2->text();
    for(int i=0;i<ui->tableWidget->columnCount();i++){
        for(int j=0;j<ui->tableWidget->rowCount();j++){
            ui->tableWidget->item(j,i)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        }
    }
}

/**
 * @brief TableForm::清除表数据
 */
void TableForm::on_pushButton_12_clicked()
{
    ui->tableWidget->clear();
}

void TableForm::on_checkBox_5_stateChanged()
{
    auto * checkBox = ui->checkBox_5;
    qDebug() << checkBox->checkState();
    if(checkBox->checkState() == Qt::Checked){
        ui->tableWidget->verticalHeader()->hide();
    }else{
        ui->tableWidget->verticalHeader()->show();
    }
}

void TableForm::on_checkBox_4_stateChanged()
{
    auto * checkBox = ui->checkBox_4;
    qDebug() << checkBox->checkState();
    if(checkBox->checkState() == Qt::Checked){
        ui->tableWidget->horizontalHeader()->hide();
    }else{
        ui->tableWidget->horizontalHeader()->show();
    }
}

//调整行高
void TableForm::on_lineEdit_editingFinished()
{
    qDebug() << ui->lineEdit->text();
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        ui->tableWidget->setRowHeight(i,ui->lineEdit->text().toInt());
    }

}

//调整列宽
void TableForm::on_spinBox_valueChanged(int arg1)
{
    qDebug() << arg1;
//    for(int i=0;i<ui->tableWidget->columnCount();i++){
//        ui->tableWidget->setColumnWidth(i,arg1);
//    }
}

void TableForm::on_spinBox_editingFinished()
{
    qDebug() << ui->spinBox->value();
    for(int i=0;i<ui->tableWidget->columnCount();i++){
        ui->tableWidget->setColumnWidth(i,ui->spinBox->value());
    }
}

//调整行高自动适应内容
void TableForm::on_checkBox_2_stateChanged(int arg1)
{
    qDebug() << arg1;
    if(ui->checkBox_2->checkState()==Qt::Checked){
        ui->tableWidget->resizeRowsToContents();
    }else{
        for(int i=0;i<ui->tableWidget->rowCount();i++){
            ui->tableWidget->setRowHeight(i,ui->lineEdit->text().toInt());
        }
    }
}

//调整列宽自动适应内容
void TableForm::on_checkBox_3_stateChanged(int arg1)
{
    qDebug() << arg1;
    if(ui->checkBox_2->checkState()==Qt::Checked){
//        ui->tableWidget->resizeColumnsToContents();
        //使用下面两句可以实现

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
    }else{
        for(int i=0;i<ui->tableWidget->columnCount();i++){
            ui->tableWidget->setColumnWidth(i,ui->spinBox->value());
        }
    }
}

// 导出数据ecxel
void TableForm::on_pushButton_13_clicked()
{
   //获取保存路径
   QString filepath=QFileDialog::getSaveFileName(this,tr("Save"),".",tr(" (*.xlsx)"));
   if(!filepath.isEmpty()){
       QAxObject *excel = new QAxObject(this);
       //连接Excel控件
       excel->setControl("Excel.Application");
       //不显示窗体
//       excel->dynamicCall("SetVisible (bool Visible)","false");
       //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
       excel->setProperty("DisplayAlerts", false);
       //获取工作簿集合
       QAxObject *workbooks = excel->querySubObject("WorkBooks");
       //新建一个工作簿
       workbooks->dynamicCall("Add");
       //获取当前工作簿
       QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
       //获取工作表集合
       QAxObject *worksheets = workbook->querySubObject("Sheets");
       //获取工作表集合的工作表1，即sheet1
       QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);

       QAxObject *cellA,*cellB,*cellC,*cellD;
       //设置标题
       int cellrow=1;
       //设置要操作的单元格，如A1
       QString A="A"+QString::number(cellrow);
       QString B="B"+QString::number(cellrow);
       QString C="C"+QString::number(cellrow);
       QString D="D"+QString::number(cellrow);
       //获取单元格
       cellA = worksheet->querySubObject("Range(QVariant, QVariant)",A);
       cellB = worksheet->querySubObject("Range(QVariant, QVariant)",B);
       cellC = worksheet->querySubObject("Range(QVariant, QVariant)",C);
       cellD = worksheet->querySubObject("Range(QVariant, QVariant)",D);
       //设置单元格的表头值
       cellA->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->horizontalHeaderItem(0)->text()));
       cellB->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->horizontalHeaderItem(1)->text()));
       cellC->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->horizontalHeaderItem(2)->text()));
       cellD->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->horizontalHeaderItem(3)->text()));
       cellrow++;
       int rows = ui->tableWidget->rowCount();
       //设置表格数据
       for(int i=0;i<rows;i++){
           //设置要操作的单元格，如A1，A2，A3，A4
           QString A="A"+QString::number(cellrow);
           QString B="B"+QString::number(cellrow);
           QString C="C"+QString::number(cellrow);
           QString D="D"+QString::number(cellrow);
           //获取单元格
           cellA = worksheet->querySubObject("Range(QVariant, QVariant)",A);
           cellB = worksheet->querySubObject("Range(QVariant, QVariant)",B);
           cellC = worksheet->querySubObject("Range(QVariant, QVariant)",C);
           cellD = worksheet->querySubObject("Range(QVariant, QVariant)",D);
           //设置单元格的值
           cellA->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->item(i,0)->text()));
           cellB->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->item(i,1)->text()));
           cellC->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->item(i,2)->text()));
           cellD->dynamicCall("SetValue(const QVariant&)",QVariant(ui->tableWidget->item(i,3)->text()));
           cellrow++;
       }

       workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
       workbook->dynamicCall("Close()");//关闭工作簿
       excel->dynamicCall("Quit()");//关闭excel
       delete excel;
       excel=NULL;
       qDebug() << "\n导出成功啦！！！";
   }
}
