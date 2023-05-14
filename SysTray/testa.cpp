#include "testa.h"

TestA::TestA()
{
    qDebug() << "TestA()";
}

TestA::TestA(QString str)
{

    qDebug() << "TestA()"<<str;
}
