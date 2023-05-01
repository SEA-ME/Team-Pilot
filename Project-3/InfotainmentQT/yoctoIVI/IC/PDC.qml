import QtQuick 2.0

Item {
    id: root
    width: parent.width
    height: parent.height


    Image {
        id: car
        width: 0.1* parent.width
        height: 0.24* parent.height
        anchors.horizontalCenter: root.horizontalCenter
        y : parent.height/5.5
        source: Qt.resolvedUrl("images/car.png")
    }

    Image {
        id: sensor
        width: 0.05* parent.width
        height: 0.1* parent.height
        anchors.horizontalCenter: root.horizontalCenter
        y : parent.height/2.4
        source: (instrumentclusterLeft.msgIndex == 1) ? Qt.resolvedUrl("images/sensor.png") : Qt.resolvedUrl("images/nosensor.png")
    }


}
