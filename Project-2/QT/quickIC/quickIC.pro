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
_ROOT = $$_PRO_FILE_PWD_ #.pro .pro 파일이 있는 위치
INCLUDEPATH += ../project-fidl-gen-test/src-gen/ #자신의 프로젝트에서 풀경로로 안해도 경로를 찾아 줄수 있도록 추가하는 부분

SOURCES += \
        main.cpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusDeployment.cpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusProxy.cpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusStubAdapter.cpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcStubDefault.cpp \
    datacontroller.cpp \
    ipcstubimpl.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lCommonAPI-DBus

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../commonapi/capicxx-dbus-runtime/build/ -lCommonAPI-DBus

INCLUDEPATH += $$PWD/../commonapi/capicxx-dbus-runtime/include
DEPENDPATH += $$PWD/../commonapi/capicxx-dbus-runtime/include

unix:!macx: LIBS += -L$$PWD/../commonapi/dbus-1.10.10/dbus/.libs/ -ldbus-1

INCLUDEPATH += $$PWD/../commonapi/dbus-1.10.10
DEPENDPATH += $$PWD/../commonapi/dbus-1.10.10

HEADERS += \
    ../project-fidl-gen-test/src-gen/v1/commonapi/Ipc.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusDeployment.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusProxy.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcDBusStubAdapter.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcProxy.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcProxyBase.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcStub.hpp \
    ../project-fidl-gen-test/src-gen/v1/commonapi/IpcStubDefault.hpp \
    datacontroller.h \
    ipcstubimpl.h
