# Adding other functions (WIFI, CAN, I2C, Auto-start etc)

### **Table of Contents**

- [WIFI with systemd](#wifi-with-systemd) 
- [CAN](#can)
- [I2C](#i2c)
- [Auto login](#auto-login)
- [Auto Start](#auto-start)
- [Using joystick](#using-joystick)
- [Splash](#splash)

## WIFI with systemd

If you want to use init manager as systemd, follow this step.

1. Enable systemd

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add this line:

```jsx
# To use init manager as systemd
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""
```
2. Enable wifi

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add this line:

```jsx
# Wifi
IMAGE_INSTALL:append = " wpa-supplicant"
```

3.  Modify systemd recipe in custom layer

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/wifi
vim systemd_%.bbappend
```

#### [systemd_%.bbappend](WIFI/systemd_%25.bbappend)
    

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/wifi
mkdir files
cd files
vim wlan.network
```

#### [wlan.network](WIFI/wlan.network)
    

4.  Modify wpa-supplicant recipe in custom layer

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/wifi
vim wpa-supplicant_%.bbappend
```

#### [wpa-supplicant_%.bbappend](WIFI/wpa-supplicant_%25.bbappend)
    

    

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/wifi
mkdir files
cd files
vim wpa_supplicant-nl80211-wlan0.conf
```

#### [wpa_supplicant-nl80211-wlan0.conf](WIFI/wpa_supplicant-nl80211-wlan0.conf)   


## CAN

1. Enable CAN

```jsx
~/yocto/poky/meta-mylayer/recipes-bsp/bootfiles
vim rpi-config_git.bbappend
```

Add this line

```jsx
#In order to use CAN with an MCP2515-based module, set the following variables:
ENABLE_CAN = "1"
#In case of dual CAN module (e.g. PiCAN2 Duo), set following variables instead:
#ENABLE_DUAL_CAN = "1"

CAN_OSCILLATOR="16000000"
do_deploy:append() {
    echo "dtoverlay=spi-bcm2835-overlay" >> ${DEPLOYDIR}/bootfiles/config.txt
    echo "max_framebuffers=2" >> ${DEPLOYDIR}/bootfiles/config.txt
}
```

2. IMAGE_INSTALL

Add this line in your bitbake image

```jsx
IMAGE_INSTALL:append = " can-utils libsocketcan"
```

3. Build and Run

```jsx
ip link set can0 up type can bitrate 500000
candump can0
```

## I2C

For taking battery level, We should use ina219 on yocto.

1. Enable I2C

```jsx
~/yocto/poky/meta-mylayer/recipes-bsp/bootfiles
vim rpi-config_git.bbappend
```

Add this lines:

```jsx
ENABLE_I2C = "1"
KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"
```

additionally, you can enable `UART`, `SPI`

```jsx
ENABLE_UART = "1"
ENABLE_SPI_BUS = "1"
```

2. Make test bb.file

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example
mkdir pi-ina219
cd pi-ina219
```

```jsx
git clone https://github.com/kevinboone/pi-ina219.git
```

You can get source files in this git directory.

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/pi-ina219/pi-ina219
vim CMakeLists.txt
```

#### [CMakeLists.txt](I2C/CMakeLists.txt)   
    

    

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/pi-ina219
vim ina-battery.bb
```
#### [ina-battery.bb](I2C/ina-battery.bb)   
  

## Auto login

- Modify your custom image

Just add following lines in your bb file.

```jsx
KIRKSTONE_LOCAL_GETTY ?= " \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/getty@.service \
"

local_autologin () {
     sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root /' ${KIRKSTONE_LOCAL_GETTY}
}

ROOTFS_POSTPROCESS_COMMAND += "local_autologin; "
```
## Auto Start


If you want the program to run automatically after booting,

You can use the script file to run the desired program.

1. Create a script file

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/qt5
mkdir files && cd files
vim qt5-env.sh
```
#### [qt5-env.sh](Auto-start/qt5-env.sh)   


    

```jsx
export QT_QPA_EGLFS_KMS_CONFIG=/etc/kms.conf
export QT_QPA_EGLFS_INTEGRATION=eglfs_kms
export QT_QPA_PLATFORM=eglfs
export QT_QPA_EGLFS_KMS_ATOMIC=1
```

This is a pre-set part to run the QT app.

If you ran the QT app with '`-platform eglfs`',

By setting '`export QT_QPA_PLATFORM=glfs`' in advance,

There is no need to set up the platform every time you run it.

```jsx
export $(dbus-launch)
```

Commonapi Dbus is set up for service and client communication.

If this is not set up in advance, the following error occurs.

`Unable to autolaunch a dbus-daemon without a $DISPLAY for x11` 

```jsx
ip link set can0 up type can bitrate 500000
```

Set the bitrate so that CAN communication can be performed immediately after booting.

```jsx
# /usr/bin/IpcService & /usr/bin/IpcClient
```

Set the desired program execution as follows.

2. Create a configuration file   

To use a dual monitor, it sets the HDMI output connected to the raspberry pi.

If you use one monitor, you can skip it.

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/qt5
vim kms.conf
```
#### [kms.conf](Auto-start/kms.conf)   



3. Create an image file

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/qt5
vim qt5-env.bb
```
#### [qt5-env.bb](Auto-start/qt5-env.bb)   

    

This image file allows you to build scripts and conf files on ${D}${sysconfdir} in the OS.

```jsx
Variable name	        Definition	        Typical value
-------------  --------------------    --------------------
prefix	       /usr                    /usr
base_prefix	   (empty)	               (empty)
exec_prefix	   ${base_prefix}	         (empty)
base_bindir    ${base_prefix}/bin	     /bin
base_sbindir	 ${base_prefix}/sbin	   /sbin
base_libdir	   ${base_prefix}/lib	     /lib
datadir        ${prefix}/share	       /usr/share
sysconfdir	   /etc	                   /etc
localstatedir	 /var	                   /var
infodir        ${datadir}/info	       /usr/share/info
mandir         ${datadir}/man	         /usr/share/man
docdir         ${datadir}/doc	         /usr/share/doc
servicedir	   /srv	                   /srv
bindir         ${exec_prefix}/bin	     /usr/bin
sbindir        ${exec_prefix}/sbin	   /usr/sbin
libexecdir	   ${exec_prefix}/libexec	 /usr/libexec
libdir         ${exec_prefix}/lib	/usr /lib
includedir	   ${exec_prefix}/include	 /usr/include
palmtopdir	   ${libdir}/opie	         /usr/lib/opie
palmqtdir	     ${palmtopdir}	         /usr/lib/opie
```

## Using Joystick
1. Make custom packagegroup

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core
mkdir packagegroups
vim 
packagegroup-seame-devel.bb
```
#### [packagegroup-seame-devel.bb](Joystick/packagegroup-seame-devel.bb)   


2. Make for  piracer image

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example
mkdir piracer && cd piracer
```

```jsx
vim rcexam.bb
```
#### [rcexam.bb](Joystick/rcexam.bb)


```jsx
mkdir files && cd files
```

```jsx
vim rc_example.py
```
#### [rc_example.py](Joystick/rc_example.py)


3.  Modify your custom image

```jsx
IMAGE_INSTALL:append = " packagegroup-seame-devel packagegroup-core-boot rcexam"
# make extra space
IMAGE_ROOTFS_EXTRA_SPACE = "148576"
```

4. pip3 install

After booting,

```jsx
pip3 install piracer-py
```

```jsx
cd /usr/bin
python3 rc_example.py
```

For automatic execution, you can add the `rc_example.py` program execution setting to [auto-start](#auto-start).

```jsx
cd ~/yocto/poky/meta-jacey/recipes-example/qt5
mkdir files && cd files
vim qt5-env.sh
```

```jsx
cd /usr/bin
IpcClient & yoctoIVI &
# If you already have piracer-py library 
if python3 -c 'import pkgutil; exit(not pkgutil.find_loader("piracer"))'; then
    cd /usr/bin
    python3 rc_example.py 
else
    while :
    do
# Checking wifi connection 
        echo -e "GET http://google.com HTTP/1.0\n\n" | nc google.com 80 > /dev/null 2>&1
  
        if [ $? -eq 0 ]; then
          pip3 install piracer-py
          reboot
          break
        else
          echo "Offline"
        fi
    done
    cd /usr/bin
    python3 rc_example.py 
fi
```

**Important!**

After the library is installed with '`pip3 install piracer-py`',

The Raspberry Pi must be safely rebooted or shut down to avoid damaging the file.   

## Splash

If you use `core-image-base`

When you boot up raspberry pi, You can see splash image.

Here is how to change this image.

1. Git clone

```jsx
cd ~/yocto/poky
git clone https://github.com/hamzamac/meta-splash
```

2. Add new layer

```jsx
cd ~/yocto/poky/build/conf
vim bblayers.conf
```

Add following line:

```jsx
/home/username/yocto/poky/meta-splash \  
```

3. Add your image

```jsx
cd ~/yocto/poky/meta-splash/recipes-core/psplash/files
```