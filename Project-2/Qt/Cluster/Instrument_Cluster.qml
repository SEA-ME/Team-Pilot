import QtQuick 2.0
import vdata 0.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id:dashboard
    width:parent.width
    height:parent.height

    VsomeData {
        id: vsomeipdata
    }

    CircularGauge {
        id: circularGauge1
        width: height
        height: parent.height*0.5
        x: (parent.x + parent.width)/8
        anchors.verticalCenter: parent.verticalCenter
        value:vsomeipdata.qtspd
        minimumValue: 0
        maximumValue: 180

        style: CircularGaugeStyle{
            labelStepSize: 20
        }
        Behavior on value{
            NumberAnimation{
                duration: 1000
                easing: Easing.InOutSine
            }
        }

    }
    Text {
        id :speedtextbox
        width: parent.width/2
        height: parent.height
        x: (parent.x + parent.width) / 4.2
        y: (parent.y + parent.height)/1.5
        text:"km/h"
        color: "#FFFFFF"
    }
    Rectangle {
        id: tempBox
        width: parent.width/4
        height: parent.height/2
        x: (parent.x + parent.width)/2
        y: (parent.y + parent.height)/4
        color: "#171717"

        Text {
            id :humTextBox
            width: parent.width
            height: parent.height/4
            text:"HUM    " + vsomeipdata.qthum + "%"
            anchors.top: parent.top
            anchors.topMargin: 0
            color: "#FFFFFF"
        }
        Text {
            id :tempTextBox
            width: parent.width
            height: parent.height/4
            text:"TMP   " + vsomeipdata.qttmp + "℃"
            anchors.top: humTextBox.bottom
            anchors.topMargin: 0
            color: "#FFFFFF"
        }
        Text {
            id :rpmTextBox
            width: parent.width
            height: parent.height/4
            text:"RPM   " + vsomeipdata.qtrpm
            anchors.top: tempTextBox.bottom
            anchors.topMargin: 0
            color: "#FFFFFF"
        }
        Text {
            id :batteryTextBox
            width: parent.width
            height: parent.height/4
            text:"BAT   " + vsomeipdata.qtbat + "%"
            anchors.top: rpmTextBox.bottom
            anchors.topMargin: 0
            color: "#FFFFFF"
        }
    }
}


