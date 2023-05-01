SUMMARY = "A Raspberry pi image for Infotainment system"

require recipes-core/images/core-image-base.bb 

IMAGE_INSTALL:append = " \ 
    wpa-supplicant \
    common-api-c++ \
    common-api-c++-dbus \
    i2c-tools \
    qt5-env \
    can-utils \
    libsocketcan \
    ipcexam \
    rcexam \
    yoctoIVI \
    packagegroup-seame-devel \
    packagegroup-core-boot \
    libcamera \
    kernel-modules \
"

IMAGE_ROOTFS_EXTRA_SPACE = "148576"


KIRKSTONE_LOCAL_GETTY ?= " \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/getty@.service \
"

local_autologin () {
     sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root /' ${KIRKSTONE_LOCAL_GETTY}
}

ROOTFS_POSTPROCESS_COMMAND += "local_autologin; "

QT_BASE = " \
    qtbase \
    qtbase-dev \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-tools \
"
 
QT_PKGS = " \
    qtwayland \
    qtwayland-dev \
    qtwayland-mkspecs \
    qtconnectivity-dev \
    qtconnectivity-mkspecs \
    qtquickcontrols \
    qtquickcontrols-qmlplugins \
    qtquickcontrols2 \
    qtquickcontrols2-dev \
    qtquickcontrols2-mkspecs \
    qtquickcontrols2-qmlplugins \
    qtdeclarative \
    qtdeclarative-dev \
    qtdeclarative-mkspecs \
    qtdeclarative-qmlplugins \
    qtgraphicaleffects \
    qtgraphicaleffects-dev \
    qtmultimedia \
    qtmultimedia-plugins \
    qtmultimedia-qmlplugins \
"
 
IMAGE_INSTALL += " \
    ${QT_BASE} \
    ${QT_PKGS} \
"
export IMAGE_BASENAME = "qt-api-test-image"
