    SUMMARY = "A basic Raspberry pi image"
    
    require recipes-core/images/core-image-base.bb 
    
    IMAGE_INSTALL += " common-api-c++ common-api-c++-dbus"
    export IMAGE_BASENAME = "api-test"