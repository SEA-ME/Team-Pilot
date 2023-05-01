import QtQuick 2.0
import data 0.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3

WaylandOutput {
    id: intrumentclusterScreen
    property alias screen: winInstrument.screen
    sizeFollowsWindow: true

    property bool windowed: false
    property int msgIndex: 0



    window: Window {
        id: winInstrument
        x: Screen.virtualX
        y: Screen.virtualY
        visibility: Window.FullScreen
        visible: true

        DataController {
            id:datacontroller
        }
        Background {

        }

        CircularGauge {
            id: circularGaugeSpeed
            width: 350
            height: 350
            anchors.right: parent.right
            anchors.rightMargin: 60
            anchors.verticalCenter: parent.verticalCenter
            value:datacontroller.speed
            minimumValue: 0
            maximumValue: 10

            style: CircularGaugeStyle{
                labelStepSize: 1
            }
            Behavior on value{
                NumberAnimation{
                    duration: 1000
                    easing: Easing.InOutSine
                }
            }
            Text {
                id: speedText
                text: "km/h"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                color: "#FFFFFF"
            }
        }

        CircularGauge {
            id: circularGaugeRPM
            width: 350
            height: 350
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 60
            value:datacontroller.rpm
            minimumValue: 0
            maximumValue: 14

            style: CircularGaugeStyle{
                labelStepSize: 1
            }
            Behavior on value{
                NumberAnimation{
                    duration: 1000
                    easing: Easing.InOutSine
                }
            }
            Text {
                id: rpmText
                text: "1000 r/min"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                color: "#FFFFFF"
            }
        }

        Rectangle {
            id: canRect
            width: 60
            height: parent.height/3
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "#171717"

            Text {
                id :humTextBox
                width: parent.width
                height: parent.height/4
                text:"HUM    " + datacontroller.humidity+ "%"
                anchors.top: parent.top
                anchors.topMargin: 0
                color: "#FFFFFF"
            }
            Text {
                id :tempTextBox
                width: parent.width
                height: parent.height/4
                text:"TMP   " + datacontroller.temperature + "℃"
                anchors.top: humTextBox.bottom
                anchors.topMargin: 0
                color: "#FFFFFF"
            }
            Text {
                id :batteryTextBox
                width: parent.width
                height: parent.height/4
                text:"BAT   " + datacontroller.battery + "%"
                anchors.top: tempTextBox.bottom
                anchors.topMargin: 0
                color: "#FFFFFF"
            }
        }

        Row {
            id: prndRow
            anchors.top: canRect.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 20

            Text {
                id: parkText
                text: "P"
                font.weight: Font.Bold
                font.bold: false
                font.pointSize: 30
                color: (instrumentclusterLeft.msgIndex == 0) ? "blue" : "#123456"
            }
            Text {
                id: reverseText
                text: "R"
                font.weight: Font.Bold
                font.bold: false
                font.pointSize: 30
                color: (instrumentclusterLeft.msgIndex == 1) ? "red" : "#123456"
            }
            Text {
                id: neutralText
                text: "N"
                font.weight: Font.Bold
                font.bold: false
                font.pointSize: 30
                color: (instrumentclusterLeft.msgIndex == 2) ? "orange" : "#123456"
            }
            Text {
                id: driveText
                text: "D"
                font.weight: Font.Bold
                font.bold: false
                font.pointSize: 30
                color: (instrumentclusterLeft.msgIndex == 3) ? "green" : "#123456"
            }
        }

    }
}


