import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    id: window1
    visible: true
    width: 640
    height: 480
    title: qsTr("Feel Free to Click Button!")

    signal prndSignal(int msg)

    PRND{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
