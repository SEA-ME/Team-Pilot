# Pilot Project 4 - PDC

## Contents
- [Step 1: Setting Ultrasonic Sensor](#step-1-setting-ultrasonic-sensor)
- [Step 2: Add new var in fidl](#step-2-add-new-var-in-fidl)
- [Step 3: Add Buzzer (or speaker)](#step-3-add-buzzer-or-speaker)
- [Step 4: Make your App!](#step-4-make-your-app)

---

## Reference

- [Arduino - Ultrasonic Sensor](https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm#:~:text=Previous)
- [Playing the Imperial March From Star Wars on Raspberry Pi With Piezo Buzzer](https://www.instructables.com/Playing-the-Imperial-March-From-Star-Wars-on-Raspb/)
- [rpi-examples](https://github.com/leon-anavi/rpi-examples)

---

<br/>

## Step 1: Setting Ultrasonic Sensor
First, take the ultrasound sensor value from Arduino and deliver it to the service. Connect Arduino and as follows. Pins were connected to 7 and 8. For more details, please refer to this place.
- [ultrasonic.ino](ultrasonic/ultrasonic.ino)

Since the CAN value has been increased, you need to add Ultrasonic value to Canservice.

```bash
cd ~
mkdir seame
cd seame && mkdir canservice
cd canservice
mkdir src && cd src
```

- [CANService.cpp](seame/canservice/src/CANService.cpp)
- [SEAMEStubImpl.cpp](seame/canservice/src/SEAMEStubImpl.cpp)
- [SEAMEStubImpl.hpp](seame/canservice/src/SEAMEStubImpl.hpp)
- [defs.h](seame/canservice/src/defs.h)
- [ina219.c](seame/canservice/src/ina219.c)
- [ina219.h](seame/canservice/src/ina219.h)

```bash
cd ~/seame/canservice
code CMakeLists.txt
```
- [CMakeLists.txt](seame/canservice/CMakeLists.txt)

Check that the ultrasonic sensor value is well received and then add an ultrasonic sensor variable to the VSOMEIP FIDL.

<br/>

## Step 2: Add new var in fidl

```bash
cd ~/seame && mkdir fidl
cd fidl
```

- [seame.fidl](seame/fidl/seame.fidl)
- [seame.fdepl](seame/fidl/seame.fdepl)

Run generator

```bash
cd ~/seame
../generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/seame.fidl -d ./src-gen-seame
../generator/someip-generator/commonapi-someip-generator-linux-x86_64 ./fidl/seame.fdepl -d ./src-gen-seame
```
- troubleshooting
    
     https://github.com/COVESA/capicxx-someip-tools/issues/34
    
    ```bash
    /home/moon/Team-Pilot/Project-4/seame/src-gen-seame/v1/commonapi/SEAMESomeIPStubAdapter.hpp:265: error: ‘UNDEFINED_EVENTGROUP_ID’ was not declared in this scope
    ../Team-Pilot/Project-4/seame/src-gen-seame/v1/commonapi/SEAMESomeIPStubAdapter.hpp:265:70: error: ‘UNDEFINED_EVENTGROUP_ID’ was not declared in this scope
      265 |             itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(UNDEFINED_EVENTGROUP_ID));
          |                                                                      ^~~~~~~~~~~~~~~~~~~~~~~
    ```

Move to RPI (copied or git to SD card)

<br/>

## Step 3: Add Buzzer (or speaker)
I didn't have a speaker, so I decided to use a simple Buzzer. Connected to the Raspberry Pi and pressed the R button to make the Buzzer sound rang. And simply pressing the MUSIC icon to play the Star Wars example with beep.

Turn the example and apply it to the QT.

```bash
git clone https://github.com/leon-anavi/rpi-examples.git
cd rpi-examples
cd buzzer/c/
gcc starwars.c -o starwars -lwiringPi -std=c99
```

## Step 4: Make your App!
The existing headunit app has been added to the BUZZER and camera functions. The camera function is convenient because it can be implemented as code in QML or C ++. For more information, please refer to the QT Document.

- [ambient.cpp](seame/src/ambient.cpp)
- [ambient.h](seame/src/ambient.h)
- [beep.cpp](seame/src/beep.cpp)
- [beep.h](seame/src/beep.h)
- [canclient.cpp](seame/src/canclient.cpp)
- [canclient.h](seame/src/canclient.h)
- [main.cpp](seame/src/main.cpp)
- [seame.pro](seame/src/seame.pro)
- [qml files](seame/qml/)