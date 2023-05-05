
#include <QApplication>
#include "mainwindow.h"



/*参考：https://blog.csdn.net/Jacksqh/article/details/122797904*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();
//    SysTray sw;
//    sw.show();
    return a.exec();
}
