#include "streamwriteread.h"

StreamWriteRead::StreamWriteRead()
{

}

void StreamWriteRead::newFile(const QString pathName)
{
    QFile file(pathName);
    //打开文件（如果没有该文件，会新建一个）
    if (!file.open(QIODevice::ReadWrite))
        return;
    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("bookmark");
    stream.writeAttribute("href", "http://qt-project.org/");
    stream.writeTextElement("title", "Qt Project");
    stream.writeEndElement(); // bookmark
    stream.writeEndDocument();
    file.close();
}

void StreamWriteRead::deleteFile(const QString pathName)
{
    QFile file(pathName);
    file.remove();
}

void StreamWriteRead::readFile(const QString pathName)
{
    QFile file(pathName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    file.reset();

    QXmlStreamReader xml(&file);
    while (!xml.atEnd()) {
        QXmlStreamReader::TokenType tokenType = xml.readNext();
        qDebug() <<"------------------";
        qDebug() <<"tokenType:"<<tokenType;
        qDebug() <<"name:"<<xml.name();
        qDebug() <<"text:"<<xml.text();
        for(int i=0;i<xml.attributes().count();i++){
            qDebug() <<"attributes" << i << ":" <<xml.attributes().at(i).name();
            qDebug() <<"attributes" << i << ":" <<xml.attributes().at(i).value();
        }
    }
    if (xml.hasError()) {
        qDebug() << "xml.hasError()";
    }
    file.close();
}
