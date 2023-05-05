#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wpsoperator.h"

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
    void on_createFileBtn_clicked();

    void on_writeLineBtn_clicked();

    void on_callMacroBtn_clicked();

    void on_copyFileBtn_clicked();

    void on_openFileBtn_clicked();

    void on_saveFileBtn_clicked();

    void on_closeFileBtn_clicked();

    void on_addSheetBtn_clicked();

    void on_removeSheetBtn_clicked();

    void on_writeBlockBtn_clicked();

private:
    Ui::MainWindow *ui;
    WPSOperator * wPSOperator;
};
#endif // MAINWINDOW_H
