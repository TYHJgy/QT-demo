#include "standarditemwindow.h"
#include "ui_standarditemwindow.h"

StandardItemWindow::StandardItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StandardItemWindow)
{
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
    }
}


void StandardItemWindow::on_actAppend_triggered()
{
    //在表格最后添加行
//    QList<QStandardItem*>  aItemList; //列表类
//    QStandardItem   *aItem;
//    for(int i=0;iheaderData(theModel->columnCount()-1, Qt::Horizontal, Qt::DisplayRole).toString();
//    aItem=new QStandardItem(str); //创建 "测井取样" Item
//    aItem->setCheckable(true);
//    aItemList<insertRow(theModel->rowCount(),aItemList); //插入一行
//    QModelIndex curIndex=theModel->index(theModel->rowCount()-1,0);
//    theSelection->clearSelection();
//    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}
