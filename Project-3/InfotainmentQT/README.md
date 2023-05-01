# Infotainment QT

So far, we have explained how to add the desired features to Yocto. 

Now it's time to create your own Infotainment QT app!

## [Instrument Cluster](yoctoIVI/IC/Cluster.qml)

It was created by referring to the QT example file, and details can be found [here](https://doc.qt.io/QtIVI/qtivi-ivicore-qface-tutorial-example.html).

<p align="center">
  <img width="1123" height="360" src="https://user-images.githubusercontent.com/81483791/221198961-b21376b8-85c6-4656-aab3-fb6ee8de5538.png">
</p>

```jsx
├── Background.qml
├── Cluster.qml
├── Dial.qml
├── Fuel.qml
├── ICPrnd.qml
├── images
│   ├── car.png
│   ├── dial_cursor.png
│   ├── dial_cursor_right.png
│   ├── dial_fill_color_left.png
│   ├── dial_fill_color.png
│   ├── dial_pattern.png
│   ├── fuel_level.png
│   ├── fuel.png
│   ├── fuelsymbol_orange.png
│   ├── left_dial.png
│   ├── mask_overlay.png
│   ├── middle-bkg.png
│   ├── middle-circle.png
│   ├── nosensor.png
│   ├── +--.png
│   ├── P-R-N-D.png
│   ├── right_dial.png
│   ├── sensor.png
│   └── top_bar.png
├── Label.qml
├── LeftDial.qml
├── PDC.qml
├── RightDial.qml
└── Top.qml
```
## [Head Unit](yoctoIVI/HU/HeadUnit.qml)

<p align="center">
  <img width="1273" height="490" src="https://user-images.githubusercontent.com/81483791/221198943-9481ea97-1989-46fe-aeae-09a0062399fd.png">
</p>

<p align="center">
  <img width="1273" height="490" src="https://user-images.githubusercontent.com/81483791/221198950-b3f6631d-59a6-4d63-a3ac-309f770966e9.png">
</p>

```jsx
├── Background.qml
├── HeadUnit.qml
├── images
│   ├── backBar.PNG
│   ├── back.PNG
│   ├── battery.PNG
│   ├── buttonBox.PNG
│   ├── car.PNG
│   ├── homeLight.PNG
│   ├── homeMap.PNG
│   ├── homeMUsic.PNG
│   ├── home.PNG
│   ├── homeSetting.PNG
│   ├── map.jpg
│   ├── menu.PNG
│   └── toolbutton.sci
├── Label.qml
├── mainHu.qml
├── MiddleBar.qml
├── MyButton.qml
└── TopBar.qml
```

I used qtwayland compositor to display clusters and head units on two monitors each.

At this time, dual monitors should be available. So if you haven't set them up, please read [here](../Others/README.md) first.

**Platform : EGLFS**

**Compositor : qtwayland**

## What is [EGLFS](https://doc.qt.io/qt-6/embedded-linux.html)?

On Embedded Linux systems, there are multiple platform plugins that you can use: EGLFS, LinuxFB, DirectFB, or Wayland. 

EGLFS is a platform plugin for running Qt applications on EGL, OpenGL ES 2.0 without Windows System (e.g., X11 or Wayland).

## What is [QtWayland](https://wiki.qt.io/QtWayland) ?

QtWayland is a Qt 5 module that wraps the functionality of Wayland. QtWayland is separated into a client and server side. The client side is the wayland platform plugin, and provides a way to run Qt applications as Wayland clients. The server side is the Qt Wayland Compositor API, and allows users to write their own Wayland compositors.

`main.qml`

```jsx
import QtQuick 2.5
import QtQuick.Window 2.2 as Window
import QtWayland.Compositor 1.0
import QtQml 2.2
import QtQml.Models 2.1
import "IC"
import "HU"

WaylandCompositor{
    id: comp
    property bool right_screen: false

    Cluster {
        id:instrumentclusterLeft
        compositor: comp
        screen: Qt.application.screens[0]
    }

    HeadUnit {
        signal prndSignal(int msg)
        id: headunitRight
        compositor: comp
        screen: Qt.application.screens[1]
        Component.onCompleted: comp.defaultOutput = this
        onPrndSignal: instrumentclusterLeft.msgIndex = msg
    }

     function handleShellSurfaceCreated(shellSurface) {
         // First application is shown on left screen
         // Second application is show on right screen
         // Then start with left screen again
         if (right_screen) {
             createShellSurfaceItem(shellSurface, headunitRight);
             right_screen = false;
         }
        else {
            createShellSurfaceItem(shellSurface, instrumentclusterLeft);
            right_screen = true;
        }
     }
}
```