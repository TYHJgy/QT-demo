#include "styledemoform.h"
#include "ui_styledemoform.h"

#include <QStyleFactory>

StyleDemoForm::StyleDemoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StyleDemoForm)
{
    ui->setupUi(this);
    //将黄色设置为应用程序中所有qlineedit的背景色
//    setStyleSheet("QLineEdit { background-color: yellow }");
    //指定名称改变样式
//    setStyleSheet("QLineEdit#lineEdit { background-color: yellow }");
    //直接使用控件的setStyleSheet
//    ui->lineEdit->setStyleSheet("color: blue;"
//                            "background-color: yellow;"
//                            "selection-color: yellow;"
//                            "selection-background-color: blue;");
    //使用动态属性自定义样式
    ui->lineEdit->setProperty("mandatoryField", true);
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "background-color: red;"
                                  "border-style: outset;"
                                  "border-width: 2px;"
                                  "border-radius: 10px;"
                                  "border-color: beige;"
                                  "font: bold 14px;"
                                  "min-width: 10em;"
                                  "padding: 6px;}");

}

StyleDemoForm::~StyleDemoForm()
{
    delete ui;
}

void StyleDemoForm::on_comboBox_activated(const QString &arg1)
{
    QApplication::setStyle(QStyleFactory::create(arg1));
}
