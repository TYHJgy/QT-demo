#include <QCoreApplication>
#include <iostream>
#include "test1.h"
#include "test2.h"
#include "test3.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test1 test;
    Test2 test2;
    Test3 test3;
    cout << "main" << endl;
    test.myprint();
    return a.exec();
}
