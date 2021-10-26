#ifndef CODEUIFORM_H
#define CODEUIFORM_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class CodeUiForm;
}

class CodeUiForm : public QWidget
{
    Q_OBJECT

public:
    //如果parent为nullptr，则新小部件将成为一个窗口。
    //如果parent是另一个小部件，则该小部件将成为parent中的子窗口。
    //当父小部件被删除时，新小部件也被删除。
    explicit CodeUiForm(QWidget *parent = nullptr);
    ~CodeUiForm();

private:
    Ui::CodeUiForm *ui;
};

#endif // CODEUIFORM_H
