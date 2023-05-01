SUMMARY = "Components useful to developers added to -devel images"
LICENSE = "CLOSED"

inherit packagegroup

RDEPENDS:${PN} = "\
    gcc \
    libopencv-core-dev \
    python3-core \
    python3-dev \
    python3-venv \
    python3-setuptools \
    python3-pip \
    v4l-utils \
"
