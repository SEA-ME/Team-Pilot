DESCRIPTION = "QT application"

LICENSE = "CLOSED"
inherit qmake5
DEPENDS = " qtbase qtquickcontrols2 common-api-c++ common-api-c++-dbus dbus"

  
SRC_URI += "file://yoctoIVI.pro \
            file://qml.qrc \
            file://main.cpp \
            file://ipcstubimpl.h \
            file://ipcstubimpl.cpp \
            file://datacontroller.h \
            file://datacontroller.cpp \
            file://ambient.cpp \
            file://ambient.h \
            file://beep.cpp \
            file://beep.h \
            file://wiringPi.h \
            file://main.qml \
            file://IC \
            file://HU \
            file://src-gen"
S = "${WORKDIR}"

do_configure() {

    qmake ${S}/yoctoIVI.pro
}


do_install(){
    install -d ${D}${bindir}
    install -m 0755 yoctoIVI ${D}${bindir}
}
