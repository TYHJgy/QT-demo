#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include "mainwindow.h"


class MyClass : public QObject
{
    Q_OBJECT
public:
//    explicit MyClass(QObject *parent = nullptr);
    MyClass(MainWindow *parent = nullptr);
    ~MyClass();
signals:

};

#endif // MYCLASS_H
