TEMPLATE = app

QT += qml quick
CONFIG += c++11
INCLUDEPATH += src-gen/

SOURCES += main.cpp \
    src-gen/v1/commonapi/IpcDBusDeployment.cpp \
    src-gen/v1/commonapi/IpcDBusProxy.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/build/ -lCommonAPI

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/build/ -lCommonAPI-DBus

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/build/dbus/ -ldbus-1

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0


HEADERS += \
    src-gen/v1/commonapi/Ipc.hpp \
    src-gen/v1/commonapi/IpcDBusDeployment.hpp \
    src-gen/v1/commonapi/IpcDBusProxy.hpp \
    src-gen/v1/commonapi/IpcProxy.hpp \
    src-gen/v1/commonapi/IpcProxyBase.hpp \
    src-gen/v1/commonapi/IpcStub.hpp \
    src-gen/v1/commonapi/IpcStubDefault.hpp

