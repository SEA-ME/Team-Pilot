DESCRIPTION = "Commonapi dbus client application"

LICENSE = "CLOSED"
inherit cmake
DEPENDS = " common-api-c++ common-api-c++-dbus dbus"

  
SRC_URI += "file://src/IpcClient.cpp \
            file://src/IpcService.cpp \
            file://src/IpcStubImpl.cpp \
            file://src/IpcStubImpl.hpp \
            file://src/defs.h \
            file://src/ina219.c \
            file://src/ina219.h \
            file://src-gen/v1/commonapi/IpcDBusDeployment.cpp \
            file://src-gen/v1/commonapi/IpcDBusDeployment.hpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.cpp \
            file://src-gen/v1/commonapi/IpcDBusProxy.hpp \
            file://src-gen/v1/commonapi/Ipc.hpp \
            file://src-gen/v1/commonapi/IpcProxy.hpp \
            file://src-gen/v1/commonapi/IpcProxyBase.hpp \
            file://src-gen/v1/commonapi/IpcStub.hpp \
            file://src-gen/v1/commonapi/IpcStubDefault.hpp \
            file://src-gen/v1/commonapi/IpcDBusStubAdapter.cpp \
            file://src-gen/v1/commonapi/IpcDBusStubAdapter.hpp \
            file://CMakeLists.txt"
S = "${WORKDIR}"


do_install(){
    install -d ${D}${bindir}
    install -m 0755 IpcClient ${D}${bindir}
    install -m 0755 IpcService ${D}${bindir}
}

do_package_qa[noexec] = "1"
