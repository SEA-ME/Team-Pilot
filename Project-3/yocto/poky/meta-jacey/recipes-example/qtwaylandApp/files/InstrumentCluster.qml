import QtQuick 2.0
import data 0.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.3
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
        Rectangle {
            id: tempBox
            width: height * 2
            height: parent.height*0.5
            x: (parent.x + parent.width) / 1.7
            y: (parent.y + parent.height)/4
            color : "#171717"


            Text {
                id :tempTextBox
                width: parent.width/2
                height: parent.height
                text:"TEMP   "+datacontroller.temperature + "℃"
                color: "#FFFFFF"
            }
            Text {
                id :humTextBox
                width: parent.width/2
                height: parent.height
                y: (parent.y + parent.height)/16
                text:"HUM   "+datacontroller.humidity + "℃"
                color: "#FFFFFF"
            }
            Text {
                id :rpmTextBox
                width: parent.width/2
                height: parent.height
                y: (parent.y + parent.height)/8
                text:"RPM   "+datacontroller.rpm + "℃"
                color: "#FFFFFF"
            }
            Text {
                id :speedTextBox
                width: parent.width/2
                height: parent.height
                y: (parent.y + parent.height)/4
                text:"SPD   "+datacontroller.speed + "℃"
                color: "#FFFFFF"
            }
            Text {
                id :batteryTextBox
                width: parent.width/2
                height: parent.height
                y: (parent.y + parent.height)/2
                text:"BAT   "+datacontroller.battery + "℃"
                color: "#FFFFFF"
            }
        }

    }

}


