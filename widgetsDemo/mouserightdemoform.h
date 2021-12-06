#ifndef MOUSERIGHTDEMOFORM_H
#define MOUSERIGHTDEMOFORM_H

#include <QMainWindow>

namespace Ui {
class MouseRightDemoForm;
}

class MouseRightDemoForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MouseRightDemoForm(QWidget *parent = nullptr);
    ~MouseRightDemoForm();

private slots:
    void on_MouseRightDemoForm_customContextMenuRequested(const QPoint &pos);
    void onTaskBoxContextMenuEvent();

private:
    Ui::MouseRightDemoForm *ui;

};

#endif // MOUSERIGHTDEMOFORM_H
