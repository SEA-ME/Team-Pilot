SUMMARY = "rc_example application"
SECTION = "examples"
LICENSE = "CLOSED"
SRC_URI = "file://rc_example.py"

# Avoid a compilation error: No GNU_HASH in the elf binary
TARGET_CC_ARCH += "${LDFLAGS}"

S = "${WORKDIR}"


do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 rc_example.py ${D}${bindir}
}
