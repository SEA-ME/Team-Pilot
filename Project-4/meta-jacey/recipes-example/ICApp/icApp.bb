DESCRIPTION = "QT application"

LICENSE = "CLOSED"
inherit qmake5
DEPENDS = " qtbase qtquickcontrols2 common-api-c++ common-api-c++-dbus dbus pigpio"

  
SRC_URI += "file://quickIC1.pro \
            file://qml.qrc \
            file://main.cpp \
            file://ipcstubimpl.h \
            file://ipcstubimpl.cpp \
            file://datacontroller.h \
            file://datacontroller.cpp \
            file://ambient.cpp \
            file://ambient.h \
            file://PRND.qml \
            file://main.qml \
            file://InstrumentCluster.qml \
            file://Background.qml \
            file://Prnd.qml \
            file://Cluster.qml \
            file://Dial.qml \
            file://Fuel.qml \
            file://Label.qml \
            file://LeftDial.qml \
            file://RightDial.qml \
            file://Top.qml \
            file://PDC.qml \
            file://src-gen/v1/commonapi/IpcDBusDeployment.cpp \
            file://src-gen/v1/commonapi/IpcDBusDeployment.hpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.cpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.hpp \
            file://src-gen/v1/commonapi/Ipc.hpp \
            file://src-gen/v1/commonapi/IpcProxy.hpp \
            file://src-gen/v1/commonapi/IpcProxyBase.hpp \
            file://src-gen/v1/commonapi/IpcStub.hpp \
            file://src-gen/v1/commonapi/IpcStubDefault.hpp \
            file://images"
S = "${WORKDIR}"

do_configure() {

    qmake ${S}/quickIC1.pro
}


do_install(){
    install -d ${D}${bindir}
    install -m 0755 quickIC1 ${D}${bindir}
}
