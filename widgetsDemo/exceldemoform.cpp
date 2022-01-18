#include "exceldemoform.h"
#include "ui_exceldemoform.h"

#include <QFileDialog>
#include <QAxObject>
#include <QDebug>
#include <QMessageBox>

ExcelDemoForm::ExcelDemoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExcelDemoForm)
{
    ui->setupUi(this);
}

ExcelDemoForm::~ExcelDemoForm()
{
    delete ui;
}


//导出数据到excel
void ExcelDemoForm::on_pushButton_clicked()
{
   //获取保存路径
   QString filepath=QFileDialog::getSaveFileName(this,tr("Save"),".",tr(" (*.xlsx)"));
   if(!filepath.isEmpty()){
       QAxObject *excel = new QAxObject(this);
       //连接Excel控件
       excel->setControl("Excel.Application");
       //是否显示excel窗体
       excel->dynamicCall("SetVisible (bool Visible)","false");
       //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
       excel->setProperty("DisplayAlerts", true);
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
        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
       QAxObject *cellA,*cellB,*cellC,*cellD;
       //设置标题
       int cellrow=1;
       //设置要操作的单元格，如A1
       QString A=new QString(65) + QString::number(cellrow);
       QString B="B"+QString::number(cellrow);
       QString C="C"+QString::number(cellrow);
       QString D="D"+QString::number(cellrow);
       //获取单元格
       cellA = worksheet->querySubObject("Range(QVariant, QVariant)",A);
       cellB = worksheet->querySubObject("Range(QVariant, QVariant)",B);
       cellC = worksheet->querySubObject("Range(QVariant, QVariant)",C);
       cellD = worksheet->querySubObject("Range(QVariant, QVariant)",D);
       //设置单元格文本格式
       cellA->setProperty("NumberFormatLocal", "@");
       //设置单元格的表头值
       cellA->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
       cellB->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
       cellC->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
       cellD->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
       cellrow++;
       int rows = 3;
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
           cellA->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
           cellB->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
           cellC->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
           cellD->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
           cellrow++;
       }

//       workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
       workbook->dynamicCall("Save()");
       workbook->dynamicCall("Close()");//关闭工作簿
       excel->dynamicCall("Quit()");//关闭excel
       delete excel;
       excel=NULL;

       int ret = QMessageBox::warning(this, QStringLiteral("提示!"),
                                      QStringLiteral("n导出成功啦！！！"),
                                      QMessageBox::Cancel | QMessageBox::Ok);
        if( ret == QMessageBox::Ok)
        {
            return;
        }

        qDebug() << "\n导出成功啦！！！";
   }
}


//合并单元格
void ExcelDemoForm::on_pushButton_2_clicked()
{
    //获取保存路径
    QString filepath=QFileDialog::getSaveFileName(this,tr("Save"),".",tr(" (*.xlsx)"));
    if(!filepath.isEmpty()){
        QAxObject *excel = new QAxObject(this);
        //连接Excel控件
        excel->setControl("Excel.Application");
        //是否显示excel窗体
        excel->dynamicCall("SetVisible (bool Visible)","false");
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
//        worksheet->dynamicCall("test1()");

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
        cellA->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
        cellB->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
        cellC->dynamicCall("SetValue(const QVariant&)",QVariant("1"));
        cellD->dynamicCall("SetValue(const QVariant&)",QVariant("1"));

        //合并单元格
        QAxObject * range = worksheet->querySubObject("Range(QString, QString)","A5","A10");
        QAxObject * range2 = worksheet->querySubObject("Range(QVariant, QVariant)","C5","C10");
        range->dynamicCall("Merge()");
        range2->dynamicCall("Merge()");

        //运行宏
        //QT程序查找PERSONAL.XLSB的默认位置是C:\Users\gy\Documents
        excel->dynamicCall("Run(QString)","PERSONAL.XLSB!test1");

        //保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;

        qDebug() << "\n导出成功啦！！！";
}

}


//调用excel宏
void ExcelDemoForm::on_pushButton_3_clicked()
{
    //获取保存路径
    QString filepath=QFileDialog::getSaveFileName(this,tr("Save"),".",tr(" (*.xlsx)"));
    if(!filepath.isEmpty()){
        QAxObject *excel = new QAxObject(this);
        //连接Excel控件
        excel->setControl("Excel.Application");
        //是否显示excel窗体
        excel->dynamicCall("SetVisible (bool Visible)","false");
        //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
        excel->setProperty("DisplayAlerts", false);
        //获取工作簿集合
        QAxObject *workbooks = excel->querySubObject("WorkBooks");
        //新建一个工作簿
        workbooks->dynamicCall("Add");
        //获取当前工作簿
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");

        //运行宏
        //QT程序查找PERSONAL.XLSB的默认位置是C:\Users\gy\Documents
        excel->dynamicCall("Run(QString)","PERSONAL.XLSB!test1");

        //保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel=NULL;

        qDebug() << "\n导出成功啦！！！";
    }
}

//选择文件，导入数据
void ExcelDemoForm::on_pushButton_4_clicked()
{

    QVector<QVector<QString>> vecDatas = loadExcel("sheet1");
//    for(int i=0;i<vecDatas.count();i++){
//        QVector<QString> slist = vecDatas[i];
//        qDebug() << vecDatas[i];
//        for(int j=0;j<slist.count();j++){
//            qDebug() << i << "+" << slist[j];
//        }
//    }

    initHorizontalHeader(vecDatas[0].count());
    for(QVector<QString> e : vecDatas){
        insertRow(e);
    }
}

//整页读取
QVector<QVector<QString>> ExcelDemoForm::loadExcel(QString strSheetName)
{
    QVector<QVector<QString>> vecDatas;//获取所有数据
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "/", tr("excel Files (*.xlsx)"));
    qDebug() << fileName;
    QFile file(fileName);
    if(!file.exists()){
        qWarning() << "文件不存在";
        return vecDatas;
    }
    QAxObject *excel = new QAxObject("Excel.Application");//excel应用程序
    excel->dynamicCall("SetVisible(bool)", false); //true 表示操作文件时可见，false表示为不可见
    QAxObject *workbooks = excel->querySubObject("WorkBooks");//所有excel文件
    QAxObject *workbook = workbooks->querySubObject("Open(QString&)", fileName);//按照路径获取文件
    QAxObject * worksheets = workbook->querySubObject("WorkSheets");//获取文件的所有sheet页
    QAxObject * worksheet = worksheets->querySubObject("Item(QString)", strSheetName);//获取文件sheet页
    if(nullptr == worksheet){
        qWarning()<<strSheetName<<"Sheet页不存在。";
        return vecDatas;
    }
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");//有数据的矩形区域

    //获取行数
    QAxObject * rows = usedrange->querySubObject("Rows");
    int nRows = rows->property("Count").toInt();
    if(nRows <= 1){
        qWarning()<<"无数据，跳过该文件";
        return vecDatas;
    }

    //获取列数
//    QAxObject * columns = usedrange->querySubObject("Columns");
//    int nColumns = columns->property("Count").toInt();


    QVariant var = usedrange->dynamicCall("Value");
    foreach(QVariant varRow,var.toList()){
        QVector<QString> vecDataRow;
        foreach(QVariant var,varRow.toList()){
            vecDataRow.push_back(var.toString());
        }
        vecDatas.push_back(vecDataRow);
    }

    //关闭文件
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    if (excel)
    {
        delete excel;
        excel = NULL;
    }

    return vecDatas;
}

/**
 * @brief TableForm::on_pushButton_6_clicked
 *   修改列表头样式
 */
void ExcelDemoForm::initHorizontalHeader(int column)
{
    auto * table = ui->tableWidget;
    for(int i=0;i<column;i++){
        table->insertColumn(i);
    }
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
//    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

/**
 * @brief TableForm::on_pushButton_7_clicked
 * 新增一行数据
 */
void ExcelDemoForm::insertRow(QVector<QString> vecDataRow)
{
    auto * table = ui->tableWidget;

    //新增一行（空行）
    table->insertRow(table->rowCount());
    int rowIdx = table->rowCount() - 1;

    //添加一行数据

    for(int i=0;i<vecDataRow.count();i++){
        QTableWidgetItem *item = new QTableWidgetItem(vecDataRow[i]);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        table->setItem(rowIdx,i,item);
    }


}
