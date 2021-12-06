#include "fileoperationform.h"
#include "ui_fileoperationform.h"

FileOperationForm::FileOperationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileOperationForm)
{
    ui->setupUi(this);
}

FileOperationForm::~FileOperationForm()
{
    delete ui;
}

//新建文件
void FileOperationForm::on_newFile_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/",
                                                         QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QFile file(path + "/out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";
    file.close();
}

//读文件内容
void FileOperationForm::on_readData_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "/", tr("txt Files (*.txt)"));
    qDebug() << fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "open failed";
        return;
    }
    qDebug() << file.atEnd();
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        qDebug() << line;
        ui->dataEdit->insertPlainText(line);//在当前光标位置插入文本
    }
    file.close();
}

//删除文件
void FileOperationForm::on_removeFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "/", tr("txt Files (*.txt)"));
    qDebug() << fileName;
    QFile file(fileName);
    qDebug() << "文件存在" << file.exists();
    file.remove();
    qDebug() << "文件存在" << file.exists();
}
