SUMMARY = "A basic Raspberry pi image"

require recipes-core/images/core-image-base.bb 

IMAGE_INSTALL += " common-api-c++ vsomeip common-api-c++-someip"

export IMAGE_BASENAME = "some-test-image"