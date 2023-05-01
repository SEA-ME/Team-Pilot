#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datacontroller.h"
#include "ambient.h"
#include "beep.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DataController>("data",0,0,"DataController");
//    DataController data;
    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("datacontroller",&data);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *item = engine.rootObjects().first();
    QObject *childObj = item->findChild<QObject *>("headunitObj");
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
