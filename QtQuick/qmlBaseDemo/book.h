#ifndef BOOK_H
#define BOOK_H

#include <QObject>

class Book : public QObject
{
    Q_OBJECT
public:
    explicit Book(QObject *parent = nullptr);

signals:

};

#endif // BOOK_H
