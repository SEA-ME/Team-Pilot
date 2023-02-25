#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "canclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);

    CANClient canClient;
    canClient.initVsomeipClient();
    canClient.startCommunication();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("canData", &canClient);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
