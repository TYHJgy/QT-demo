#include "standarditemwindow.h"
#include "ui_standarditemwindow.h"

StandardItemWindow::StandardItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StandardItemWindow)
{
    qDebug() << "StandardItemWindow";
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    theModel = new QStandardItemModel(FixedRowCount,FixedColumnCount,this); //数据模型
    theSelection = new QItemSelectionModel(theModel);//选择模型
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
          this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(theModel); //设置数据模型
    ui->tableView->setSelectionModel(theSelection);//设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    //plainTextEdit设置为不自动换行
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

    //创建状态栏组件
    LabCurFile = new QLabel(this);  //当前文件
    LabCellPos = new QLabel(this);  //当前单元格行列号
    LabCellText = new QLabel(this); //当前单元格内容

    LabCurFile->setMinimumWidth(200);
    LabCellPos->setMinimumWidth(150);
    LabCellText->setMinimumWidth(200);

    ui->statusbar->addWidget(LabCurFile);
    ui->statusbar->addWidget(LabCellPos);
    ui->statusbar->addWidget(LabCellText);

}

StandardItemWindow::~StandardItemWindow()
{
    qDebug() << "~StandardItemWindow";
    delete ui;
}

void StandardItemWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    //选择单元格变化时的响应
    if (current.isValid())
    {
      LabCellPos->setText(QString::asprintf("当前单元格：%d行，%d列",
                          current.row(),current.column()));
      QStandardItem*   aItem=theModel->itemFromIndex(current);
      this->LabCellText->setText("单元格内容："+aItem->text());
      QFont   font=aItem->font();
      ui->actFontBold->setChecked(font.bold());
    }
}


void StandardItemWindow::iniModelFromStringList(QStringList& aFileContent)
{
    //从一个StringList 获取数据，初始化数据模型
    int rowCnt=aFileContent.count(); //文本行数，第1行是标题
    theModel->setRowCount(rowCnt-1);
    //设置表头，一个或多个空格、TAB等分隔符隔开的字符串，分解为一个StringList
    QString  header=aFileContent.at(0);//第1行是表头
    QStringList  headerList=
         header.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    theModel->setHorizontalHeaderLabels(headerList); //设置表头文字
    //设置表格数据
    QStandardItem   *aItem;
    QStringList   tmpList;
    int j;
    for (int i=1;i<rowCnt;i++)
    {
        QString  aLineText=aFileContent.at(i);
        tmpList=aLineText.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        for (j=0;j<FixedColumnCount-1;j++)
        { //不包含最后一列
            aItem=new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1,j,aItem); //为模型的某个行列位置设置Item
        }
        aItem=new QStandardItem(headerList.at(j));//最后一列
        aItem->setCheckable(true); //设置为Checkable
        if (tmpList.at(j)=="0")
            aItem->setCheckState(Qt::Unchecked);
        else
            aItem->setCheckState(Qt::Checked);
        theModel->setItem(i-1,j,aItem);
    }
}



void StandardItemWindow::on_actOpen_triggered()
{
    //打开文件
    QString  curPath=QCoreApplication::applicationDirPath();
    QString  aFileName=QFileDialog::getOpenFileName(this,"打开一个文件",
              curPath,"井数据文件(*.txt);;所有文件(*.*)");
    if (aFileName.isEmpty())
      return;

    QStringList fFileContent;
    QFile aFile(aFileName);
    if (aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //打开文件
    {
        QTextStream aStream(&aFile); //用文本流读取文件
        aStream.setCodec("UTF-8");
        ui->plainTextEdit->clear();
        while (!aStream.atEnd())
        {
            QString  str=aStream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fFileContent.append(str);
        }
        aFile.close();
        this->LabCurFile->setText("当前文件："+aFileName);//状态栏显示
        iniModelFromStringList(fFileContent);//初始化数据模型
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
    }
}


void StandardItemWindow::on_actAppend_triggered()
{
    //在表格最后添加行
    QList<QStandardItem*> aItemList; //列表类
    QStandardItem*aItem;

    for(int i=0;i<FixedColumnCount-1;i++){
         aItem=new QStandardItem("0");
         aItemList << aItem;
    }
    QString str = theModel->headerData(theModel->columnCount()-1, Qt::Horizontal, Qt::DisplayRole).toString();
    aItem=new QStandardItem(str); //创建 "测井取样" Item
    aItem->setCheckable(true);
    aItemList<<aItem;
//    theModel->insertRow(theModel->rowCount(),aItemList); //插入一行
    theModel->appendRow(aItemList);
    QModelIndex curIndex=theModel->index(theModel->rowCount()-1,0);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

void StandardItemWindow::on_actSave_triggered()
{
    //保存为文件
    QString curPath=QCoreApplication::applicationDirPath();
    QString aFileName=QFileDialog::getSaveFileName(this,"选择一个文件", curPath,"井斜数据文件(*.txt);;所有文件(*.*)");
    if (aFileName.isEmpty())
        return;
    QFile aFile(aFileName);
    if (!(aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
        return; //以读写、覆盖原有内容方式打开文件

    QTextStream aStream(&aFile);
    aStream.setCodec("UTF-8");
    QStandardItem *aItem;
    int i,j;
    QString str;
    ui->plainTextEdit->clear();
    //获取表头文字
    for (i=0;i<theModel->columnCount();i++)
    {
        aItem=theModel->horizontalHeaderItem(i); //获取表头的项数据
        str=str+aItem->text()+"\t";  //以TAB隔开
    }
    aStream << str << "\n";
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区文字
    for ( i=0;i<theModel->rowCount();i++)
    {
        str="";
        for( j=0;j<theModel->columnCount()-1;j++)
        {
            aItem=theModel->item(i,j);
            str=str+aItem->text()+QString::asprintf("\t");
        }
        aItem=theModel->item(i,j); //最后一列是逻辑型
        if (aItem->checkState()==Qt::Checked)
            str=str+"1";
        else
            str=str+"0";
        aStream << str << "\n";
        ui->plainTextEdit->appendPlainText(str);
    }
}

void StandardItemWindow::on_actModelData_triggered()
{
    QStandardItem *aItem;
    int i,j;
    QString str;
    ui->plainTextEdit->clear();
    //获取表头文字
    for (i=0;i<theModel->columnCount();i++)
    {
        aItem=theModel->horizontalHeaderItem(i); //获取表头的项数据
        str=str+aItem->text()+"\t";  //以TAB隔开
    }
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区文字
    for ( i=0;i<theModel->rowCount();i++)
    {
        str="";
        for( j=0;j<theModel->columnCount()-1;j++)
        {
            aItem=theModel->item(i,j);
            str=str+aItem->text()+QString::asprintf("\t");
        }
        aItem=theModel->item(i,j); //最后一列是逻辑型
        if (aItem->checkState()==Qt::Checked)
            str=str+"1";
        else
            str=str+"0";
        ui->plainTextEdit->appendPlainText(str);
    }
}

void StandardItemWindow::on_actInsert_triggered()
{
    //在表格最后添加行
    QList<QStandardItem*> aItemList; //列表类
    QStandardItem*aItem;

    for(int i=0;i<FixedColumnCount-1;i++){
         aItem=new QStandardItem("1");
         aItemList << aItem;
    }
    QString str = theModel->headerData(theModel->columnCount()-1, Qt::Horizontal, Qt::DisplayRole).toString();
    aItem=new QStandardItem(str); //创建 "测井取样" Item
    aItem->setCheckable(true);
    aItemList<<aItem;

    QModelIndex currentIndex = theSelection->currentIndex();
    theModel->insertRow(currentIndex.row(),aItemList); //插入一行
    QModelIndex curIndex=theModel->index(theModel->rowCount()-1,0);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

void StandardItemWindow::on_actDelete_triggered()
{
    int rowNum = theSelection->currentIndex().row();
    theModel->removeRow(rowNum);
    QModelIndex curIndex=theModel->index(rowNum,0);
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

void StandardItemWindow::on_actAlignLeft_triggered()
{
    setTextAlignment(Qt::AlignLeft);
}

void StandardItemWindow::on_actAlignCenter_triggered()
{
    setTextAlignment(Qt::AlignCenter);
}

void StandardItemWindow::on_actAlignRight_triggered()
{
    setTextAlignment(Qt::AlignRight);
}
void StandardItemWindow::setTextAlignment(Qt::Alignment atextAlignment)
{
    if (!theSelection->hasSelection())
        return;
    //获取选择的单元格的模型索引列表，可以是多选
    QModelIndexList selectedIndex=theSelection->selectedIndexes();
    for (int i=0;i<selectedIndex.count();i++)
    {
        QModelIndex  aIndex=selectedIndex.at(i); //获取一个模型索引
        QStandardItem * aItem=theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(atextAlignment|Qt::AlignVCenter);//设置文字对齐方式
    }
}

void StandardItemWindow::on_actFontBold_triggered()
{
    //设置字体粗体
    if (!theSelection->hasSelection())
        return;
    QModelIndexList selectedIndex=theSelection->selectedIndexes();
    for (int i=0;i< selectedIndex.count();i++)
    {
        QModelIndex aIndex= selectedIndex.at(i); //获取一个模型索引
        QStandardItem * aItem=theModel->itemFromIndex(aIndex);//获取项数据
        QFont font=aItem->font();
        font.setBold(true); //设置字体是否粗体
        aItem->setFont(font);
    }
}

void StandardItemWindow::on_actExit_triggered()
{
//    close();

}
