#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initTableWidget();

private slots:
    void on_btnInsertRow_clicked();

    void on_btnDeleteRow_clicked();

    void on_btnUpdateRow_clicked();

    void on_btnRowCenter_clicked();

    void on_btnColumnCenter_clicked();

    void on_btnRowLeft_clicked();

    void on_btnColumnTop_clicked();

    void on_btnColumnBottom_clicked();

    void on_btnRowRight_clicked();

private:
    Ui::MainWindow *ui;
//    QTableWidgetItem * item;
};
#endif // MAINWINDOW_H
