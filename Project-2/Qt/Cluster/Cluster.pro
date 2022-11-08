TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    vsomedata.cpp \
    canstubimpl.cpp \
    ../src-gen/v1/commonapi/CANSomeIPDeployment.cpp \
    ../src-gen/v1/commonapi/CANSomeIPProxy.cpp \
    ../src-gen/v1/commonapi/CANSomeIPStubAdapter.cpp \
    ../src-gen/v1/commonapi/CANStubDefault.cpp

RESOURCES += qml.qrc
_ROOT = $$_PRO_FILE_PWD_
INCLUDEPATH += ../ic/src-gen/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    vsomedata.h \
    canstubimpl.h \
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
    Instrument_Cluster.qml

unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/vsomeip/build/ -lvsomeip

INCLUDEPATH += $$PWD/../build-commonapi/vsomeip/interface
DEPENDPATH += $$PWD/../build-commonapi/vsomeip/interface
