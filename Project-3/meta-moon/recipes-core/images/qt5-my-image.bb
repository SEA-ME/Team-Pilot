SUMMARY = "The minimal image that can run Qt5 applications"
LICENSE = "MIT"

require recipes-core/images/core-image-base.bb

inherit populate_sdk populate_sdk_qt5

QT_TOOLS = " \
    qtbase \
    qtbase-dev \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-tools \
"
QT_PKGS = " \
    qt3d \
    qt3d-dev \
    qt3d-mkspecs \
    qtcharts \
    qtcharts-dev \
    qtcharts-mkspecs \
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
"

IMAGE_INSTALL:append = " \
    ${QT_TOOLS} \
    ${QT_PKGS} \
"
DISTRO_FEATURES:remove = "x11 wayland vulkan"

export IMAGE_BASENAME = "qt5-my-image"