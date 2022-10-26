# Crosscompiling Qt 5.15 for RPi 4B

## Contents    
- [Step 1: Enable Development Sources](#step-1-enable-development-sources)
- [Step 2: Update the system](#step-2-update-the-system)
- [Step 3: Install the required development packages](#step-3-install-the-required-development-packages)
- [Step 4: Create a directory for the Qt install](#step-4-create-a-directory-for-the-qt-install)
- [Step 5: Update the PC](#step-5-update-the-pc)
- [Step 6: Set up the directory structure](#step-6-set-up-the-directory-structure)
- [Step 7: Download Qt sources](#step-7-download-qt-sources)
- [Step 8: Download the cross-compiler](#step-8-download-the-cross-compiler)
- [Step 9: Sync our sysroot](#step-9-sync-our-sysroot)
- [Step 10: Fix symbolic links](#step-10-fix-symbolic-links)
- [Step 11: Configure Qt Build](#step-11-configure-qt-build)
- [Step 12: Build Qt](#step-12-build-qt)
- [Step 13: Deploy Qt to our Raspberry Pi](#step-13-deploy-qt-to-our-raspberry-pi)
- [Step 14: Update linker on Raspberry Pi](#step-14-update-linker-on-raspberry-pi)
- [Step 15: Build an example application](#step-15-build-an-example-application)
- [Step 16: Add library what you want](#step-16-add-library-what-you-want)

---

<br/>

## Reference
- https://github.com/UvinduW/Cross-Compiling-Qt-for-Raspberry-Pi-4

<br/>


`Raspberry Pi`

## Step 1: Enable Development Sources

```bash
sudo nano /etc/apt/sources.list
```

In the nano text editor, uncomment the following line by removing the `#` character (the line should exist already, if not then add it):

```bash
deb-src http://raspbian.raspberrypi.org/raspbian/ buster main contrib non-free rpi
```

<br/>

## Step 2: Update the system

```bash
sudo apt-get update
sudo apt-get dist-upgrade
sudo reboot
```

```bash
which rsync
# /usr/bin/rsync
sudo visudo
```

Add following structure

```bash
<username> ALL=NOPASSWD:/usr/bin/rsync
```

<br/>

## Step 3: Install the required development packages

```bash
sudo apt-get build-dep qt5-qmake
sudo apt-get build-dep libqt5gui5
sudo apt-get build-dep libqt5webengine-data
sudo apt-get build-dep libqt5webkit5
sudo apt-get install libudev-dev libinput-dev libts-dev libxcb-xinerama0-dev libxcb-xinerama0 gdbserver
```

<br/>

## Step 4: Create a directory for the Qt install

```bash
sudo mkdir /usr/local/qt5.15
sudo chown -R moon:moon /usr/local/qt5.15
```

<br/>

`PC`
## Step 5: Update the PC

```bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install gcc git bison python gperf pkg-config gdb-multiarch
sudo apt install build-essential
```

<br/>

## Step 6: Set up the directory structure

```bash
sudo mkdir ~/rpi
sudo mkdir ~/rpi/build
sudo mkdir ~/rpi/tools
sudo mkdir ~/rpi/sysroot
sudo mkdir ~/rpi/sysroot/usr
sudo mkdir ~/rpi/sysroot/opt
sudo chown -R 1000:1000 ~/rpi
cd ~/rpi
```

<br/>

## Step 7: Download Qt sources

```bash
sudo wget http://download.qt.io/archive/qt/5.15/5.15.0/single/qt-everywhere-src-5.15.0.tar.xz
sudo tar xfv qt-everywhere-src-5.15.0.tar.xz
cp -R qt-everywhere-src-5.15.0/qtbase/mkspecs/linux-arm-gnueabi-g++ qt-everywhere-src-5.15.0/qtbase/mkspecs/linux-arm-gnueabihf-g++
sed -i -e 's/arm-linux-gnueabi-/arm-linux-gnueabihf-/g' qt-everywhere-src-5.15.0/qtbase/mkspecs/linux-arm-gnueabihf-g++/qmake.conf
```

<br/>

## Step 8: Download the cross-compiler

```bash
cd ~/rpi/tools
sudo wget https://releases.linaro.org/components/toolchain/binaries/7.4-2019.02/arm-linux-gnueabihf/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
sudo tar xfv gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
cd ~/rpi
```

<br/>

## Step 9: Sync our sysroot

```bash
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/lib sysroot
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/usr/include sysroot/usr
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/usr/lib sysroot/usr
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/usr/local/qt5.15 sysroot/usr/local
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/opt/vc sysroot/opt
```

<br/>

## Step 10: Fix symbolic links

```bash
wget https://raw.githubusercontent.com/riscv/riscv-poky/master/scripts/sysroot-relativelinks.py
sudo chmod +x sysroot-relativelinks.py
./sysroot-relativelinks.py sysroot
```
<br/>

## Step 11: Configure Qt Build
To prevent error, I add these 3 lines at the top of `~/rpi/qt-everywhere-src-5.15.0/qtbase/src/corelib/global/qglobal.h`
```c++
#ifdef __cplusplus
#include <limits>
#endif
```

```bash
cd ~/rpi/build
../qt-everywhere-src-5.15.0/configure -release -opengl es2  -eglfs -device linux-rasp-pi4-v3d-g++ -device-option CROSS_COMPILE=~/rpi/tools/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf- -sysroot ~/rpi/sysroot -prefix /usr/local/qt5.15 -extprefix ~/rpi/qt5.15 -opensource -confirm-license -skip qtscript -skip qtwayland -skip qtwebengine -nomake tests -make libs -pkg-config -no-use-gold-linker -v -recheck
```
<details>
<summary>Troubleshooting</summary>
    
```bash
(base) seame-three@seamethree-ThinkPad-P14s-Gen-2a:~/rpi/build$ ../qt-everywhere-src-5.15.0/configure -release -opengl es2  -eglfs -device linux-rasp-pi4-v3d-g++ -device-option CROSS_COMPILE=~/rpi/tools/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf- -sysroot ~/rpi/sysroot -prefix /usr/local/qt5.15 -extprefix ~/rpi/qt5.15 -opensource -confirm-license -skip qtscript -skip qtwayland -skip qtwebengine -nomake tests -make libs -pkg-config -no-use-gold-linker -v -recheck
+ cd qtbase
+ /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/configure -top-level -release -opengl es2 -eglfs -device linux-rasp-pi4-v3d-g++ -device-option CROSS_COMPILE=/home/seame-three/rpi/tools/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf- -sysroot /home/seame-three/rpi/sysroot -prefix /usr/local/qt5.15 -extprefix /home/seame-three/rpi/qt5.15 -opensource -confirm-license -skip qtscript -skip qtwayland -skip qtwebengine -nomake tests -make libs -pkg-config -no-use-gold-linker -v -recheck
Performing shadow build...
Preparing build tree...
Creating qmake...
g++ -c -o qutfcodec.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake/library -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake/generators -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/src/3rdparty/tinycbor/src -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake/generators/unix -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake/generators/win32 -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/qmake/generators/mac -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/5.15.0 -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/5.15.0/QtCore -I../src/corelib/global -I/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.0\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=0 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/src/corelib/codecs/qutfcodec.cpp
In file included from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/qfloat16.h:1,
                 from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h:44,
                 from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/qendian.h:1,
                 from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/src/corelib/codecs/qutfcodec.cpp:43:
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:7: error: ‘numeric_limits’ is not a class template
  300 | class numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> : public numeric_limits<float>
      |       ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:77: error: expected template-name before ‘<’ token
  300 | class numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> : public numeric_limits<float>
      |                                                                             ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:77: error: expected ‘{’ before ‘<’ token
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:344:18: error: ‘numeric_limits’ is not a class template
  344 | template<> class numeric_limits<const QT_PREPEND_NAMESPACE(qfloat16)>
      |                  ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:344:69: error: ‘std::numeric_limits’ is not a template
  344 | template<> class numeric_limits<const QT_PREPEND_NAMESPACE(qfloat16)>
      |                                                                     ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:7: note: previous declaration here
  300 | class numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> : public numeric_limits<float>
      |       ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:345:28: error: expected template-name before ‘<’ token
  345 |     : public numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> {};
      |                            ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:346:18: error: ‘numeric_limits’ is not a class template
  346 | template<> class numeric_limits<volatile QT_PREPEND_NAMESPACE(qfloat16)>
      |                  ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:346:72: error: ‘std::numeric_limits’ is not a template
  346 | template<> class numeric_limits<volatile QT_PREPEND_NAMESPACE(qfloat16)>
      |                                                                        ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:7: note: previous declaration here
  300 | class numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> : public numeric_limits<float>
      |       ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:347:28: error: expected template-name before ‘<’ token
  347 |     : public numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> {};
      |                            ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:348:18: error: ‘numeric_limits’ is not a class template
  348 | template<> class numeric_limits<const volatile QT_PREPEND_NAMESPACE(qfloat16)>
      |                  ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:348:78: error: ‘std::numeric_limits’ is not a template
  348 | template<> class numeric_limits<const volatile QT_PREPEND_NAMESPACE(qfloat16)>
      |                                                                              ^
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:300:7: note: previous declaration here
  300 | class numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> : public numeric_limits<float>
      |       ^~~~~~~~~~~~~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qfloat16.h:349:28: error: expected template-name before ‘<’ token
  349 |     : public numeric_limits<QT_PREPEND_NAMESPACE(qfloat16)> {};
      |                            ^
In file included from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/qendian.h:1,
                 from /home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/src/corelib/codecs/qutfcodec.cpp:43:
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h: In static member function ‘static constexpr QSpecialInteger<S> QSpecialInteger<S>::max()’:
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h:331:30: error: ‘std::numeric_limits’ is not a template
  331 |     { return QSpecialInteger(std::numeric_limits<T>::max()); }
      |                              ^~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h:331:54: error: incomplete type ‘std::numeric_limits’ used in nested name specifier
  331 |     { return QSpecialInteger(std::numeric_limits<T>::max()); }
      |                                                      ^~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h: In static member function ‘static constexpr QSpecialInteger<S> QSpecialInteger<S>::min()’:
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h:333:30: error: ‘std::numeric_limits’ is not a template
  333 |     { return QSpecialInteger(std::numeric_limits<T>::min()); }
      |                              ^~~
/home/seame-three/rpi/qt-everywhere-src-5.15.0/qtbase/include/QtCore/../../src/corelib/global/qendian.h:333:54: error: incomplete type ‘std::numeric_limits’ used in nested name specifier
  333 |     { return QSpecialInteger(std::numeric_limits<T>::min()); }
      |                                                      ^~~
gmake: *** [Makefile:383: qutfcodec.o] Error 1
```
    
```bash
(base) seame-three@seamethree-ThinkPad-P14s-Gen-2a:~/rpi/build$ g++ --version
g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
    
For me the following solution works to build both Qt5 ant Qt6 with GCC 11: I add these 3 lines at the top of qtbase/src/corelib/global/`qglobal.h` :
    
```bash
#ifdef __cplusplus
#include <limits>
#endif
```
    
If you have any issues, before running configure again, delete the current contents with the following command (save a copy of config log first if you need to):
    
```bash
rm -rf *
```

</details>

<br/>

## Step 12: Build Qt

```bash
make -j4
make install
```

<br/>

## Step 13: Deploy Qt to our Raspberry Pi

```bash
cd ~/rpi
rsync -avz --rsync-path="sudo rsync" qt5.15 moon@<IP-address>:/usr/local
```

<br/>

## Step 14: Update linker on Raspberry Pi

```bash
echo /usr/local/qt5.15/lib | sudo tee /etc/ld.so.conf.d/qt5.15.conf
sudo ldconfig
```

```bash
If you're facing issues with running the example, 
try to use 00-qt5pi.conf instead of qt5pi.conf, to introduce proper order.
```

<br/>

## Step 15: Build an example application

```bash
cp -r ~/rpi/qt-everywhere-src-5.15.0/qtbase/examples/opengl/qopenglwidget ~/rpi/
cd ~/rpi/qopenglwidget
../qt5.15/bin/qmake
make
```

```bash
scp qopenglwidget moon@<IP-address>:/home/moon
```

<br/>

`Raspberry Pi`

```bash
cd ~
./qopenglwidget
# if you want to use Full screen Mode...
# you should disable VNC through **raspi-config**
./qopenglwidget -platform vnc
```

<br/>

## Step 16: Add library what you want
If you want to add libraries in qt projects, you should download libraries in your RPi. After that find where is library in your terminal. In my case, I want to inlcude vSomeIP library in qt projects.

```bash
(env) moon@moon:~ $ whereis libvsomeip3.so
libvsomeip3: /usr/local/lib/libvsomeip3.so
```

You can find the directory where is library you want. Then copy and paste `/usr/local/lib/` to \<source-file-dir>

```bash
rsync -avz --rsync-path="sudo rsync" --delete moon@<IP-address>:/usr/local/lib/ sysroot/usr/local
```

And then start again Step 10 to Step 14.