SUMMARY = "CommonAPI"
SECTION = "libs"
LICENSE = "MPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

PROVIDES = "commonapi3"
PR = "r0"

DEPENDS = "dlt-daemon"

inherit cmake lib_package pkgconfig

SRCREV = "89720d3c63bbd22cbccc80cdc92c2f2dd20193ba"
SRC_URI = "git://github.com/GENIVI/capicxx-core-runtime.git;protocol=https \
    "
S = "${WORKDIR}/git"

EXTRA_OECMAKE += "-DCMAKE_INSTALL_PREFIX=/usr \
    -DINSTALL_LIB_DIR:PATH=${baselib} \
    -DINSTALL_CMAKE_DIR:PATH=${baselib}/cmake/CommonAPI \
    "

FILES:${PN}-dev += "${libdir}/cmake"
