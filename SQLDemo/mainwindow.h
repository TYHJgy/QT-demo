#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTimer>
#include <QTime>


#include "sqlmanager.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();

    void on_btnUpdateTable_clicked();

    void on_checkBox_stateChanged(int arg1);

    void timeOut();
    void on_ptnAdd_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    SqlManager * sqlManager;
    QSqlQueryModel * model;
    QTimer * timer;
    int count;
};
#endif // MAINWINDOW_H
