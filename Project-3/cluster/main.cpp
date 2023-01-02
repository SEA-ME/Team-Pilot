#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "vsomedata.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    qmlRegisterType<VsomeData>("vdata",0,0,"VsomeData");
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
