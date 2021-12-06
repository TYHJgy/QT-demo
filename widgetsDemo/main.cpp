﻿#include "mainwindow.h"
#include "dialoglogin.h"

#include <QApplication>

//main分支
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
       MainWindow w;
       w.show();
       return a.exec();
    }
    return 0;
}
