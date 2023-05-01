import QtQuick 2.7
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3
import QtMultimedia 5.15
import QtQuick.Layouts 1.2
import QtQml 2.0
import data 0.0

WaylandOutput {
    id: prnd
    property alias screen: winHead.screen
    property int colorIndex: 4
    sizeFollowsWindow: true

    property bool windowed: false


    window: Window {
        id: winHead
        x: Screen.virtualX
        y: Screen.virtualY
        visibility: Window.FullScreen
        visible: true


        Background {

        }


        Rectangle {
            id : root
            width: parent.width
            height: parent.height*0.7

            color:"black"
                TopBar {
                    id: topBar
                }
                MiddleBar {
                    id: middleBar
                }

        }

    }
}
