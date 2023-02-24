import QtQuick 2.15
import QtQuick.Window 2.15
import "IC"

Window {
    visible: true
    visibility: Window.FullScreen
    title: qsTr("Hello World")

    Background {

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
        source: Qt.resolvedUrl("images/mask_overlay.png")
    }
}
