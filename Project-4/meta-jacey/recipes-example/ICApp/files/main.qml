import QtQuick 2.5
import QtQuick.Window 2.2 as Window
import QtWayland.Compositor 1.0
import QtQml 2.2
import QtQml.Models 2.1

WaylandCompositor{
    id: comp
    property bool right_screen: false

    Cluster {
        id:instrumentclusterLeft
        compositor: comp
        screen: Qt.application.screens[0]
    }

    PRND {
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

