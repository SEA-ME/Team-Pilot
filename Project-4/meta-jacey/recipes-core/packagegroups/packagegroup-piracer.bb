SUMMARY = "Components useful to piracer"
LICENSE = "CLOSED"

inherit packagegroup

RDEPENDS:${PN} = "\
    python-adafruit-blinka \
    python-adafruit-circuitpython-busdevice \
    python-adafruit-circuitpython-framebuf \
    python-adafruit-circuitpython-ina219 \
    python-adafruit-circuitpython-pca9685 \
    python-adafruit-circuitpython-register \
    python-adafruit-circuitpython-requests \
    python-adafruit-circuitpython-ssd1306 \
    python-adafruit-circuitpython-typing \
    python-adafruit-platformdetect \
    python-adafruit-pureio \
    python-piracer-py \
    python-pyftdi \
    python-pyserial \
    python-pyusb \
    python-rpi-gpio \
    python-typing-extensions \
    python-wheel \
"
