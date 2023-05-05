#include "wpsoperator.h"

WPSOperator::WPSOperator(QObject *parent) : QObject(parent)
{
    excel = new QAxObject();
    //连接Excel控件
    if(!excel->setControl("ket.Application")){
        qDebug() << "连接ket.Application失败";
    }
}

WPSOperator::~WPSOperator()
{
    delete excel;
}

bool WPSOperator::createFile(const QString fileName)
{
    qDebug()<<"enter createFile";
    currentFileName = fileName;
    QFile file(currentFileName);
    file.open(QIODevice::ReadWrite);
    file.close();
    if(!file.exists()){
        qDebug() << "文件不存在";
        return false;
    }
    return true;
}

bool WPSOperator::writeLine(QList<QString> strList)
{
    qDebug() << "in writeLine";
    QAxObject *cellA,*cellB,*cellC;


    //获取单元格
    cellA = worksheet->querySubObject("Range(QVariant, QVariant)","A1");
    cellB = worksheet->querySubObject("Range(QVariant, QVariant)","B1");
    cellC = worksheet->querySubObject("Range(QVariant, QVariant)","C1");

    //设置单元格的值
    cellA->dynamicCall("SetValue(const QVariant&)",QVariant("A1"));
    cellB->dynamicCall("SetValue(const QVariant&)",QVariant("B1"));
    cellC->dynamicCall("SetValue(const QVariant&)",QVariant("C1"));

    return true;
}

bool WPSOperator::callMacro()
{
    //运行宏
    //excel宏文件默认位置：C:\Users\gy\AppData\Roaming\Microsoft\Excel\XLSTART
    //QT程序查找PERSONAL.XLSB的默认位置是C:\Users\gy\Documents
    excel->dynamicCall("Run(QString)",currentFileName+"!Macro1");
    return true;
}

bool WPSOperator::copyFile(const QString fileName,const QString newfileName)
{
    //复制文件
    QFile::copy(fileName,newfileName);
    qDebug() << newfileName;
    QFile file(newfileName);
    if(!file.exists()){
        qDebug() << "文件不存在";
        return false;
    }
    return true;
}

bool WPSOperator::openFile(const QString fileName)
{
    currentFileName = fileName;
    //是否显示excel窗体.true-显示； false-不显示
    excel->dynamicCall("SetVisible (bool Visible)","true");
    //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
    excel->setProperty("DisplayAlerts", true);
    //获取工作簿集合
    workbooks = excel->querySubObject("WorkBooks");
    //代开一个工作簿
    workbook = workbooks->querySubObject("Open(QString&)", fileName);
    //获取文件的所有sheet页
    worksheets = workbook->querySubObject("WorkSheets");
    //获取指定sheet页
    worksheet = worksheets->querySubObject("Item(QString)", "Sheet1");
    if(nullptr == worksheet){
        qDebug()<<"Sheet1页不存在。";
        return false;
    }
    return true;
}

bool WPSOperator::saveFile()
{
    workbook->dynamicCall("Save()");
    return true;
}

bool WPSOperator::closeFile()
{
    workbook->dynamicCall("Close()");//关闭工作簿
    excel->dynamicCall("Quit()");//关闭excel
    delete excel;
    excel = nullptr;
    return true;
}

bool WPSOperator::addSheet()
{
    //新建sheet
    QAxObject* newSheet = worksheets->querySubObject("Add()");
    if(nullptr == newSheet){
        qWarning()<<"新建Sheet页失败。";
        return false;
    }
    return true;
}

bool WPSOperator::removeSheet()
{
    //删除
    worksheets->querySubObject("Delete()");
    return true;
}

bool WPSOperator::writeBlock(const QList<QList<QString> > &cells)
{
    if(cells.size() <= 0)
        return false;
    if(NULL == this->worksheet || this->worksheet->isNull())
        return false;
    int startRow = 1;
    int rowCount = cells.size();
    int colCount = cells.at(0).size();

    QList<QList<QVariant>> vCells;
    QList<QVariant> row;
    for(int i=0;i<cells.size();i++)
    {
        for(int j=0;j<cells[i].size();j++)
        {
            qDebug() << "bui:" << cells[i].at(j);
            row.append(cells[i].at(j));
        }
        vCells.append(row);
    }


    QString rangStr;
    convertToColName(colCount,rangStr);
    rangStr += QString::number(rowCount+startRow);
    rangStr = "A" +QString::number(startRow+1)+ ":" + rangStr;
    qDebug() << "rangStr:" << rangStr;
    QAxObject *range = this->worksheet->querySubObject("Range(const QString&)",rangStr);
    if(NULL == range || range->isNull())
    {
        qDebug() << "123456";
        return false;
    }
    bool succ = false;
    QVariant var;
    castListListVariant2Variant(vCells,var);

    // 数据
    QVariantList table; // 表格
    QVariantList tableLine; // 表格行

    // 测试
    for (int i = 0; i < 100; ++i) { // 列
        tableLine << QStringLiteral("test%1").arg(i);
    }
    for (int i = 0; i < 100; ++i) { // 行
        table << QVariant(tableLine);   // 每次添加一行
    }

    succ = range->setProperty("Value2", table);
    delete range;
    qDebug() << "succ:"<<succ;
    return succ;
}
void WPSOperator::convertToColName(int data, QString &res)
{
    Q_ASSERT(data>0 && data<65535);
    int tempData = data / 26;
    if(tempData > 0)
    {
        int mode = data % 26;
        convertToColName(mode,res);
        convertToColName(tempData,res);
    }
    else
    {
        res=(to26AlphabetString(data)+res);
    }
}
///
/// \brief 数字转换为26字母
///
/// 1->A 26->Z
/// \param data
/// \return
///
QString WPSOperator::to26AlphabetString(int data)
{
    QChar ch = data + 0x40;//A对应0x41
    return QString(ch);
}

//把QList<QList<QVariant> > 转为QVariant,用于快速写入的
void WPSOperator::castListListVariant2Variant(const QList<QList<QVariant> > &cells, QVariant &res)
{
    QVariantList vars;
    const int rows = cells.size();//获取行数
    for(int i=0;i<rows;++i)
    {
        vars.append(QVariant(cells[i]));//将list(i)添加到QVariantList中 QVariant(cells[i])强制转换
    }
    res = QVariant(vars);//强制转换
}
