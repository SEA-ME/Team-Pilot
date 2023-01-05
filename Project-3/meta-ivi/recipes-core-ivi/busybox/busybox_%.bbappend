FILESEXTRAPATHS:append := ":${THISDIR}/${PN}"
SRC_URI += "file://remove-syslog.cfg"

# Defconfig doesn't have syslog activated
# Adapt if needed in the future
SYSTEMD_PACKAGES:remove = "${PN}-syslog"
INITSCRIPT_PACKAGES:remove = "${PN}-syslog"
ALTERNATIVE_${PN}-syslog:remove = "syslog-conf"
