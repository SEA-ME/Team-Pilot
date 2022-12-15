# Instrument Cluster using Qt

## Contents
- [Step 1: Qt Creator in RPi](#step-1-qt-creator-in-rpi)
- [Step 2: Import CommonAPI vsomeip libraries](#step-2-import-commonapi-vsomeip-libraries)
- [Step 3: Connect CommonAPI Generator code](#step-3-connect-commonapi-generator-code)

---

In this Page, I will describe how to make qt project in Raspberry Pi. I wanted to develop qt projects in my Ubuntu labtop, but when I cross compile my project to raspberry pi, It didn’t work properly because of commonapi vsomeip library (maybe). So I moved to raspberry pi my qt creator environment. If you have a solution how to cross compile commonapi vsomeip to raspberry pi, using ubuntu labtop is more proper environment.

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
unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-core-runtime/build/ -lCommonAPI

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-core-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/capicxx-someip-runtime/build/ -lCommonAPI-SomeIP

INCLUDEPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include
DEPENDPATH += $$PWD/../build-commonapi/capicxx-someip-runtime/include

unix:!macx: LIBS += -L$$PWD/../build-commonapi/vsomeip/build/ -lvsomeip

INCLUDEPATH += $$PWD/../build-commonapi/vsomeip/interface
DEPENDPATH += $$PWD/../build-commonapi/vsomeip/interface
```

<br/>

## Step 3: Connect CommonAPI Generator code


As I mentioned on [CommonAPI vSomeIP Setup (RPi) Step 6](https://www.notion.so/CommonAPI-vSomeIP-Setup-RPi-ce8b69ad6b4f40fc9734cf0e744a58e1), I couldn’t execute generator in raspberry pi. So you should generate code in your labtop, and send your src-gen folder using ‘rsync’ command.

<img src="https://user-images.githubusercontent.com/111988634/200329541-f38979ec-eae4-4bac-8dec-33953a3fa68c.png"  width="300" height="300"/> 

Add Existing Files - Select your generated codes

In my pro file, you can see that generated codes are included in sources and headers.

```bash
SOURCES += main.cpp \
    vsomedata.cpp \
    canstubimpl.cpp \
    ~/src-gen/v1/commonapi/CANSomeIPDeployment.cpp \
    ~/src-gen/v1/commonapi/CANSomeIPProxy.cpp \
    ~/src-gen/v1/commonapi/CANSomeIPStubAdapter.cpp \
    ~/src-gen/v1/commonapi/CANStubDefault.cpp

HEADERS += \
    vsomedata.h \
    canstubimpl.h \
    ~/src-gen/v1/commonapi/CAN.hpp \
    ~/src-gen/v1/commonapi/CANProxy.hpp \
    ~/src-gen/v1/commonapi/CANProxyBase.hpp \
    ~/src-gen/v1/commonapi/CANSomeIPDeployment.hpp \
    ~/src-gen/v1/commonapi/CANSomeIPProxy.hpp \
    ~/src-gen/v1/commonapi/CANSomeIPStubAdapter.hpp \
    ~/src-gen/v1/commonapi/CANStub.hpp \
    ~/src-gen/v1/commonapi/CANStubDefault.hpp
```

This is my prototype instrument cluster project. As you see, I didn’t caculate my RPM and speed yet.

[Digital Instrument Cluster Video](https://user-images.githubusercontent.com/111988634/200329556-4ca457d4-42d5-4613-865d-af7b0b90e7c4.webm)

- ### [main.cpp](Cluster/main.cpp)
- ### [vsomedata.cpp](Cluster/vsomedata.cpp)
- ### [canstubimpl.cpp](Cluster/canstubimpl.cpp)
- ### [vsomedata.h](Cluster/vsomedata.h)
- ### [canstubimpl.h](Cluster/canstubimpl.h)
- ### [main.qml](Cluster/main.qml)
- ### [Background.qml](Cluster/Background.qml)
- ### [Instrument_Cluster.qml](Cluster/Instrument_Cluster.qml)
- ### [CANClient.cpp](../CommonAPI-vSomeIP/project-can/src/CANClient.cpp)
- ### [uno_canshield.ino](../CAN/src/uno_canshield.ino)
