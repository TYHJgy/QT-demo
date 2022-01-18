#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QDebug>

#include "mainwindow.h"

class TestClass : public QPushButton
{
public:
    TestClass(MainWindow *p);
    ~TestClass();
};

#endif // TESTCLASS_H
