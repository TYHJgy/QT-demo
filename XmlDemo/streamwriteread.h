#ifndef STREAMWRITEREAD_H
#define STREAMWRITEREAD_H

#include <QString>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>


class StreamWriteRead
{
public:
    StreamWriteRead();

    void newFile(const QString pathName);
    void deleteFile(const QString pathName);
    void readFile(const QString pathName);

};

#endif // STREAMWRITEREAD_H
