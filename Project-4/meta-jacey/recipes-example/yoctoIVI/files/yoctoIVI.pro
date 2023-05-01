TEMPLATE = app

QT += qml quick gui
CONFIG += c++11
_ROOT = $$_PRO_FILE_PWD_
INCLUDEPATH += src-gen/

SOURCES += main.cpp \
    beep.cpp \
    src-gen/v1/commonapi/IpcDBusDeployment.cpp \
    src-gen/v1/commonapi/IpcDBusProxy.cpp \
    src-gen/v1/commonapi/IpcDBusStubAdapter.cpp \
    datacontroller.cpp \
    ipcstubimpl.cpp \
    ambient.cpp \
    src-gen/v1/wiringPi/ads1115.c \
    src-gen/v1/wiringPi/bmp180.c \
    src-gen/v1/wiringPi/drcNet.c \
    src-gen/v1/wiringPi/drcSerial.c \
    src-gen/v1/wiringPi/ds18b20.c \
    src-gen/v1/wiringPi/htu21d.c \
    src-gen/v1/wiringPi/max31855.c \
    src-gen/v1/wiringPi/max5322.c \
    src-gen/v1/wiringPi/mcp23008.c \
    src-gen/v1/wiringPi/mcp23016.c \
    src-gen/v1/wiringPi/mcp23017.c \
    src-gen/v1/wiringPi/mcp23s08.c \
    src-gen/v1/wiringPi/mcp23s17.c \
    src-gen/v1/wiringPi/mcp3002.c \
    src-gen/v1/wiringPi/mcp3004.c \
    src-gen/v1/wiringPi/mcp3422.c \
    src-gen/v1/wiringPi/mcp4802.c \
    src-gen/v1/wiringPi/pcf8574.c \
    src-gen/v1/wiringPi/pcf8591.c \
    src-gen/v1/wiringPi/piHiPri.c \
    src-gen/v1/wiringPi/piThread.c \
    src-gen/v1/wiringPi/pseudoPins.c \
    src-gen/v1/wiringPi/rht03.c \
    src-gen/v1/wiringPi/sn3218.c \
    src-gen/v1/wiringPi/softPwm.c \
    src-gen/v1/wiringPi/softServo.c \
    src-gen/v1/wiringPi/softTone.c \
    src-gen/v1/wiringPi/sr595.c \
    src-gen/v1/wiringPi/wiringPi.c \
    src-gen/v1/wiringPi/wiringPiI2C.c \
    src-gen/v1/wiringPi/wiringPiSPI.c \
    src-gen/v1/wiringPi/wiringSerial.c \
    src-gen/v1/wiringPi/wiringShift.c \
    src-gen/v1/wiringPi/wpiExtensions.c


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    beep.h \
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
    ambient.h \
    src-gen/v1/wiringPi/ads1115.h \
    src-gen/v1/wiringPi/bmp180.h \
    src-gen/v1/wiringPi/drcNet.h \
    src-gen/v1/wiringPi/drcNetCmd.h \
    src-gen/v1/wiringPi/drcSerial.h \
    src-gen/v1/wiringPi/ds18b20.h \
    src-gen/v1/wiringPi/htu21d.h \
    src-gen/v1/wiringPi/max31855.h \
    src-gen/v1/wiringPi/max5322.h \
    src-gen/v1/wiringPi/mcp23008.h \
    src-gen/v1/wiringPi/mcp23016.h \
    src-gen/v1/wiringPi/mcp23016reg.h \
    src-gen/v1/wiringPi/mcp23017.h \
    src-gen/v1/wiringPi/mcp23s08.h \
    src-gen/v1/wiringPi/mcp23s17.h \
    src-gen/v1/wiringPi/mcp23x08.h \
    src-gen/v1/wiringPi/mcp23x0817.h \
    src-gen/v1/wiringPi/mcp3002.h \
    src-gen/v1/wiringPi/mcp3004.h \
    src-gen/v1/wiringPi/mcp3422.h \
    src-gen/v1/wiringPi/mcp4802.h \
    src-gen/v1/wiringPi/pcf8574.h \
    src-gen/v1/wiringPi/pcf8591.h \
    src-gen/v1/wiringPi/pseudoPins.h \
    src-gen/v1/wiringPi/rht03.h \
    src-gen/v1/wiringPi/sn3218.h \
    src-gen/v1/wiringPi/softPwm.h \
    src-gen/v1/wiringPi/softServo.h \
    src-gen/v1/wiringPi/softTone.h \
    src-gen/v1/wiringPi/sr595.h \
    src-gen/v1/wiringPi/version.h \
    src-gen/v1/wiringPi/wiringPi.h \
    src-gen/v1/wiringPi/wiringPiI2C.h \
    src-gen/v1/wiringPi/wiringPiSPI.h \
    src-gen/v1/wiringPi/wiringSerial.h \
    src-gen/v1/wiringPi/wiringShift.h \
    src-gen/v1/wiringPi/wpiExtensions.h \
    wiringPi.h


    unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/build/ -lCommonAPI

    INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include
    DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/git/include

    unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/build/ -lCommonAPI-DBus

    INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include
    DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-dbus/3.2.0-r0/git/include

    unix:!macx: LIBS += -L$$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/build/dbus/ -ldbus-1

    INCLUDEPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0
    DEPENDPATH += $$/home/seame-two/yocto/poky/build/tmp/work/cortexa72-poky-linux/dbus/1.14.0-r0/dbus-1.14.0


DISTFILES += \
    Background.qml \
    PRND.qml \
    src-gen/v1/wiringPi/COPYING.LESSER \
    src-gen/v1/wiringPi/noMoreStatic



unix:!macx: LIBS += -L$$PWD/../../../../build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/lib/ -lGLESv2

INCLUDEPATH += $$PWD/../../../../build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include
DEPENDPATH += $$PWD/../../../../build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include



unix:!macx: LIBS += -L$$PWD/../../../../build/tmp/work/cortexa72-poky-linux/libxcrypt/4.4.30-r0/image/usr/lib/ -lcrypt

INCLUDEPATH += $$PWD/../../../../build/tmp/work/cortexa72-poky-linux/libxcrypt/4.4.30-r0/image/usr/include
DEPENDPATH += $$PWD/../../../../build/tmp/work/cortexa72-poky-linux/libxcrypt/4.4.30-r0/image/usr/include
