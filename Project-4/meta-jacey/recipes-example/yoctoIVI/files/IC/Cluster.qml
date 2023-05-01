import QtQuick 2.5
import QtQuick.Window 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import data 0.0

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

        DataController {
            id:datacontroller
        }

        Background{

        }


            PDC {
            }

            LeftDial {
                id : leftDial
                anchors.left : parent.left
                anchors.leftMargin: 0.1 * width
                value : datacontroller.speed

            }

            RightDial {
                id : rightDial
                anchors.right: parent.right
                anchors.rightMargin: 0.1 * width
                value : datacontroller.rpm
            }

            Top {
                id : topbar
                y : 7
                anchors.horizontalCenter: parent.horizontalCenter
                temperature: datacontroller.temperature
                humidity : datacontroller.humidity

            }
            ICPrnd {
                id: prnd
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Image {
                width: parent.width
                height: 720
//                anchors.fill: parent
                source: Qt.resolvedUrl("images/mask_overlay.png")
            }
            Text{
                x:parent.width *0.5
                y:parent.height*0.5
                width:60
                height:60
                color:"white"
                text: datacontroller.distance


            }
    }
}
