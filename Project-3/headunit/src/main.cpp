#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "ambient.h"
#include "canclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);

    CANClient canClient;
    canClient.initVsomeipClient();
    canClient.startCommunication();
    Ambient ambient;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("canData", &canClient);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject *item = engine.rootObjects().first();
    QObject *childObj = item->findChild<QObject *>("headunitObj");

    if (childObj) {
        QObject::connect(childObj, SIGNAL(prndSignal(int)),
                         &ambient, SLOT(ambientSlot(int)));
    } else {
        std::cout << "cannot read qml object" << std::endl;
    }

    return app.exec();
}
