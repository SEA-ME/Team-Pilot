#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "beep.h"
#include "ambient.h"
#include "canclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject *item = engine.rootObjects().first();
    QObject *childObj = item->findChild<QObject *>("headunitObj");

    CANClient canClient;
    canClient.initVsomeipClient();
    canClient.startCommunication();
    Beep beep;
    Ambient ambient;

    if (childObj) {
        QObject::connect(childObj, SIGNAL(prndSignal(int)),
                         &ambient, SLOT(ambientSlot(int)));
        QObject::connect(childObj, SIGNAL(prndSignal(int)),
                         &beep, SLOT(ultrasonicBeepSlot(int)));
    } else {
        std::cout << "cannot read qml object" << std::endl;
    }


    return app.exec();
}
