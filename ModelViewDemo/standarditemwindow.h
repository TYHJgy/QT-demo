#ifndef STANDARDITEMWINDOW_H
#define STANDARDITEMWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>


#define FixedColumnCount 6 //文件固定6列
#define FixedRowCount 6//文件固定6行

namespace Ui {
class StandardItemWindow;
}

class StandardItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StandardItemWindow(QWidget *parent = nullptr);
    ~StandardItemWindow();

private:
    Ui::StandardItemWindow *ui;

    QLabel  *LabCurFile;              //当前文件
    QLabel  *LabCellPos;              //当前单元格行列号
    QLabel  *LabCellText;             //当前单元格内容
    QStandardItemModel  *theModel;    //数据模型
    QItemSelectionModel *theSelection;//选择模型
    void iniModelFromStringList(QStringList&);//从StringList初始化数据模型
    void insertRow(int row, const QList<QStandardItem *> &items);
    void setTextAlignment(Qt::Alignment atextAlignment);
private slots:
    //当前选择单元格发生变化
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpen_triggered();
    void on_actAppend_triggered();
    void on_actSave_triggered();
    void on_actModelData_triggered();
    void on_actInsert_triggered();
    void on_actDelete_triggered();
    void on_actAlignLeft_triggered();
    void on_actAlignCenter_triggered();
    void on_actAlignRight_triggered();
    void on_actFontBold_triggered();
    void on_actExit_triggered();
};

#endif // STANDARDITEMWINDOW_H
