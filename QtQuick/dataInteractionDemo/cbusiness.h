#ifndef CBUSINESS_H
#define CBUSINESS_H

#include <QObject>

class CBusiness : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString strValue READ getStrValue WRITE setStrValue NOTIFY strValueChanged)
    Q_PROPERTY(int intValue READ getIntValue WRITE setIntValue NOTIFY intValueChanged)
public:
    explicit CBusiness(QObject *parent = 0);
    Q_INVOKABLE void sendSignal();

    void setStrValue(QString strValue);
    QString getStrValue() const;
    void setIntValue(int intValue);
    int getIntValue() const;

signals:
    void signal1();
    void signal2(QString strValue, int intValue);
    void strValueChanged(QString strValue);
    void intValueChanged(int intValue);

public slots:
    void slot1();
    void slot2(QString strValue, int intValue);

private:
    //类的属性
    QString m_strValue;
    int m_intValue;
};

#endif // CBUSINESS_H
