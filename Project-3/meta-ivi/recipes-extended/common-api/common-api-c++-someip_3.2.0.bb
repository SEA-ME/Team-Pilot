SUMMARY = "Genivi CommonAPI-SomeIP"
SECTION = "libs"
LICENSE = "MPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

DEPENDS = "boost common-api-c++ vsomeip"

SRCREV = "0ad2bdc1807fc0f078b9f9368a47ff2f3366ed13"
SRC_URI = "git://github.com/GENIVI/capicxx-someip-runtime.git;protocol=https \
    "
S = "${WORKDIR}/git"

inherit cmake lib_package gitpkgv

EXTRA_OECMAKE += "-DUSE_INSTALLED_COMMONAPI=ON"

FILES:${PN}-dev += "${libdir}/cmake"
RDEPENDS_${PN}-dev = "vsomeip-dev"

BBCLASSEXTEND = "nativesdk"
