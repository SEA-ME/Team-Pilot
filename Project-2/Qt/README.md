# Instrument Cluster using Qt

## Contents
- [Step 1: Qt Creator in RPi](#step-1-qt-creator-in-rpi)
- [Step 2: Import CommonAPI vsomeip libraries](#step-2-import-commonapi-vsomeip-libraries)
- [Step 3: Connect CommonAPI Generator code](#step-3-connect-commonapi-generator-code)
- [Step 4: Make your App!](#step-4-make-your-app)

---

Now it is time to create a qt application using the project created by commonapi vsomeip. First, you need to download an IDE to develop qt, so you can work easily. Since the application we use uses CAN, it is often cumbersome to work on the host PC, so we installed it on the RPi and proceeded.

After working on the Host PC, there is a way to cross-compile with Raspberry Pi and send only the executable file, but I couldn't. Also, since debugging is not possible because there is no CAN, it is a convenient way to just open qt creator from RPi.

The download method followed [**Link**](https://s-engineer.tistory.com/265).

In Qt, the build method is divided into cmake and qmake. It is recommended to use cmake from qt6.

However, since qt5.15 is used more universally, it is written with qmake in this project.

Instrument Cluster receives CAN data from the current service and displays the values.

Qt is divided into front-end and back-end. In terms of the web, the front-end is QML and the back-end is C++.

Since vsomeip has made all the backend stages, this project is over if you only touch the front side and write qmake according to Qt.

---

<br/>

## Step 1: Qt Creator in RPi

```bash
sudo apt-get install qt5-default
sudo apt-get install qtcreator
sudo apt-get install qtdeclarative5-dev
```
<img src="https://user-images.githubusercontent.com/111988634/200329521-08180a5c-be79-431f-aada-361b84e883a7.png"  width="500" height="300"/>  

You can execute Qt Creator in Raspberry Pi

Create new project - Application - Qt Quick Application (Empty)

<br/>

## Step 2: Import CommonAPI vsomeip libraries

<img src="https://user-images.githubusercontent.com/111988634/200329535-ef58f5c9-8154-47c3-8f05-c42f6243b2a4.png"  width="300" height="300"/>  

To use CommonAPI vsomeip, you should import 3 libraries in Qt projects. In Qt creator, you can easily add dependencies.

Add Library - External library - Browse Library path and Include path

If you follow my [CommonAPI vSomeIP Setup (RPi)](../CommonAPI-vSomeIP/), your library path will be `~/build-commonapi/capicxx-core-runtime/build` and your include path `~/build-commonapi/capicxx-core-runtime/include`.

After you add 3 libraries, you can see follow codes in pro file.

```bash
unix:!macx: LIBS += -L$$PWD/../../../../../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../../../../../build-commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../../../../../build-commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../../../../../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../../../../../build-commonapi/capicxx-someip-runtime/include
DEPENDPATH += $$PWD/../../../../../build-commonapi/capicxx-someip-runtime/include

unix:!macx: LIBS += -L$$PWD/../../../../../build-commonapi/vsomeip/build/ -lvsomeip3

INCLUDEPATH += $$PWD/../../../../../build-commonapi/vsomeip/interface
DEPENDPATH += $$PWD/../../../../../build-commonapi/vsomeip/interface
```

<br/>

## Step 3: Connect CommonAPI Generator code

As I mentioned on [CommonAPI vSomeIP Setup (RPi) Step 6](../CommonAPI-vSomeIP/), I couldn’t execute generator in raspberry pi. So you should generate code in your labtop, and send your src-gen folder using ‘rsync’ command.

<img src="https://user-images.githubusercontent.com/111988634/200329541-f38979ec-eae4-4bac-8dec-33953a3fa68c.png"  width="300" height="300"/> 

Add Existing Files - Select your generated codes

In my pro file, you can see that generated codes are included in sources and headers.

```bash
INCLUDEPATH += ../src-gen/
SOURCES += \
        ../src-gen/v1/commonapi/CANSomeIPDeployment.cpp \
        ../src-gen/v1/commonapi/CANSomeIPProxy.cpp \
        ../src-gen/v1/commonapi/CANSomeIPStubAdapter.cpp \
        canclient.cpp \
        main.cpp

HEADERS += \
  ../src-gen/v1/commonapi/CAN.hpp \
  ../src-gen/v1/commonapi/CANProxy.hpp \
  ../src-gen/v1/commonapi/CANProxyBase.hpp \
  ../src-gen/v1/commonapi/CANSomeIPDeployment.hpp \
  ../src-gen/v1/commonapi/CANSomeIPProxy.hpp \
  ../src-gen/v1/commonapi/CANSomeIPStubAdapter.hpp \
  ../src-gen/v1/commonapi/CANStub.hpp \
  ../src-gen/v1/commonapi/CANStubDefault.hpp \
  canclient.h
```

<br/>

## Step 4: Make your App!

If you use the CAN data you received last time to connect to qml, Project 2 will be over. To create an app, you need to learn the Qt framework, but there are not many materials in Korean, so please check the official document. It's really well organized, so if you find the features you're looking for, almost everything is implemented. Since Qt app acts as a client, the service used the existing executable file as it is.

Below is my qt project code.
- [canclient.cpp](instrumentcluster/src/canclient.cpp)
- [canclient.h](instrumentcluster/src/canclient.h)
- [main.cpp](instrumentcluster/src/main.cpp)
- [instrumentcluster.pro](instrumentcluster/src/instrumentcluster.pro)
- [qml files](instrumentcluster/qml/)