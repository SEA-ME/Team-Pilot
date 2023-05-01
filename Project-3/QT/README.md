# How to use QT on yocto



- ### Reference
    
    [Build Rpi4 Qt5 using Yocto project](http://www.yocto.co.kr/2017/03/yocto-morty-22-qtv57.html)    
    [Hacking Raspberry Pi 4 with Yocto](https://lancesimms.com/RaspberryPi/HackingRaspberryPi4WithYocto_Part5.html)   
    [Build Qt SDK1](https://makersweb.net/embedded/12540)   
    [Build Qt SDK2](https://makersweb.net/embedded/12845?search_target=title_content&search_keyword=sdk)
    
- ### Contents
    Step 1.[ Execute qt example file](#step-1-execute-qt-example-file)  
    Step 2-1.[ Using SDK](#step-2-1-using-sdk)  
    Step 2-2.[ Setup QT creator in Ubuntu (host PC)](#step-2-2-setup-qt-creator-in-ubuntu-host-pc)  
    Step 3.[ Using qmake (or cmake) on image](#step-3-using-qmake-or-cmake-on-image)


If you want to use QT on yocto project, I suggest following 3 steps.

## **Step 1. Execute qt example file**

 1. Use Git to Clone meta-qt5

```jsx
cd ~/yocto/poky
git clone -b kirkstone https://github.com/meta-qt5/meta-qt5
```

 2. Create new layer

```jsx
cd ~/yocto/poky/build/conf
vim bblayers.conf
```

Add following line:

```jsx
/home/username/yocto/poky/meta-qt5 \  
```

 3. Modify your configuration file

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add this line:

```jsx
CORE_IMAGE_EXTRA_INSTALL:append = " qtbase-examples"
```

 4. Make a directory and create .bbappend file

```jsx
cd ~/yocto/poky/meta-mylayer
mkdir -p recipes-qt/qt5
cd recipes-qt/qt5
vim qtbase_git.bbappend
```

Add this line:

```jsx
PACKAGECONFIG:append = " examples gles2 eglfs fontconfig"
DEPENDS += "userland"
```

 5. Build

```jsx
cd ~/yocto/poky
bitbake -c cleanall core-image-base
bitbake core-image-base
```

 6. Execute qt example file on Rpi4


Boot and Login your raspberry pi.

Execute this simple example file.

```jsx
cd /usr/share/qt5/examples/opengl/hellowindow
```

```jsx
./hellowindow -platform eglfs
```

 

## **Step 2-1. Using SDK**

 1. Write a new image recipe

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core/images
vim basic-qt5-image.bb
```
#### [basic-qt5-image.bb](example/basic-qt5-image.bb)   



 2. Build

```jsx
cd yocto/poky
source oe-init-build-env
bitbake basic-qt5-image
```

If you don’t need to add external library like `commonapi` ,

I recommend to follow [next step.](#step-3-using-qmake-or-cmake-on-image)

 3. Modify basic-qt5-image.bb

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core/images
vim basic-qt5-image.bb
```

Add this line top of file:

```jsx
inherit populate_sdk populate_sdk_qt5
```

 4. Modify your configuration file

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add this line:

```jsx
DISTRO_FEATURES:remove = "x11 vulkan"
```

 5. Build

```jsx
cd yocto/poky
source oe-init-build-env
bitbake basic-qt5-image -c populate_sdk
```

 6. Install SDK

If building successfully finished, You can check here 

```jsx
cd yocto/poky/build/tmp/deploy/sdk
```


Install `/opt/poky`

```jsx
./poky-glibc-x86_64-basic-qt5-image-cortexa72-raspberrypi4-64-toolchain-4.0.5.sh
```

```jsx
source /opt/poky/4.0.5/environment-setup-cortexa72-poky-linux
```

## **Step 2-2. Setup QT creator in Ubuntu (host PC)**

Tool → Options 

1. Compilers

Path : /opt/poky/4.0.5/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux/aarch64-poky-linux-g++

<p align="center">
  <img width="714" height="518" src="https://user-images.githubusercontent.com/81483791/220721714-b0495c22-2a4e-4827-aada-d6b758d9ee89.png">
</p>   

2. Debuggers

Path: /opt/poky/4.0.5/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux/aarch64-poky-linux-gdb

<p align="center">
  <img width="714" height="518"src="https://user-images.githubusercontent.com/81483791/220721719-0a9e4d50-b8b6-43a9-afd9-711ec1575026.png">
</p>

 3. CMake

Path: /opt/poky/4.0.5/sysroots/x86_64-pokysdk-linux/usr/bin/cmake

<p align="center">
  <img width="714" height="518" src="https://user-images.githubusercontent.com/81483791/220721723-1731a966-5bd2-48cf-8ea7-96abaf1714d3.png">
</p>

 4. Qt Versions

qmake location: /opt/poky/4.0.5/sysroots/x86_64-pokysdk-linux/usr/bin/qmake

<p align="center">
  <img width="714" height="518" src="https://user-images.githubusercontent.com/81483791/220721725-96e675ac-683f-4ac0-93d6-b719d6aa264f.png">
</p>

 5. Kits

<p align="center">
  <img width="714" height="518"src="https://user-images.githubusercontent.com/81483791/220721728-0195974d-35a3-46ed-8c77-5476694d6653.png">
</p>   

 6. Make simple Qt test file.

If you want to send this execute file to rpi, just use `sudo cp`


```jsx
cd ~/build-hello-RpiOS-Debug
```

```jsx
sudo cp hello /{your root directory}
```

 7. Execute file on Rpi

```jsx
./hello -platform eglfs
```


## **Step 3. Using qmake (or cmake) on image**

I assume you’ve followed up to `step2-2.2`

Now, we can make our simple qt file using `bitbake`.

 1. Make simple example bb.file

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-example
mkdir qt-example && cd qt-example
vim simple.bb
```

#### [simple.bb](example/simple.bb)   

    

### 2. Download and unzip files

#### [files.zip](example/files.zip)

unzip this file in this directory.

It should be look like this.
```jsx
.
├── files
│   ├── deployment.pri
│   ├── main.cpp
│   ├── MainForm.ui.qml
│   ├── main.qml
│   ├── qml.qrc
│   ├── simple.pro
│   └── simple.pro.user
└── simple.bb

1 directory, 8 files
```

Or you can easily make this simple example file using Qt creator.

Just make sure to match your file name in bb file.

 3. build

```jsx
cd ~/yocto/poky
source oe-init-build-env
bitbake simple
```

 4. IMAGE_INSTALL

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core/images
vim basic-qt5-image.bb
```

Add following line:

```jsx
IMAGE_INSTALL:append = " simple"
```

 5. build

```jsx
cd ~/yocto/poky
source oe-init-build-env
bitbake basic-qt5-image.bb
```

 6. Execute file on Rpi

```jsx
/usr/bin/simple -platform eglfs
```

because when we qmake this simple file, 

We already set where to save our execute file `${D}${bindir}` = /usr/bin