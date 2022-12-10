#ifndef EXCELMANAGER_H
#define EXCELMANAGER_H

#include <QObject>
#include <QDebug>
#include <QFileDialog>
#include <QAxObject>
#include <QDateTime>
#include <QMessageBox>


class ExcelManager : public QObject
{
    Q_OBJECT
private:
    QAxObject * pExcel;
    QAxObject * pWorkbook;
    QAxObject * pWorksheet;
public slots:
    void slotCreateExcelFile(QString pathName);
    void slotWriteOneLineData(QList<uint16_t> lineData);
signals:
    void signalsCreateExcelFileFinish(bool result);
public:
    ExcelManager();
    ~ExcelManager();
    ExcelManager(QObject *parent = nullptr);
    //创建excel文件
    bool createExcelFile(QString pathName);
    //写入数据
    void writeOneLineData(QList<uint16_t> &lineData);
    QString to26AlphabetString(int data);
    void convertToColName(int data, QString &res);
    bool writeCurrentSheet(const QList<QList<QVariant> > &cells,const int startRow);
    void castListListVariant2Variant(const QList<QList<QVariant> > &cells, QVariant &res);

    QAxObject *getPExcel() const;
    void setPExcel(QAxObject *value);
    QAxObject *getPWorkbook() const;
    void setPWorkbook(QAxObject *value);
    QAxObject *getPWorksheet() const;
    void setPWorksheet(QAxObject *value);
};

#endif // EXCELMANAGER_H
