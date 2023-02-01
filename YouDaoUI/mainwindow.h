#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QStyle>
#include <QFile>
#include <Qt>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString testString();
    void testAdd(const int i1,const int i2);
private:
    void initStyleSheet();
protected:
      bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
