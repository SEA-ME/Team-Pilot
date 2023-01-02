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
    vsomedata.cpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPDeployment.cpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPProxy.cpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPStubAdapter.cpp \
    headunitstubimpl.cpp

RESOURCES += qml.qrc
INCLUDEPATH += ../src-gen-headunit/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    vsomedata.h \
    ../src-gen-headunit/v1/commonapi/HeadUnit.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitProxy.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitProxyBase.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPDeployment.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPProxy.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitSomeIPStubAdapter.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitStub.hpp \
    ../src-gen-headunit/v1/commonapi/HeadUnitStubDefault.hpp \
    headunitstubimpl.h


DISTFILES += \
    Background.qml \
    Instrument_Cluster.qml \
    main.qml


unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/vsomeip/build/ -lvsomeip3

INCLUDEPATH += $$PWD/../build-commonapi/vsomeip/interface
DEPENDPATH += $$PWD/../build-commonapi/vsomeip/interface
