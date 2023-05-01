TEMPLATE = app

QT += qml quick
CONFIG += c++11
_ROOT = $$_PRO_FILE_PWD_
INCLUDEPATH += src-gen/

SOURCES += main.cpp \
    src-gen/v1/commonapi/IpcDBusDeployment.cpp \
    src-gen/v1/commonapi/IpcDBusProxy.cpp \
    src-gen/v1/commonapi/IpcDBusStubAdapter.cpp \
    datacontroller.cpp \
    ipcstubimpl.cpp \
    ambient.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src-gen/v1/commonapi/Ipc.hpp \
    src-gen/v1/commonapi/IpcDBusDeployment.hpp \
    src-gen/v1/commonapi/IpcDBusProxy.hpp \
    src-gen/v1/commonapi/IpcProxy.hpp \
    src-gen/v1/commonapi/IpcProxyBase.hpp \
    src-gen/v1/commonapi/IpcStub.hpp \
    src-gen/v1/commonapi/IpcStubDefault.hpp \
    src-gen/v1/commonapi/IpcDBusStubAdapter.hpp \
    datacontroller.h \
    ipcstubimpl.h \
    ambient.h

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/build/ -lCommonAPI

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/build/ -lCommonAPI-DBus

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/build/dbus/ -ldbus-1

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/lib/ -lEGL

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include

unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/79-r0/git/ -lpigpio

INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/79-r0/git
DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/pigpio/79-r0/git


DISTFILES += \
    Background.qml \
    PRND.qml

