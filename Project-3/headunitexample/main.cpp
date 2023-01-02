#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ambient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *item = engine.rootObjects().first();
    Ambient ambient;
    QObject::connect(item, SIGNAL(prndSignal(QString)),
                     &ambient, SLOT(ambientSlot(QString)));

    return app.exec();
}
