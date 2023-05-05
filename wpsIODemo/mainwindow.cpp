#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wPSOperator = new WPSOperator();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createFileBtn_clicked()
{
    QString fileName = QCoreApplication::applicationDirPath() +"/"+ QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss") + ".xlsm";
    wPSOperator->createFile(fileName);


}

void MainWindow::on_writeLineBtn_clicked()
{
    QList<QString> strList;
    wPSOperator->writeLine(strList);
}

void MainWindow::on_callMacroBtn_clicked()
{
    wPSOperator->callMacro();
}

void MainWindow::on_copyFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "./", tr("Image Files (*.xlsm *.xlsx)"));
    QString newfileName = QCoreApplication::applicationDirPath() +"/"+ QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss") + ".xlsm";
    wPSOperator->copyFile(fileName,newfileName);
}

void MainWindow::on_openFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "./", tr("Image Files (*.xlsm *.xlsx)"));
    wPSOperator->openFile(fileName);
}

void MainWindow::on_saveFileBtn_clicked()
{
    wPSOperator->saveFile();
}

void MainWindow::on_closeFileBtn_clicked()
{
    wPSOperator->closeFile();
}

void MainWindow::on_addSheetBtn_clicked()
{
    wPSOperator->addSheet();
}

void MainWindow::on_removeSheetBtn_clicked()
{
    wPSOperator->removeSheet();
}

void MainWindow::on_writeBlockBtn_clicked()
{
    QList<QList<QString> > cells;
    for(int i=0;i<10;i++)
    {
        QList<QString> row;
        for(int j=0;j<10;j++)
        {
            qDebug() <<"buy:" << QString::number(i*j);
            row.append(QString::number(i*j));
        }
        cells.append(row);
    }
    wPSOperator->writeBlock(cells);
}
