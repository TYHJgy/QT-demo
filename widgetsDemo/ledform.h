#ifndef LedForm_H
#define LedForm_H

#include <QWidget>
#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>

#include "qsimpleled.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LedForm; }
QT_END_NAMESPACE

class LedForm : public QMainWindow
{
    Q_OBJECT

public:
    LedForm(QWidget *parent = nullptr);
    ~LedForm();

private:
    Ui::LedForm *ui;

    QGroupBox *group = nullptr;

    QSimpleLed *stepLed00 = nullptr;
    QSimpleLed *stepLed01 = nullptr;
    QSimpleLed *stepLed02 = nullptr;
    QSimpleLed *stepLed10 = nullptr;
    QSimpleLed *stepLed11 = nullptr;
    QSimpleLed *stepLed12 = nullptr;
    QSimpleLed *stepLedbig = nullptr;

    QPushButton *turn;
    QPushButton *blink;

    bool mOn = false;

public slots:
    void onTurnBtnClicked();
    void onBlinkBtnClicked();
};
#endif // LedForm_H
