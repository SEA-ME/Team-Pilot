FILESEXTRAPATHS:append := ":${THISDIR}/${PN}"

inherit systemd

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "X.service"

SRC_URI:append = " file://X.service \
                 "
do_install:append() {
    if ${@bb.utils.contains('DISTRO_FEATURES','systemd','true','false',d)}; then
        install -d ${D}${systemd_unitdir}/system/
        install -m 0644 ${WORKDIR}/X.service ${D}${systemd_unitdir}/system
    fi
}
