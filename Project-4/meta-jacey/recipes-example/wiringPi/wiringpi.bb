SUMMARY = "wiringPi"
SECTION = "libs"
LICENSE = "CLOSED"
SRC_URI[sha256sum] = "fb6b004f615159e62bfc9c2c34098a08604a14af3a88076033fa7c8dcfdc658b"

SRCREV = "5de0d8f"
SRC_URI = "https://github.com/WiringPi/WiringPi/archive/refs/tags/2.61-1.zip"
S = "${WORKDIR}"
inherit autotools
DEPENDS = " libgcrypt libxcrypt "

# do_configure() {
#     ${S}/WiringPi-2.61-1/build
# }

do_compile() {
    cd ${S}/WiringPi-2.61-1/wiringPi    
    make -j5 
    cd ${S}/WiringPi-2.61-1/devLib   
    make -j5 
    cd ${S}/WiringPi-2.61-1/gpio   
    make -j5 
}

do_install() {
    install -d ${D}${libdir}
    cd ${S}/WiringPi-2.61-1/wiringPi
    install -m 0755 libwiringPi.so.2.61 ${D}${libdir}
    cd ${S}/WiringPi-2.61-1/devLib 
    install -m 0755 libwiringPiDev.so.2.61 ${D}${libdir}
    # cd ${S}/WiringPi-2.61-1/gpio
    # install -m 0755 libgpio.so.2.61 ${D}${libdir}
}
do_package_qa[noexec] = "1"
