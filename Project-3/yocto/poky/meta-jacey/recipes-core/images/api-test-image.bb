SUMMARY = "A basic Raspberry pi image"

require recipes-core/images/core-image-base.bb 

IMAGE_INSTALL:append = " common-api-c++ common-api-c++-dbus"
IMAGE_INSTALL:append = " can-utils libsocketcan helloexam ipcexam qt5-env"

KIRKSTONE_LOCAL_GETTY ?= " \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/getty@.service \
"

local_autologin () {
     sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root /' ${KIRKSTONE_LOCAL_GETTY}
}

ROOTFS_POSTPROCESS_COMMAND += "local_autologin; "


export IMAGE_BASENAME = "api-test-image"