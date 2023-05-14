
#include <QApplication>
#include "mainwindow.h"
#include "testb.h"



/*参考：https://blog.csdn.net/Jacksqh/article/details/122797904*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TestB testb;
    return a.exec();
}
