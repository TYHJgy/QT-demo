#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QXmlStreamWriter>


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
    void on_readBtn_clicked();

    void on_addBtn_clicked();

    void on_createFile_clicked();

    void on_deleteFile_clicked();

    void on_updateElementBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
