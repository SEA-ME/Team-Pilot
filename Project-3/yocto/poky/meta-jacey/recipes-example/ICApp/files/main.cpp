#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datacontroller.h"
#include "ambient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DataController>("data",0,0,"DataController");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *item = engine.rootObjects().first();
    Ambient ambient;

    QObject::connect(item, SIGNAL(prndSignal(int)),
                    &ambient, SLOT(ambientSlot(int)));
    return app.exec();
}
