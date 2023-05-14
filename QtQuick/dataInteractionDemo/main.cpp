#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cbusiness.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //qmlRegisterType注册C++类型至QML
    //arg1:import时模块名
    //arg2:主版本号
    //arg3:次版本号
    //arg4:QML类型名
    qmlRegisterType<CBusiness>("WorkClass", 1, 0, "CBusiness");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
