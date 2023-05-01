# How to use Commonapi-Dbus on yocto

    
    

 - ### Reference
    
    [meta-ivi](https://github.com/GENIVI/meta-ivi)    
    [systemd](https://velog.io/@markyang92/yocto-meta-raspberrypi)
    

- ### Contents  
 1. [Select commonapi version](#select-commonapi-version)  
 2. [Using Commonapi-Dbus](#using-commonapi-dbus)      
        Step 1.[ Change dbus version (Latest)](#step-1-change-dbus-version-latest)      
        Step 2.[ Download meta-ivi ]()     
        Step 3.[ Change version](#step-3-change-version)     
        Step 4.[ Add build system](#step-4-add-build-system)    
        Step 5.[ Edit local.conf file](#step-5-edit-localconf-file)    
        Step 6.[ Change commonapi version (Latest)](#step-6-change-commonapi-version-latest)    
        Step 7.[ Make own image](#step-7-make-own-image)    
        Step 8.[ BitBake](#step-8-bitbake)    



## **Selecting commonapi version**

If you want to use Commonapi-Dbus, I propose to match the version.

1. **Old Version**
- Library

capicxx-core-runtime [3.1.12.6](https://github.com/COVESA/capicxx-core-runtime/releases/tag/3.1.12.6)

capicxx-dbus-runtime [3.1.12.11](https://github.com/COVESA/capicxx-dbus-runtime/releases/tag/3.1.12.11)

dbus [1.10.10](https://dbus.freedesktop.org/releases/dbus/)

- Code generator

commonapi-generator [3.1.12.4](https://github.com/COVESA/capicxx-core-tools/releases/tag/3.1.12.4)

commonapi-bus-generator [3.1.12.2](https://github.com/COVESA/capicxx-dbus-tools/releases/tag/3.1.12.2)

2. **Latest Version (When to write 01.02.2023)**
- Library

capicxx-core-runtime [3.2.0](https://github.com/COVESA/capicxx-core-runtime/releases/tag/3.2.0)

capicxx-dbus-runtime [3.2.0](https://github.com/COVESA/capicxx-dbus-runtime/releases/tag/3.2.0)

dbus [1.14.0](https://dbus.freedesktop.org/releases/dbus/)

- Code generator

commonapi-generator [3.2.0.1](https://github.com/COVESA/capicxx-core-tools/releases/tag/3.2.0.1)

commonapi-bus-generator [3.2.0](https://github.com/COVESA/capicxx-dbus-tools/releases/tag/3.2.0)     

----


## **Using Commonapi-Dbus**

1. Change dbus version (Latest)

To use dbus-1.14.0 version, change your [dbus version](http://cgit.openembedded.org/openembedded-core/tree/meta/recipes-core/dbus?h=kirkstone-next).

You can check your dbus version here.

```jsx
cd ~/yocto/poky/meta/recipes-core/dbus
open .
```

If your dbus is not 1.14.0 verison, You should change like this.

|  |  |
| --- | --- |
| <img src="https://user-images.githubusercontent.com/81483791/221005536-fe43c83e-036e-4b5b-92db-1697d30c6f8c.png"  width="460" height="185"/> |  <img src="https://user-images.githubusercontent.com/81483791/221005538-df1303b8-c920-4eed-87db-e3db229e73b7.png"  width="578" height="185"/> |

2. Download `meta-ivi`

```jsx
cd ~/yocto/poky
git clone https://github.com/GENIVI/meta-ivi.git
```

3. Change version

```jsx
cd ~/yocto/poky/meta-ivi/meta-ivi/conf
vim layer.conf
```

Edit following line.

```jsx
LAYERSERIES_COMPAT_ivi = "kirkstone"
```

This version has old override syntax.

We should change this override syntax. ex) `IMAGE_INSTALL_append` → `IMAGE_INSTALL:append`

From kirkstone version, use `:` instead of `_`  .

4.  Add build system

```jsx
cd ~/yocto/poky/build/conf
vim bblayers.conf
```

Add following line:

```jsx
/home/username/yocto/poky/meta-ivi/meta-ivi \  
```

5. Edit local.conf file

```jsx
cd ~/yocto/poky/build/conf
vim local.conf
```

Add following line

```jsx
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""
```

It makes that we use `systemd` instead of `sysvinit` .

6. Change commonapi version (Latest)

```jsx
cd ~/yocto/poky/meta-ivi/meta-ivi/recipes-extended/common-api
```

In this directory, We will change this 2 files.

Please rename it

`common-api-c++_3.1.12.6.bb` → `common-api-c++_3.2.0.bb`

`common-api-c++-dbus_3.1.12.11.bb` → `common-api-c++-dbus_3.2.0.bb`

```jsx
vim common-api-c++_3.2.0.bb
```

#### [common-api-c++_3.2.0.bb](example/common-api-c%2B%2B_3.2.0.bb)   

 

I only change this line.

`SRCREV = "89720d3c63bbd22cbccc80cdc92c2f2dd20193ba"`

<p align="center">
  <img width="606" height="234" src="https://user-images.githubusercontent.com/81483791/221005542-06f64c71-9860-4903-af47-fa1ce4a10a87.png">
</p>

I want to change release version, so I just modified version commit. 

```jsx
vim common-api-c++-dbus_3.2.0.bb
```
#### [common-api-c++-dbus_3.2.0.bb](example/common-api-c%2B%2B-dbus_3.2.0.bb)   
    

    

7. Make own image

```jsx
cd ~/yocto/poky/meta-mylayer/recipes-core/images
vim api-test.bb
```

#### [api-test.bb](example/api-test.bb)   
   

8. Bitbake

```jsx
bitbake api-test
```

- Trouble Shooting
    
    If you have have any other error form meta-ivi,
    
    I recommend to delete the file or directory that error occured