#include "cbusiness.h"
#include <QDebug>

CBusiness::CBusiness(QObject *parent) : QObject(parent), m_strValue(""), m_intValue(0)
{
}


void CBusiness::sendSignal()
{
    qDebug() << "CBusiness::" << __FUNCTION__;
    emit signal1();
    emit signal2(m_strValue, m_intValue);
}

void CBusiness::setStrValue(QString strValue)
{
    qDebug() << "CBusiness::" << __FUNCTION__ << strValue;
    m_strValue = strValue;
    emit strValueChanged(strValue);
    qDebug()<< "CBusiness::" << "emit strValueChanged" << endl;
}

QString CBusiness::getStrValue() const
{
    qDebug() << "CBusiness::" << __FUNCTION__;
    return m_strValue;
}

void CBusiness::setIntValue(int intValue)
{
    qDebug() << "CBusiness::" << __FUNCTION__;
    m_intValue = intValue;
    emit intValueChanged(intValue);
    qDebug()<< "CBusiness::" << "emit intValueChanged";
}


int CBusiness::getIntValue() const
{
    qDebug() << "CBusiness::" << __FUNCTION__;
    return m_intValue;
}

void CBusiness::slot1()
{
    qDebug() << "CBusiness::" << __FUNCTION__;
}

void CBusiness::slot2(QString strValue, int intValue)
{
    qDebug() << "CBusiness::" << __FUNCTION__;
    qDebug() << "CBusiness:: " << strValue << "  " << intValue;
}
