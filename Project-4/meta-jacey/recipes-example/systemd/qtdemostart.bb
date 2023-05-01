SUMMARY = "Start Qt-Demo application"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI += "file://qt_demo_start.service \
            file://qt_demo_start.sh"

S = "${WORKDIR}"

inherit systemd

SYSTEMD_PACKAGES="${PN}"

do_install() {
    install -d ${D}${sbindir}
    install -m 0750 qt_demo_start.sh ${D}${sbindir}

    install -d ${D}${systemd_system_unitdir}
    install -m 0644 qt_demo_start.service ${D}${systemd_system_unitdir}
}

FILES:${PN} = "${sbindir} ${systemd_system_unitdir}"

SYSTEMD_SERVICE:${PN} = "qt_demo_start.service"