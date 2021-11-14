#include "ledform.h"
#include "ui_ledform.h"

#include <QLayout>
#include <QSpacerItem>
#include <QDebug>

LedForm::LedForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LedForm)
{
    ui->setupUi(this);

    //
    // 组、布局
    group = new QGroupBox(parent);
    group->setFixedSize(250, 550);
    group->setStyleSheet("QGroupBox { "
                         "border: 1px solid #C0C0C0;"
                         "background-color: #D8D8D8;"
                         "} ");

    QGridLayout *grid = new QGridLayout(parent);

    group->setLayout(grid);

    layout()->setMargin(50);
    layout()->addWidget(group);

    //
    // 默认大小led
    // 默认如果太大，可以在构造函数中更改
    stepLed00 = new QSimpleLed(parent, QSimpleLed::CUSTOM);

    // 自定义颜色led
    stepLed00->setCustomOnColor0(QColor(0, 255, 255));
    stepLed00->setCustomOnColor1(QColor(0, 191, 191));
    stepLed00->setCustomOffColor0(QColor(0, 28, 28));
    stepLed00->setCustomOffColor1(QColor(0, 128, 128));

    stepLed01 = new QSimpleLed(parent, QSimpleLed::RED);
    stepLed02 = new QSimpleLed(parent, QSimpleLed::GREEN);
    stepLed10 = new QSimpleLed(parent, QSimpleLed::BLUE);
    stepLed11 = new QSimpleLed(parent, QSimpleLed::YELLOW);
    stepLed12 = new QSimpleLed(parent, QSimpleLed::ORANGE);

    grid->addWidget(stepLed00, 0, 0, Qt::AlignCenter);
    grid->addWidget(stepLed01, 0, 1, Qt::AlignCenter);
    grid->addWidget(stepLed02, 1, 0, Qt::AlignCenter);
    grid->addWidget(stepLed10, 1, 1, Qt::AlignCenter);
    grid->addWidget(stepLed11, 2, 0, Qt::AlignCenter);
    grid->addWidget(stepLed12, 2, 1, Qt::AlignCenter);

    //
    // 自定义大小led
    stepLedbig = new QSimpleLed(parent, QSimpleLed::GREEN);
    stepLedbig->setFixedSize(128, 128);

    grid->addWidget(stepLedbig, 3, 0, 2, 2, Qt::AlignCenter);

    //
    // 按钮组
    turn = new QPushButton("Turn on", parent);
    turn->setFixedSize(75, 25);

    connect(turn, &QPushButton::clicked, this, &LedForm::onTurnBtnClicked);

    grid->addWidget(turn, 5, 0, Qt::AlignCenter);

    blink = new QPushButton("Blink", parent);
    blink->setFixedSize(75, 25);

    connect(blink, &QPushButton::clicked, this, &LedForm::onBlinkBtnClicked);

    grid->addWidget(blink, 5, 1, Qt::AlignCenter);

    QSpacerItem *hSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding);
    grid->addItem(hSpacer, 0, 2);
    QSpacerItem *vSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    grid->addItem(vSpacer, 6, 0);
    grid->setSpacing(40);
    grid->setMargin(40);
}

LedForm::~LedForm()
{
    delete ui;
}

void LedForm::onTurnBtnClicked()
{
    stepLed00->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLed01->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLed02->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLed10->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLed11->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLed12->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);
    stepLedbig->setStates(mOn ? QSimpleLed::OFF : QSimpleLed::ON);

    mOn = !mOn;

    turn->setText(mOn ? "Turn off" : "Turn on");
}

void LedForm::onBlinkBtnClicked()
{
    //
    // 延时开启闪烁产生流水效果
    QTimer::singleShot(200/7.0*0, nullptr, [&]() {
        stepLed00->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*1, nullptr, [&]() {
        stepLed01->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*2, nullptr, [&]() {
        stepLed02->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*3, nullptr, [&]() {
        stepLed10->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*4, nullptr, [&]() {
        stepLed11->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*5, nullptr, [&]() {
        stepLed12->setStates(QSimpleLed::BLINK);
    });
    QTimer::singleShot(200/7.0*6, nullptr, [&]() {
        stepLedbig->setStates(QSimpleLed::BLINK);
    });
}

