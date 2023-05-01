SUMMARY = "Add Qt5 bin dir to PATH"

LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = "file://qt5-env.sh \
           file://kms.conf"

PR = "r1"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${sysconfdir}/profile.d
    install -m 0755 qt5-env.sh ${D}${sysconfdir}/profile.d

    install -d ${D}${sysconfdir}
    install -m 0755 kms.conf ${D}${sysconfdir}
}

FILES_${PN} = "${sysconfdir}"

