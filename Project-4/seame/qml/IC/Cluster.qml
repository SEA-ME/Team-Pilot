import QtQuick 2.5
import QtQuick.Window 2.3
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0

WaylandOutput {
    id: screen
    property alias screen: winInstrument.screen
    sizeFollowsWindow: true

    property bool windowed: false
    property int msgIndex: 0


    window: Window {
        id : winInstrument
        x: Screen.virtualX
        y: Screen.virtualY
        visibility: Window.FullScreen
        visible: true

        Background{

        }

//        Rectangle {
//            id : root
//            width: parent.width
//            height: parent.height*0.7

//            color:"black"
            PDC {
            }

            LeftDial {
                id : leftDial
                anchors.left : parent.left
                anchors.leftMargin: 0.1 * width
                value : canData.speed
            }

            RightDial {
                id : rightDial
                anchors.right: parent.right
                anchors.rightMargin: 0.1 * width
                value : canData.rpm
            }

            Top {
                id : topbar
                y : 7
                anchors.horizontalCenter: parent.horizontalCenter
                temperature: canData.temperature
                humidity : canData.humidity
            }

            ICPrnd {
                id: prnd
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Image {
                width: parent.width
                height: parent.height*0.5
//                anchors.fill: parent
                source: Qt.resolvedUrl("images/mask_overlay.png")
            }
//        }
    }
}
