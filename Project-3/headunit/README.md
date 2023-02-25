# HeadUnit using Qt

## Contents
- [Step 1: Qtwayland download](#step-1-qtwayland-download)
- [Step 2: Ambient Light Setting](#step-2-ambient-light-setting)
- [Step 3: Make your App!](#step-3-make-your-app)

---

## Reference
- [wiringpi (deprecated)](http://wiringpi.com/pins/)
- [Raspberry Pi GPIO in Go and C - RGB LED](https://youngkin.github.io/post/sunfoundergpionotesrgbled/)
- [WiringPi (unofficial)](https://github.com/WiringPi/WiringPi/tree/final_official_2.50)
- [KY-009 RGB SMD-LED
](https://sensorkit.joy-it.net/en/sensors/ky-009)
---

<br/>

Since the difficulty of yocto is enormous and the amount is vast, it seems that you can save a lot of time in the order of making HU and putting it into yocto rather than doing yocto first.

To run two apps on two monitors, you need to use Qt App Manager and QtWayland.

I didn't have time to implement Qt Appmanager (I spent too much time on yocto), so I had no choice but to use qtwayland. The problem at this time was that two independent Qt projects could not be launched, so only one Qt project could be launched on two monitors.

So, the goal was to combine the IC created in Project 2 and the HU to be created from now on into one Qt project. The goals of this Head Unit are as follows.

- Press the PRND button to change the color of the IC
- Press the PRND button to change the LED color
- Run each on 2 monitors (this is how I wanted it, the easiest way would be to find out how to run 2 apps on 1 monitor)

First, you need to create a signal in PRND and send it to two places. The first is the IC qml, the second is the ambient cpp file. ambient is an object created for the LED. It is a simple project to find out which button was pressed through the received signal and change the qml color and LED color according to the value.

## Step 1: Qtwayland download
If qtwayland does not exist, download it with the command below.
```bash
sudo apt-get install -y qml-module-qtwayland-compositor
```
<br/>

## Step 2: Ambient Light Setting

Download the library to use Raspberry Pi's GPIO.
```bash
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build
```
LED connection method

The LED model used is **KY-009 RGB SMD-LED**
| RPi | LED |
| --- | --- |
| GND | ㅡ |
| GPIO17 | R |
| GPIO27 | B |
| GPIO18  | G |

Experiment with simple example codes [on the site](https://youngkin.github.io/post/sunfoundergpionotesrgbled/). It is written in C language, but I just wrote it. If you modify it in C++ and use it, it will be more complete.

<br/>

## Step 3: Make your App!
Likewise, a lot of ambient class and qtwayland related codes have been added to the Instrument cluster app. If there are many codes that you do not know, you can refer to the qt document.

- [ambient.cpp](src/ambient.cpp)
- [ambient.h](src/ambient.h)
- [canclient.cpp](src/canclient.cpp)
- [canclient.h](src/canclient.h)
- [main.cpp](src/main.cpp)
- [headunit.pro](src/headunit.pro)
- [qml files](qml/)