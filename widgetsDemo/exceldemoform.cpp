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

       workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
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
