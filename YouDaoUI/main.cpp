#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug()<<"--1--";
    int i = a.exec();
    qDebug()<<"--2--"<<i;
    return i;
}