# IPC - commonapi-Dbus


<img src="https://user-images.githubusercontent.com/81483791/194726738-c873e16d-6515-4c54-baf3-dd75bb0d0c17.png"  width="400" height="200"/>   

- ## Reference site

[CommonAPI  D Bus in 10 minutes](https://github.com/COVESA/capicxx-dbus-tools/wiki/CommonAPI-C---D-Bus-in-10-minutes#step5)   
[commonapi-dbus downlaod](https://jayden-ji.tistory.com/84)   
[JAVA 8 downlaod](https://amosground.blogspot.com/2018/01/linux-xubuntu-commonapi-cc.html)
- - - 

- ## Contents

[Step 1. Build the CommonAPI Runtime Library](#1-build-the-commonapi-runtime-library)    
[Step 2. Build the CommonAPI D-Bus Runtime Library](#2-build-the-commonapi-d-bus-runtime-library)   
[Step 3. Download code generator](#3-download-code-generator)    
[Step 4. Install JAVA 8 ](#4-install-java-8httpswwworaclecomjavatechnologiesdownloadsjava8)   
[Step 5. Generate Code](#5-generate-code)   
[Step 6. Write the client and the service application](#6-write-the-client-and-the-service-application)   
[Step 7. Make CMakeList file](#7-make-cmakelist)   
[Step 8. Build and run](#8-build-and-run)   
[How to send CAN data , Battery data using IPC](#how-to-send-can-data--battery-data-using-ipc)
- - -

### 1. **Build the CommonAPI Runtime Library**

```jsx
mkdir commonapi
cd commonapi/
```

```jsx
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
git checkout 3.1.12.6
mkdir build
cd build
cmake ..
make
```

### 2. **Build the CommonAPI D-Bus Runtime Library**

```jsx
cd commonapi/
```

```jsx
git clone https://github.com/GENIVI/capicxx-dbus-runtime.git
```

```jsx
wget http://dbus.freedesktop.org/releases/dbus/dbus-1.10.10.tar.gz
tar -xzf dbus-1.10.10.tar.gz
cd dbus-1.10.10/
```

```jsx
patch -p1 <../capicxx-dbus-runtime/src/dbus-patches/capi-dbus-add-send-with-reply-set-notify.patch
patch -p1 <../capicxx-dbus-runtime/src/dbus-patches/capi-dbus-add-support-for-custom-marshalling.patch
```

- OUTPUT:
    - capi-dbus-add-send-with-reply-set-notify
    
    patching file dbus/dbus-connection.c
    Hunk #1 succeeded at 3500 (offset 18 lines).
    patching file dbus/dbus-connection.h
    
    - capi-dbus-add-support-for-custom-marshalling
    
    patching file dbus/dbus-message.c
    Hunk #1 succeeded at 3595 (offset -151 lines).
    Hunk #2 succeeded at 4824 (offset -230 lines).
    patching file dbus/dbus-message.h
    Hunk #1 succeeded at 138 (offset -32 lines).
    Hunk #2 succeeded at 268 with fuzz 1 (offset -34 lines).
    patching file dbus/dbus-string.c
    patching file dbus/dbus-string.h
    

```jsx
./configure
make
```

```jsx
ls dbus/.libs/libdbus-1.so*
```

- OUTPUT:
    
    dbus/.libs/libdbus-1.so    dbus/.libs/libdbus-1.so.3.14.7
    dbus/.libs/libdbus-1.so.3
    

```jsx
cd capicxx-dbus-runtime/
git checkout 3.1.12.11
mkdir build
cd build/
```

Please check your path

```jsx
export PKG_CONFIG_PATH="/home/seame-two/commonapi/dbus-1.10.10"
```

```jsx
cmake -D USE_INSTALLED_COMMONAPI=OFF -D USE_INSTALLED_DBUS=OFF ..
```

```jsx
make
```

### 3. **Download code generator**

```jsx
~/$  mkdir project-fidl-gen-test
cd project-fidl-gen-test/
mkdir fidl
cd fidl
vim HelloWorld.fidl
```

 #### [HelloWorld.fidl](HelloWorld-example/project-fidl-gen-test/fidl/HelloWorld.fidl)


```jsx
cd project-fidl-gen-test/
mkdir cgen
cd cgen
```

Download [commonapi-generator](https://github.com/COVESA/capicxx-core-tools/releases) 3.1.12.4

```jsx
wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.1.12.4/commonapi-generator.zip
```

Download [commonapi-bus-generator](https://github.com/COVESA/capicxx-dbus-tools/releases) 3.1.12.2

```jsx
wget https://github.com/COVESA/capicxx-dbus-tools/releases/download/3.1.12.2/commonapi_dbus_generator.zip
```

```jsx
~/project-fidl-gen-test/cgen$  unzip commonapi-generator.zip -d commonapi-generator
~/project-fidl-gen-test/cgen$  unzip commonapi_dbus_generator.zip -d commonapi_dbus_generator
```

```jsx
~/project-fidl-gen-test/cgen/commonapi-generator$ chmod +x commonapi-generator-linux-x86
```

```jsx
~/project-fidl-gen-test/cgen/commonapi_dbus_generator$ chmod +x commonapi-dbus-generator-linux-x86
```

### 4. Install [JAVA 8](https://www.oracle.com/java/technologies/downloads/#java8)



```jsx
wget https://javadl.oracle.com/webapps/download/GetFile/1.8.0_321-b07/df5ad55fdd604472a86a45a217032c7d/linux-i586/jdk-8u321-linux-x64.tar.gz
```

```jsx
tar -xvzf jdk-8u321-linux-x64.tar.gz
```

```jsx
sudo mv jdk1.8.0_321 /usr/local
```

```jsx
sudo vi /etc/profile
```

Add this line:

```jsx
JAVA_HOME=/usr/local/jdk1.8.0_321
PATH=$PATH:$JAVA_HOME/bin
CLASS_PATH=.:$JAVA_HOME/jre/lib/ext:$JAVA_HOME/lib/tools.jar
export JAVA_HOME PATH CLASS_PATH
```

### 5. **Generate Code**

```jsx
cd project-fidl-gen-test/
```

```jsx
source /etc/profile
```

```jsx
~/project-fidl-gen-test$ ./cgen/commonapi-generator/commonapi-generator-linux-x86 -sk ./fidl/HelloWorld.fidl
~/project-fidl-gen-test$ ./cgen/commonapi_dbus_generator/commonapi-dbus-generator-linux-x86 ./fidl/HelloWorld.fidl
```

We can check generated code

```jsx
~/project-fidl-gen-test/src-gen/v1/commonapi$ ls
```

- OUTPUT:
    
    HelloWorldDBusDeployment.cpp   HelloWorld.hpp
    HelloWorldDBusDeployment.hpp   HelloWorldProxyBase.hpp
    HelloWorldDBusProxy.cpp        HelloWorldProxy.hpp
    HelloWorldDBusProxy.hpp        HelloWorldStubDefault.cpp
    HelloWorldDBusStubAdapter.cpp  HelloWorldStubDefault.hpp
    HelloWorldDBusStubAdapter.hpp  HelloWorldStub.hpp
    

If you can’t use generator in Raspberry pi, You can use this zip file.

```jsx
cd project-fidl-gen-test/
wget https://github.com/jacey-h/Team-Pilot/raw/main/Project-2/Commonapi-Dbus/HelloWorld-example/project-fidl-gen-test/src-gen.zip
unzip src-gen.zip
```

### 6. **Write the client and the service application**

```jsx
cd project-fidl-gen-test/
mkdir src
cd src
```

Make this  4 files in src directory

#### [HelloWorldClient.cpp](HelloWorld-example/project-fidl-gen-test/src/HelloWorldClient.cpp)

#### [HelloWorldService.cpp](HelloWorld-example/project-fidl-gen-test/src/HelloWorldService.cpp)

#### [HelloWorldStubImpl.hpp](HelloWorld-example/project-fidl-gen-test/src/HelloWorldStubImpl.hpp)

#### [HelloWorldStubImpl.cpp](HelloWorld-example/project-fidl-gen-test/src/HelloWorldStubImpl.cpp)



### 7. Make CMakeList

```jsx
cd project-fidl-gen-test/
vim CMakeLists.txt
```

### CMakeLists.txt

```jsx
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    $ENV{RUNTIME_PATH}/capicxx-core-runtime/include
    $ENV{RUNTIME_PATH}/capicxx-dbus-runtime/include
    $ENV{DBUS_PATH}
)
link_directories(
    $ENV{RUNTIME_PATH}/capicxx-core-runtime/build
    $ENV{RUNTIME_PATH}/capicxx-dbus-runtime/build
    $ENV{DBUS_PATH}/dbus/.libs
)
add_executable(HelloWorldClient
	src/HelloWorldClient.cpp
	src-gen/v1/commonapi/HelloWorldDBusProxy.cpp
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-DBus dbus-1)
add_executable(HelloWorldService
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	src-gen/v1/commonapi/HelloWorldDBusStubAdapter.cpp
	src-gen/v1/commonapi/HelloWorldStubDefault
	src-gen/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-DBus dbus-1)
```

Please check your path.

If you follow every step, your path is same like this.

#### [CMakeList.txt](HelloWorld-example/project-fidl-gen-test/CMakeLists.txt)


## In raspberry pi

Add this 2 lines:

```jsx
project(ProjectName)
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -latomic")
```



### 8. Build and run

```jsx
cd project-fidl-gen-test/
mkdir build
cd build
```

```jsx
cmake ..
make
```

OUTPUT:
```jsx
./HelloWorldService &
```
<img src="https://user-images.githubusercontent.com/81483791/194726827-8a0aff2a-a9c4-4b83-a8cb-aedb81815489.png"  width="500" height="110"/> 

```jsx
./HelloWorldClient
```
<img src="https://user-images.githubusercontent.com/81483791/194726855-c372c73c-57b0-44b2-a260-761464a0a925.png"  width="500" height="81"/> 


- - - 

## How to send CAN data , Battery data using IPC

### In Raspberry Pi

### 1. Make Franca file (.fidl)

```jsx
mkdir project
cd ~/project/fidl
vim DbusData.fidl
```
#### [DbusData.fidl](DbusData-example/project/fidl/DbusData.fidl)
    

### 2. Generate Code

```jsx
cd ~/project/
```

```jsx
source /etc/profile
```

```jsx
cd ~/project-fidl-gen-test
./cgen/commonapi-generator/commonapi-generator-linux-x86 -sk ./fidl/DbusData.fidl
cd ~/project-fidl-gen-test
./cgen/commonapi_dbus_generator/commonapi-dbus-generator-linux-x86 ./fidl/DbusData.fidl
```
```jsx
cd project-fidl-gen-test/
wget https://github.com/jacey-h/Team-Pilot/raw/main/Project-2/Commonapi-Dbus/DbusData-example/project/src-gen.zip
unzip src-gen.zip
```
### 3. **Write the client and the service application**

```jsx
cd ~/project/src
```
#### [DbusDataClient.cpp](DbusData-example/project/src/DbusDataClient.cpp)
#### [DbusDataService.cpp](DbusData-example/project/src/DbusDataService.cpp)
#### [DbusDataStubImpl.hpp](DbusData-example/project/src/DbusDataStubImpl.hpp)
#### [DbusDataStubImpl.cpp](DbusData-example/project/src/DbusDataStubImpl.cpp)


### 4. Make CMakeList.txt

```jsx
cd ~/project/
vim CMakeLists.txt
```
### [CMakeLists.txt](DbusData-example/project/CMakeLists.txt)


### 5. Build and run

```jsx
cd ~/project/
mkdir build
cd build
```

```jsx
cmake ..
make
```