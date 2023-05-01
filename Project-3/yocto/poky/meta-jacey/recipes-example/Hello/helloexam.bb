DESCRIPTION = "Commonapi dbus client application"

LICENSE = "CLOSED"
inherit cmake
DEPENDS = " common-api-c++ common-api-c++-dbus dbus"

#RDEPENDS:${PN} = "commonapi3 common-api-c++ common-api-c++-dbus dbus"
  
SRC_URI += "file://src/HelloWorldClient.cpp \
            file://src/HelloWorldService.cpp \
            file://src/HelloWorldStubImpl.cpp \
            file://src/HelloWorldStubImpl.hpp \
            file://src-gen/v1/commonapi/HelloWorldDBusDeployment.cpp \
            file://src-gen/v1/commonapi/HelloWorldDBusDeployment.hpp \
            file://src-gen/v1/commonapi/HelloWorldDBusProxy.cpp \
            file://src-gen/v1/commonapi/HelloWorldDBusProxy.hpp \
            file://src-gen/v1/commonapi/HelloWorld.hpp \
            file://src-gen/v1/commonapi/HelloWorldProxy.hpp \
            file://src-gen/v1/commonapi/HelloWorldProxyBase.hpp \
            file://src-gen/v1/commonapi/HelloWorldStub.hpp \
            file://src-gen/v1/commonapi/HelloWorldStubDefault.hpp \
            file://src-gen/v1/commonapi/HelloWorldDBusStubAdapter.cpp \
            file://src-gen/v1/commonapi/HelloWorldDBusStubAdapter.hpp \
            file://CMakeLists.txt"
S = "${WORKDIR}"


do_install(){
    install -d ${D}${bindir}
    install -m 0755 HelloWorldClient ${D}${bindir}
    install -m 0755 HelloWorldService ${D}${bindir}
}

do_package_qa[noexec] = "1"
