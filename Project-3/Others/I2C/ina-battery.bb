    SUMMARY = "battery application"
    SECTION = "examples"
    LICENSE = "CLOSED"
    
    DEPENDS = " i2c-tools"
    
    inherit cmake
    SRC_URI = "file://src/defs.h \
    	   file://src/ina219.h \
    	   file://src/ina219.c \
    	   file://src/main.c \
    	   file://CMakeLists.txt \
    	   "
    
    S = "${WORKDIR}"
    
    do_install() {
    	     install -d ${D}${bindir}
    	     install -m 0755 piina ${D}${bindir}
    }