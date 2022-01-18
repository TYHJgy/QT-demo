#include "myclass.h"


MyClass::MyClass(MainWindow *parent)
{
    setParent(parent);
}


MyClass::~MyClass()
{
    qDebug()<< "~MyClass";

}

