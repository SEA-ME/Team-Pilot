import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3
import QtMultimedia 5.15
import QtQuick.Layouts 1.2

Rectangle {
    id: topBar
    width: 1
    height: parent.height *0.1
    color: "#151515"
    anchors {
        top: parent.top
        left: parent.left
        right: parent.right
        bottomMargin: 0

    }

    RowLayout {
        anchors.fill : parent
        spacing: 0

        Rectangle {
            id : topBar1
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.08
            color: "#151515"
            Image {
                id: backImage
                source: "images/back.PNG"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: parent.width *0.1
                width: parent.height*0.5
                height : parent.height*0.5
            }
            MouseArea {
                id: mouseRegion
                anchors.fill: topBar1
                onClicked: Qt.quit();
            }


        }
        Rectangle {
            id : topBar2
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.08
            color: "#151515"

            Image {
                id: homeImage
                source: "images/home.PNG"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                width: parent.height*0.5
                height : parent.height*0.5
            }


        }
        Rectangle {
            id : topBar3
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.08
            color: "#151515"

            Image {
                id: menuImage
                source: "images/menu.PNG"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                width: parent.height*0.5
                height : parent.height*0.5
            }


        }
        Rectangle {
            id : topBar4
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.3
            color: "#151515"

            Label {
                id: timeText
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 0.05 * parent.width
                font.pixelSize: 0.5 * parent.height
                font.bold: true
                color : "white"

                text: Qt.formatTime(currentDate, "hh:mm")

                property var currentDate: new Date();

                Timer {
                    interval: 1000
                    repeat: true
                    running: true
                    onTriggered: {
                        timeText.currentDate = new Date();
                    }
                }
            }

        }
        Rectangle {
            id : topBar5
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.36
            color: "#151515"

            Label {
                id: dateText
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                font.pixelSize: 0.3 * parent.height
                font.bold: true
                color : "white"

                text: new Date().toLocaleDateString(Qt.locale("en"), 'ddd. MMM dd')

            }

        }
        Rectangle {
            id : test6
            Layout.alignment: Qt.AlignLeft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.22
            color: "#151515"

            Image {

                id: batteryImage
                source: "images/battery.PNG"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left : parent.left
                anchors.leftMargin: parent.width * 0.3
                width: parent.height*0.7
                height : parent.height*0.7

            }

            Label {
                id: batteryText
                anchors.verticalCenter: parent.verticalCenter
                anchors.left : parent.left
                anchors.leftMargin: parent.width * 0.12
                font.pixelSize: 0.4 * parent.height
                font.bold: true
                color : "white"

                text: "55 %"
            }

        }

    }

}
