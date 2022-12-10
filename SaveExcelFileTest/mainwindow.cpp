#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , excelType(0)
{
    ui->setupUi(this);
    qRegisterMetaType<QList<uint16_t>>("QList<uint16_t>");//注册diskInformation类型
    qDebug() <<"this->thread():"<< this->thread();
    excelManager = new ExcelManager(nullptr);

    excelThread = new QThread();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,&MainWindow::timerOut);
}

MainWindow::~MainWindow()
{
    qDebug() << "enter ~MainWindow";
    delete ui;
//    excelThread->deleteLater();
    delete excelThread;
    delete excelManager;
//    excelManager->deleteLater();
}


void MainWindow::on_pushButtonOpenFile_clicked()
{
    QString pathName = QDir::currentPath()+"/test";
    qDebug() << "pathName:" << pathName;
    excelManager->createExcelFile(pathName);
}

void MainWindow::on_pushButtonWriteData_clicked()
{
    QList<uint16_t> lineData;
    for(uint16_t i=0;i<200;i++){
        lineData.append(i);
    }
    excelManager->writeOneLineData(lineData);
}

void MainWindow::on_pushButtonWriteDataAuto_clicked()
{
    timer->start(1000);
}

//根据log可以看到，写一行数据大概需要150ms
static uint count = 0;
void MainWindow::timerOut()
{
    qDebug() << "in:" << QTime::currentTime();
    count++;
    QList<uint16_t> lineData;
    for(uint16_t i=70;i>0;i--){
        lineData.append(i);
    }
    if(excelType == 0){
        excelManager->writeOneLineData(lineData);
    }else{
        emit signalWriteOneLineData(lineData);
        lineData.clear();
        for(uint16_t i=0;i<70;i++){
            lineData.append(i);
        }
        emit signalWriteOneLineData(lineData);
    }
    qDebug() << "out:" << QTime::currentTime();
    qDebug() << "count:"<<count;
}

void MainWindow::on_pushButtonStopWriteDataAuto_2_clicked()
{
    timer->stop();
}


void MainWindow::on_pushButtonCreateNewThread_clicked()
{

    excelManager->moveToThread(excelThread);
    qDebug() << "excelManager->thread():"<<excelManager->thread();
    connect(this,SIGNAL(signalCreateNewExcelFile(QString)),excelManager,SLOT(slotCreateExcelFile(QString)));
    connect(this,SIGNAL(signalWriteOneLineData(QList<uint16_t>)),excelManager,SLOT(slotWriteOneLineData(QList<uint16_t>)));
    //connect(this,&MainWindow::signalsCreateNewExcelFile,excelManager,&ExcelManager::slotsCreateExcelFile);

    excelThread->start();

}

void MainWindow::on_pushButtonOpenFileInNewThread_clicked()
{
    qDebug() << "enter on_pushButtonOpenFileInNewThread_clicked";
    QString pathName = QDir::currentPath()+"/test";
    qDebug() << "pathName:" << pathName;
    emit signalCreateNewExcelFile(pathName);
}

void MainWindow::on_pushButtonWriteDataAutoInNewThread_clicked()
{
    timer->start(1000);
    excelType = 1;

}

void MainWindow::on_pushButtonStopThread_clicked()
{
    excelThread->quit();
}

void MainWindow::on_pushButtonStopWrite_clicked()
{

}

void MainWindow::on_pushButtonWriteData_2_clicked()
{
    QElapsedTimer timer;
    timer.start();
    qDebug()<<"create cost:"<<timer.elapsed()<<"ms";timer.restart();
    QList< QList<QVariant>> m_datas;
    for(int i=0;i<1000;++i)
    {
        QList<QVariant> rows;
        for(int j=0;j<100;++j)
        {
            rows.append(i*j);
        }
        m_datas.append(rows);
    }
    timer.restart();
    excelManager->writeCurrentSheet(m_datas,5);
    qDebug()<<"write cost:"<<timer.elapsed()<<"ms";timer.restart();

}
