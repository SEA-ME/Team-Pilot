# Base this image on core-image-base
include recipes-core/images/core-image-base.bb

COMPATIBLE_MACHINE = "^rpi$"

# Enable SPI bus
ENABLE_SPI_BUS = "1"

# Enable I2C
ENABLE_I2C = "1"
KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"

# Enable CAN
#In order to use CAN with an MCP2515-based module, set the following variables:
#ENABLE_SPI_BUS = "1"
#ENABLE_CAN = "1"

#In case of dual CAN module (e.g. PiCAN2 Duo), set following variables instead:
ENABLE_SPI_BUS = "1"
ENABLE_DUAL_CAN = "1"

IMAGE_INSTALL += "packagegroup-moon"