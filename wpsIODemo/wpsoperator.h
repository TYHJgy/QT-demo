#ifndef WPSOPERATOR_H
#define WPSOPERATOR_H

#include <QObject>

#include <QFileDialog>
#include <QAxObject>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QCoreApplication>

class WPSOperator : public QObject
{
    Q_OBJECT
public:
    explicit WPSOperator(QObject *parent = nullptr);
    ~WPSOperator();
    //新建文件
    bool createFile(const QString fileName);
    //写入一行数据
    bool writeLine(QList<QString> strList);
    //调用宏定义
    bool callMacro();
    //复制文件
    bool copyFile(const QString fileName,const QString newfileName);
    //打开文件
    bool openFile(const QString fileName);
    //保存文件
    bool saveFile();
    //关闭文件
    bool closeFile();
    //添加Sheet
    bool addSheet();
    //移除Sheet.TODO
    bool removeSheet();
    //写一块数据
    bool writeBlock(const QList<QList<QString> > &cells);

private:
    void convertToColName(int data, QString &res);
    QString to26AlphabetString(int data);
    void castListListVariant2Variant(const QList<QList<QVariant> > &cells, QVariant &res);

signals:


private:
    QAxObject *excel;
    QAxObject *workbooks;
    QAxObject *workbook;
    QAxObject *worksheets;
    QAxObject *worksheet;
    QString currentFileName;


};

#endif // WPSOPERATOR_H
