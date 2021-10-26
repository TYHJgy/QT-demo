#include "codeuiform.h"
#include "ui_codeuiform.h"

#include <QPushButton>

CodeUiForm::CodeUiForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeUiForm)
{
    ui->setupUi(this);
    this->resize(1000, 600);
    this->setAttribute(Qt::WA_DeleteOnClose);//窗口关闭之后，释放资源
//    this->setWindowTitle("数据分析");
    QPushButton * pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(25, 25, 200, 200));
    pushButton->setText("testbutton");

}

CodeUiForm::~CodeUiForm()
{
    qDebug() << "this is ~CodeUiForm()";
    delete ui;
}
