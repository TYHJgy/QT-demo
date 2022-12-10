#include "excelmanager.h"
#include "Windows.h"

QAxObject *ExcelManager::getPExcel() const
{
    return pExcel;
}

void ExcelManager::setPExcel(QAxObject *value)
{
    pExcel = value;
}

QAxObject *ExcelManager::getPWorkbook() const
{
    return pWorkbook;
}

void ExcelManager::setPWorkbook(QAxObject *value)
{
    pWorkbook = value;
}

QAxObject *ExcelManager::getPWorksheet() const
{
    return pWorksheet;
}

void ExcelManager::setPWorksheet(QAxObject *value)
{
    pWorksheet = value;
}

void ExcelManager::slotCreateExcelFile(QString pathName)
{
    qDebug() << "enter slotsCreateExcelFile";
    bool re = createExcelFile(pathName);
    qDebug() << "excel打开:" << re;
    emit signalsCreateExcelFileFinish(re);
}

void ExcelManager::slotWriteOneLineData(QList<uint16_t> lineData)
{
    writeOneLineData(lineData);
}

ExcelManager::ExcelManager()
{

}

ExcelManager::~ExcelManager()
{
    qDebug() << "释放ExcelManager";

    delete pExcel;
    delete pWorkbook;
    delete pWorksheet;
}

ExcelManager::ExcelManager(QObject *parent)
{
    if(nullptr == parent){
        return;
    }
    this->setParent(parent);
}

/*
 * 创建excel文件。
 * pathName：文件路径+文件名
*/
bool ExcelManager::createExcelFile(QString pathName){
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    QAxObject * excel = new QAxObject();
    //连接Excel控件
    bool re = excel->setControl("Excel.Application");
    if(!re){
        qWarning() << "打开失败";
        return false;
    }

    //是否显示excel窗体.true-显示；false-不显示
    excel->dynamicCall("SetVisible (bool Visible)","true");
    //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
    excel->setProperty("DisplayAlerts", true);
    //获取工作簿集合
    QAxObject * workbooks = excel->querySubObject("WorkBooks");
    //新建一个工作簿
    workbooks->dynamicCall("Add");
    //获取当前工作簿
    QAxObject * workbook = excel->querySubObject("ActiveWorkBook");
    //获取工作表集合
    QAxObject *worksheets = workbook->querySubObject("Sheets");
    //获取工作表集合的工作表1，即sheet1
    QAxObject * worksheet = worksheets->querySubObject("Item(int)",1);
//    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(pathName+ ".xlsx"));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(pathName+ ".xls"));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。

    pExcel = excel;
    pWorkbook = workbook;
    pWorksheet = worksheet;
    return true;
}

void ExcelManager::writeOneLineData(QList<uint16_t> &lineData)
{
    //保存数据到excel文件
   static int cellrow = 0;
   cellrow++;
   for(int i=0;i<lineData.size();i++){
       QString location;
       if(i<26){
           location = new QString(65+i) + QString::number(cellrow);
       }else if(i<52){
           location = "A";
           location = location.append(65+i-26) + QString::number(cellrow);
       }else if(i<78){
           location = "B";
           location = location.append(65+i-52) + QString::number(cellrow);
       }else if(i<104){
           location = "C";
           location = location.append(65+i-78) + QString::number(cellrow);
       }else if(i<130){
           location = "D";
           location = location.append(65+i-104) + QString::number(cellrow);
       }else if(i<156){
           location = "E";
           location = location.append(65+i-130) + QString::number(cellrow);
       }else if(i<182){
           location = "F";
           location = location.append(65+i-156) + QString::number(cellrow);
       }else if(i<208){
           location = "G";
           location = location.append(65+i-182) + QString::number(cellrow);
       }else if(i<234){
           location = "H";
           location = location.append(65+i-208) + QString::number(cellrow);
       }else{
           qWarning("超过234个16位字节");
       }
       QAxObject * cell = pWorksheet->querySubObject("Range(QVariant, QVariant)",location);
       cell->setProperty("NumberFormatLocal", "@");//格式转换。执行后没有错误提示
       cell->dynamicCall("SetValue(const QVariant&)",QVariant(QString::number(lineData[i],16)));
   }
}


///
/// \brief 写入一个表格内容
/// \param cells
/// \return 成功写入返回true
/// \see readAllSheet
///
bool ExcelManager::writeCurrentSheet(const QList<QList<QVariant> > &cells,const int startRow)
{
    if(cells.size() <= 0)
        return false;
    if(NULL == this->pWorksheet || this->pWorksheet->isNull())
        return false;
    int row = cells.size();
    int col = cells.at(0).size();
    QString rangStr;
    convertToColName(col,rangStr);
    rangStr += QString::number(row);
    rangStr = "A" +QString::number(startRow)+ ":" + rangStr;
    qDebug()<<rangStr;
    QAxObject *range = this->pWorksheet->querySubObject("Range(const QString&)",rangStr);
    if(NULL == range || range->isNull())
    {
        return false;
    }
    bool succ = false;
    QVariant var;
    castListListVariant2Variant(cells,var);
    succ = range->setProperty("Value", var);
    delete range;
    return succ;
}

///
/// \brief 把列数转换为excel的字母列号
/// \param data 大于0的数
/// \return 字母列号，如1->A 26->Z 27 AA
///
void ExcelManager::convertToColName(int data, QString &res)
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
QString ExcelManager::to26AlphabetString(int data)
{
    QChar ch = data + 0x40;//A对应0x41
    return QString(ch);
}

//把QList<QList<QVariant> > 转为QVariant,用于快速写入的
void ExcelManager::castListListVariant2Variant(const QList<QList<QVariant> > &cells, QVariant &res)
{
    QVariantList vars;
    const int rows = cells.size();//获取行数
    for(int i=0;i<rows;++i)
    {
        vars.append(QVariant(cells[i]));//将list(i)添加到QVariantList中 QVariant(cells[i])强制转换
    }
    res = QVariant(vars);//强制转换
}

