QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    canstubimpl.cpp \
    vsomedata.cpp \
    ../src-gen/v1/commonapi/CANSomeIPDeployment.cpp \
    ../src-gen/v1/commonapi/CANSomeIPProxy.cpp \
    ../src-gen/v1/commonapi/CANSomeIPStubAdapter.cpp

RESOURCES += qml.qrc
INCLUDEPATH += ../src-gen/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    canstubimpl.h \
    vsomedata.h \
    ../src-gen/v1/commonapi/CAN.hpp \
    ../src-gen/v1/commonapi/CANProxy.hpp \
    ../src-gen/v1/commonapi/CANProxyBase.hpp \
    ../src-gen/v1/commonapi/CANSomeIPDeployment.hpp \
    ../src-gen/v1/commonapi/CANSomeIPProxy.hpp \
    ../src-gen/v1/commonapi/CANSomeIPStubAdapter.hpp \
    ../src-gen/v1/commonapi/CANStub.hpp \
    ../src-gen/v1/commonapi/CANStubDefault.hpp


DISTFILES += \
    Background.qml \
    Instrument_Cluster.qml \
    main.qml

#unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

#INCLUDEPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include
#DEPENDPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include

#unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

#INCLUDEPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include
#DEPENDPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include

#unix:!macx: LIBS += -L$$PWD/../build-commonapi/vsomeip/build/ -lvsomeip3

#INCLUDEPATH += $$PWD/../build-commonapi/vsomeip/interface
#DEPENDPATH += $$PWD/../build-commonapi/vsomeip/interface

unix:!macx: LIBS += -L$$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/image/usr/lib/ -lCommonAPI

INCLUDEPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/image/usr/include/CommonAPI-3.2
DEPENDPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++/3.2.0-r0/image/usr/include/CommonAPI-3.2

unix:!macx: LIBS += -L$$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-someip/3.2.0-r0/image/usr/lib/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-someip/3.2.0-r0/image/usr/include/CommonAPI-3.2
DEPENDPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/common-api-c++-someip/3.2.0-r0/image/usr/include/CommonAPI-3.2

unix:!macx: LIBS += -L$$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/vsomeip/3.1.20.3-r0/image/usr/lib/ -lvsomeip3

INCLUDEPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/vsomeip/3.1.20.3-r0/image/usr/include/vsomeip
DEPENDPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/vsomeip/3.1.20.3-r0/image/usr/include/vsomeip

unix:!macx: LIBS += -L$$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/lib/ -lEGL

INCLUDEPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include
DEPENDPATH += $$PWD/../../../../yocto/poky/build/tmp/work/cortexa72-poky-linux/mesa/2_22.0.3-r0/image/usr/include
