SUMMARY = "My package group"

inherit packagegroup

COMPATIBLE_MACHINE = "^rpi$"

RDPENDS:${PN} = "\
    can-utils \
    libsocketcan \
"