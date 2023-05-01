    SUMMARY = "A basic Qt5 dev image"
    
    require recipes-core/images/core-image-minimal.bb 
    
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
     
    export IMAGE_BASENAME = "basic-qt5-image"