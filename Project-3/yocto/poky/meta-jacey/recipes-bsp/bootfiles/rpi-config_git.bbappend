ENABLE_UART = "1"
ENABLE_SPI_BUS = "1"
ENABLE_I2C = "1"
KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"
#In order to use CAN with an MCP2515-based module, set the following variables:
ENABLE_CAN = "1"
#In case of dual CAN module (e.g. PiCAN2 Duo), set following variables instead:
#ENABLE_DUAL_CAN = "1"

CAN_OSCILLATOR="16000000"
do_deploy:append() {
    echo "dtoverlay=spi-bcm2835-overlay" >> ${DEPLOYDIR}/bootfiles/config.txt
    echo "max_framebuffers=2" >> ${DEPLOYDIR}/bootfiles/config.txt
}
