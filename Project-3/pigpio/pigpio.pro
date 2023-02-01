TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    ambient.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ambient.h

unix:!macx: LIBS += -L$$PWD/../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/74-r0/image/usr/lib/ -lpigpio

INCLUDEPATH += $$PWD/../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/74-r0/image/usr/include
DEPENDPATH += $$PWD/../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/74-r0/image/usr/include
