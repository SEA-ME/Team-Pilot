DESCRIPTION = "QT application"

LICENSE = "CLOSED"
inherit qmake5
DEPENDS = " qtbase qtquickcontrols2 common-api-c++ common-api-c++-dbus dbus"

  
SRC_URI += "file://simple.pro \
            file://qml.qrc \
            file://main.cpp \
            file://main.qml \
            file://simple.pro.user \
            file://MainForm.ui.qml \
            file://deployment.pri \
            file://src-gen/v1/commonapi/IpcDBusDeployment.cpp \
            file://src-gen/v1/commonapi/IpcDBusDeployment.hpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.cpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.hpp \
            file://src-gen/v1/commonapi/Ipc.hpp \
            file://src-gen/v1/commonapi/IpcProxy.hpp \
            file://src-gen/v1/commonapi/IpcProxyBase.hpp \
            file://src-gen/v1/commonapi/IpcStub.hpp \
            file://src-gen/v1/commonapi/IpcStubDefault.hpp"
S = "${WORKDIR}"

do_configure() {

    qmake ${S}/simple.pro
}


do_install(){
    install -d ${D}${bindir}
    install -m 0755 simple ${D}${bindir}
}
