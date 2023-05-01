import QtQuick 2.0
import data 0.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id:dashboard
    width:parent.width
    height:parent.height

    DataController {
        id:datacontroller
    }

    CircularGauge {
        id: speedGauge
        width: height
        height: parent.height*0.5
        x: (parent.x + parent.width)/1.7
        anchors.verticalCenter: parent.verticalCenter

        value:datacontroller.speed
        minimumValue: 0
        maximumValue: 300

        style: CircularGaugeStyle{
            labelStepSize: 50


        }

        Behavior on value{
            NumberAnimation{
                duration: 200
                easing: Easing.InOutSine
            }
        }
    }
    Text {
        id :speedtextbox
        width: parent.width/2
        height: parent.height
        x: (parent.x + parent.width) / 1.4
        y: (parent.y + parent.height)/1.38
        text:"m/m"
        color: "#FFFFFF"
    }


    CircularGauge {
        id: rpmGauge
        width: height
        height: parent.height*0.5
        x: (parent.x + parent.width)/8
        anchors.verticalCenter: parent.verticalCenter

        value:datacontroller.rpm
        minimumValue: 0
        maximumValue: 80

        style: CircularGaugeStyle{
            labelStepSize: 10


        }

        Behavior on value{
            NumberAnimation{
                duration: 500
                easing:Easing.OutInCubic
            }
        }

    }
    Text {
        id :rpmtextbox
        width: parent.width/2
        height: parent.height
        x: (parent.x + parent.width) / 4.7
        y: (parent.y + parent.height)/1.38
        text:"RPM x 100"
        color: "#FFFFFF"
    }



//    Text {
//        id :speedtextbox
//        width: parent.width/2
//        height: parent.height
//        x: (parent.x + parent.width) / 4.2
//        y: (parent.y + parent.height)/1.5
//        text:"km/h"
//        color: "#FFFFFF"
//    }
    Rectangle {
        id: tempBox
        width: height * 1.5
        height: parent.height*0.2
        x: (parent.x + parent.width) / 2.3
        y: (parent.y + parent.height)/8
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
            y: (parent.y + parent.height)/6
            text:"HUM    "+datacontroller.humidity
            color: "#FFFFFF"
        }
        Text {
            id :batteryTextBox
            width: parent.width/2
            height: parent.height
            y: (parent.y + parent.height)/3
            text:"Battery   "+datacontroller.battery + "%"
            color: "#FFFFFF"
        }


    }


}


