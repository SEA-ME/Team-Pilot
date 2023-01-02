#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ambient.h"
#include "cantransceiver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *item = engine.rootObjects().first();
    Ambient ambient;
    CanTransceiver canTransceiver;
    canTransceiver.initSocket("can0");
    canTransceiver.initVsomeipClient();

    QObject::connect(item, SIGNAL(prndSignal(int)),
                     &ambient, SLOT(ambientSlot(int)));
    QObject::connect(item, SIGNAL(prndSignal(int)),
                     &canTransceiver, SLOT(canSlot(int)));

    canTransceiver.startCommunicate();

    return app.exec();
}
