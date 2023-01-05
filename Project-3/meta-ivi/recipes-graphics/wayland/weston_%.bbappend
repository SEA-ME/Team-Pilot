PR = "r3"

DEPENDS += "xkeyboard-config"
RDEPENDS_${PN} += "xkeyboard-config"

FILESEXTRAPATHS:append := ":${THISDIR}/${PN}"

FILES:${PN} += "${libdir}/weston/*"
FILES:${PN}-dbg += "${libdir}/weston/.debug/*"

