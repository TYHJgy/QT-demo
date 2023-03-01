#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QStyle>
#include <QFile>
#include <Qt>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <QPoint>
#include "testclass.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    //初始化界面
    void initForm();
    //初始化样式表。从QSS文件读取QSS样式
    void initStyleSheet();
    //窗口最大化
    void maximizeForm();

protected:
      bool eventFilter(QObject *obj, QEvent *ev) override;

private slots:

      void on_pushButton_clicked();

      void on_pushButton_8_clicked();

      void on_pushButton_9_clicked();

      void on_pushButton_10_clicked();

      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();

      void on_pushButton_4_clicked();

      void on_pushButton_5_clicked();

      void on_pushButton_6_clicked();

      void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    bool m_bDrag = false;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    TestClass btn;
    QList<TestClass> btns;
    //APP图标路径
    QString appIconPath = "border-image: url(:/icon/icon/youdao.png0);";
    //左侧边栏控件
    QList<QPushButton *> leftBarBtnList;
    //左侧边栏模式。0:文字+图标模式；1：图标模式
    int leftBarMode;
    //左侧边栏名称。
    QStringList leftBarBtnName = {"词典    ","翻译    ","搜论文  ","单词本  ","我的翻译","全部功能"};
    //左侧边栏图标path。
    QStringList leftBarBtnIconPath = {":/icon/icon/enter2.png",
                                      ":/icon/icon/enter2.png",
                                      ":/icon/icon/enter2.png",
                                      ":/icon/icon/enter2.png",
                                      ":/icon/icon/enter2.png",
                                      ":/icon/icon/enter2.png"};
    //左侧边栏切换键图标path。
    QStringList leftBarSwitchBtnIconPath = {":/icon/icon/exit4.png",
                                            ":/icon/icon/enter2.png"};
    //左侧边栏切换键当前图标path。
    QString leftBarSwitchBtnIconPathCurrent;



};
#endif // MAINWINDOW_H
