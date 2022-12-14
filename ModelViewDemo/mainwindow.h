#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QFileSystemModel>
#include <QStringListModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
//#include <QSQLiteDriver>


#include "standarditemwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initFileSystemModelView();
    void initStringListModelView();
private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_btnListAppend_clicked();

    void on_btnListInsert_clicked();

    void on_btnListDelete_clicked();

    void on_btnListClear_clicked();

    void on_btnTextImport_clicked();

    void on_listView_2_clicked(const QModelIndex &index);

    void on_btnOpenStdWin_clicked();

    void on_btnConSQL_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel * fileSystemModel;
    QStringListModel * stringListModel;
};
#endif // MAINWINDOW_H
