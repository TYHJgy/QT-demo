#include "testclass.h"

TestClass::TestClass(MainWindow *p)
{
    setParent(p);
}

TestClass::~TestClass()
{

    qDebug()<< "~TestClass";
}
