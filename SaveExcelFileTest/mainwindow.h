#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QMetaType>
#include <QElapsedTimer>

#include "excelmanager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void signalCreateNewExcelFile(QString pathName);
    void signalWriteOneLineData(QList<uint16_t> lineData);

private slots:

    void timerOut();

    void on_pushButtonOpenFile_clicked();

    void on_pushButtonWriteData_clicked();

    void on_pushButtonWriteDataAuto_clicked();

    void on_pushButtonStopWriteDataAuto_2_clicked();

    void on_pushButtonCreateNewThread_clicked();

    void on_pushButtonOpenFileInNewThread_clicked();

    void on_pushButtonWriteDataAutoInNewThread_clicked();

    void on_pushButtonStopThread_clicked();

    void on_pushButtonStopWrite_clicked();

    void on_pushButtonWriteData_2_clicked();

private:
    Ui::MainWindow *ui;
    int excelType;
    ExcelManager * excelManager;
    QThread * excelThread;
    QTimer * timer;
};
#endif // MAINWINDOW_H
