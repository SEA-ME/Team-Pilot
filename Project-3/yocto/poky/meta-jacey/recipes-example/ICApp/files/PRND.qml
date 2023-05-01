import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3

WaylandOutput {
    signal prndSignal(int msg)

    id: prnd

//    property alias surfaceArea: headbackground
//    property alias text: t.text
    property alias screen: winHead.screen
    property int colorIndex: 4
    sizeFollowsWindow: true

    property bool windowed: false


    window: Window {
        id: winHead
        x: Screen.virtualX
        y: Screen.virtualY
        visibility: Window.FullScreen
        visible: true
/*
        WaylandMouseTracker {
            id: mouseTracker
            anchors.fill: parent
            windowSystemCursorEnabled: true

            Rectangle {
                anchors.fill: parent
                id: headbackground

                Text {
                    id: t
                    anchors.centerIn: parent
                    font.pointSize: 72
                }
            }

            WaylandCursorItem {
                inputEventsEnabled: true
                x: mouseTracker.mouseX
                y: mouseTracker.mouseY
                seat: comp.defaultSeat
                visible: mouseTracker.containsMouse
            }
        }
*/
        Background {

        }

        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 10
            Button {
                id: btnP
                text: qsTr("P")
                style: ButtonStyle{
                    label: Text{
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 20
                        text: control.text
                    }
                }
                onClicked: prndSignal(0)
            }
            Button {
                id: btnR
                text: qsTr("R")
                style: ButtonStyle{
                    label: Text{
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 20
                        text: control.text
                    }
                }
                onClicked: prndSignal(1)
            }
            Button {
                id: btnN
                text: qsTr("N")
                style: ButtonStyle{
                    label: Text{
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 20
                        text: control.text
                    }
                }
                onClicked: prndSignal(2)
            }
            Button {
                id: btnD
                text: qsTr("D")
                style: ButtonStyle{
                    label: Text{
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 20
                        text: control.text
                    }
                }
                onClicked: prndSignal(3)
            }
        }

    }
}
