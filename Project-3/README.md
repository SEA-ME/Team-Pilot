
# **DES Project - Head Unit**

The head unit Qt application running on Raspberry Pi (RPi) alongside the instrument cluster Qt application

## **Project Intro**

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi.

<p align="center">
  <img width="854" height="352" src="https://user-images.githubusercontent.com/81483791/220690983-bc0886b1-1ecc-4da2-830d-73eeb0a10296.png">
</p>   

## **What is Yocto Project?**

The Yocto Project (YP) is an open source collaboration project that helps developers create custom Linux-based systems regardless of the hardware architecture.

The project is including all the tools, libraries, and technologies needed to develop custom Linux-based systems.


<p align="center">
  <img width="609" height="639" src="https://user-images.githubusercontent.com/81483791/220689781-7bcc49db-4c2d-4407-8967-9b0880fb0977.png">
</p>

## **Table of Contents**
- ### [Yocto Project Quick Build](#yocto-project-quick-build)    
Step 1. [ Downloading Yocto](#step-1-downloading-yocto)  
Step 2. [ Writing Os in SD card](#step-2-writing-os-in-sd-card)    
Step 3. [ Creating your custom layer](#step-3-creating-your-custom-layer)  
Step 4. [ Add python](#step-4-add-python)
- ### [Where To Go Next](#where-to-go-next) 
[How to use QT on yocto](QT/README.md)    
[How to use Commonapi-Dbus on yocto](Commonapi/README.md)  
[Adding other functions (WIFI, CAN, I2C, Auto-start etc)](Others/README.md)   
[Making your own Infotainment QT app](InfotainmentQT/README.md)



# Yocto Project Quick Build
### **General setup**

**Host machine:** Ubuntu 22.04.1 LTS

**Target machine:** Raspberry Pi 4   Model B     



## **Step 1. Downloading Yocto**

 1. Build Host Packages

```jsx
sudo apt install bmap-tools zstd liblz4-tool gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm python
```

 2. Make a directory

```jsx
cd ~
mkdir yocto && cd yocto
```

 3. Use Git to Clone Poky

<p align="center">
  <img width="1160" height="260" src="https://user-images.githubusercontent.com/81483791/220689823-2a2970fa-95ce-4cba-9a19-0caebc7fdb18.png">
</p>

We choose a release Codename (such as `kirkstone`)

```jsx
git clone -b kirkstone git://git.yoctoproject.org/poky.git
```

 4. Clone raspberry pi and extension

```jsx
cd poky
git clone -b kirkstone git://git.yoctoproject.org/meta-raspberrypi
git clone -b kirkstone git://git.openembedded.org/meta-openembedded
```

 5. Initialize the Build Environment

From within the poky directory, run the [oe-init-build-env](https://docs.yoctoproject.org/ref-manual/structure.html#oe-init-build-env) environment setup script to define Yocto Project’s build environment on your build host. 

```jsx
cd poky
source oe-init-build-env
```

 6. Add new layer

```jsx
cd ~/yocto/poky/build/conf
vim bblayers.conf
```

Add following line:

```jsx
/home/username/yocto/poky/meta-raspberrypi \  
/home/username*yocto/poky/meta-openembedded/meta-oe \
/home/username/yocto/poky/meta-openembedded/meta-multimedia \
/home/username/yocto/poky/meta-openembedded/meta-networking \
/home/username/yocto/poky/meta-openembedded/meta-perl \
/home/username/yocto/poky/meta-openembedded/meta-python \
```

 7. Update MACHINE and change directory

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

If we want to build for the Raspberry Pi 4, we're using `raspberrypi4`

or we can also use 64bit rpi4  `MACHINE = "raspberrypi4-64"`

change the following line:

`MACHINE ??= "qemux86-64"` -> `MACHINE = "raspberrypi4-64"`

```jsx
MACHINE = "raspberrypi4-64"
```

<p align="center">
  <img width="543" height="301" src="https://user-images.githubusercontent.com/81483791/220696637-5f0005ce-3df1-4927-9530-7df0350c7ed1.png">
</p>
Add the end of file following lines:

```jsx
# Uncomment and set to allow bitbake to execute multiple tasks at once. 
# For a quadcore, BB_NUMBER_THREADS = "4", PARALLEL_MAKE = "-j 4" would 
# be appropriate. 
BB_NUMBER_THREADS = "8" 
# Also, make can be passed flags so it run parallel threads e.g.: 
PARALLEL_MAKE = "-j 8"
```

```jsx
# For SD card image 
IMAGE_FSTYPES = "rpi-sdimg"
```

 8. Edit machine.conf

```jsx
cd ~/yocto/poky/meta-raspberrypi/conf/machine
vim raspberrypi4-64.conf
```

Change this line:

Please Edit `vc4-kms-v3d` to `vc4-fkms-v3d-pi4`

```jsx
//VC4DTBO ?= "vc4-kms-v3d"
VC4DTBO ?= "vc4-fkms-v3d-pi4"
```

 9. Build

```jsx
cd ~/yocto/poky
source oe-init-build-env
bitbake core-image-base
```

In the [Yocto documentation](https://docs.yoctoproject.org/ref-manual/images.html), you find a short description of the available image descriptions.

- `core-image-minimal`: A small image just capable of allowing a device to boot.
- `core-image-base`: A console-only image that fully supports the target device hardware.
- `core-image-full-cmdline`: A console-only image with more full-featured Linux system functionality installed.

## **Step 2. Writing Os in SD card**

 1. Find where SD card is

```jsx
sudo fdisk -l
```

OUTPUT:

<p align="center">
  <img width="593" height="185" src="https://user-images.githubusercontent.com/81483791/220697366-e0dadbc1-4c94-4ba9-a0fd-db97960b5188.png">
</p>

 2. umount

```jsx
umount /dev/sda
// umount: /dev/sda: not mounted
```

 3. Write image to SD card

When you done bitbake, You can find `rpi-sdimg` file.

```jsx
cd ~/yocto/poky/build/tmp/deploy/images/raspberrypi4-64
sudo dd if=core-image-base-raspberrypi4-64-20221227103058.rootfs.rpi-sdimg of=/dev/sda
sync
```

 4. Eject and reinsert SD card

Now, you can find boot and root 

<p align="center">
  <img width="614" height="206" src="https://user-images.githubusercontent.com/81483791/220697753-254c3815-6764-4846-a6b2-3a17f3f32ecb.png">
</p>

## **Step 3. Creating your custom layer**

Maybe you have an application or specific set of behaviors you need to isolate. You can create your own general layer using the `bitbake-layers create-layer` command. The tool automates layer creation by setting up a subdirectory with a `layer.conf` configuration file, a `recipes-example` subdirectory that contains an `example.bb` recipe, a licensing file, and a `README`.

 1. Make a new meta layer

```jsx
cd ~/yocto/poky
bitbake-layers create-layer meta-mylayer
```

`bitbake-layers create-layer meta-<layer_name>`

 2. Add new layer

```jsx
cd ~/yocto/poky/build/conf
vim bblayers.conf
```

Add following line:

```jsx
/home/username/yocto/poky/meta-mylayer \  
```

## **Step 4. Add python**
To add python, There are 3 solutions here.

 1. IMAGE_INSTALL

- **Solution 1. Using `local.conf` file**

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add following line:

```jsx
IMAGE_INSTALL:append = "python3 python3-numpy"
```

- **Solution 2. Using `core-image-base.bb` file**

```jsx
cd ~/yocto/poky/meta/recipes-core/images
vim core-image-base.bb
```

Add following line:

```jsx
IMAGE_INSTALL:append = "python3 python3-numpy"
```

- **Solution 3. Using my image file**

```jsx
cd ~/yocto/poky/meta-mylayer
mkdir -p recipes-core/images
cd recipes-core/images
```

```jsx
vim my-rpi-image.bb
```

- `my-rpi-image.bb`
    
    ```jsx
    SUMMARY = "My Raspberry pi image for python3 "
    
    require recipes-core/images/core-image-base.bb 
    
    IMAGE_INSTALL:append = "python3 python3-numpy"
     
    export IMAGE_BASENAME = "my-rpi-image"
    ```
    

***! IMPORTANT THING***

From `kirkstone` version,

We should change this override syntax. ex) `IMAGE_INSTALL_append` → `IMAGE_INSTALL:append`

Use `:` instead of `_`  

 2. Build

- **Solution 1 & Solution 2**

```jsx
cd ~/yocto/poky
source oe-init-build-env
bitbake -c cleanall core-image-base
bitbake core-image-base
```

- **Solution 3**

```jsx
cd ~/yocto/poky
source oe-init-build-env
bitbake my-rpi-image
```


 3. Booting and Executing python file

When you do first login, 

`login : root`

If you want to execute python file,

Now we can only use `vi`

```jsx
vi start.py
```

```jsx
print("Hello World!")
```

For this simple test code, you can check python3 

```jsx
python3 start.py
```

# Where To Go Next


Now, We can create a simple OS that can be booted.

Next step is how to run head unit Qt application on yocto based OS.

### [How to use QT on yocto](QT/README.md)    
### [How to use Commonapi-Dbus on yocto](Commonapi/README.md)
### [Adding other functions (WIFI, CAN, I2C, Auto-start etc)](Others/README.md)
### [Making your own Infotainment QT app](InfotainmentQT/README.md)